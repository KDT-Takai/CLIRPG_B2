#include "InGameScene.hpp"
#include "System/Entity/Manager/EntityManager.hpp"
#include "System/SystemManager/SystemManager.hpp"
#include "Hierarchy/System/HierarchySystem.hpp"
#include "Graphics/Renderer.hpp"
#include "System/KeyInput/KeyInput.h"
#include "Chara/Player/CreatePlayer.h"
#include "Chara/Enemy/CreateEnemy.h"
#include "Hierarchy/HierarchyComponent.hpp"
#include "SceneManager.hpp"
#include "TitleScene.hpp"

#include <thread>
#include <chrono>

namespace System {

	std::string InGameScene::GetName() const { return "InGameScene"; }

	void InGameScene::Initialize() {
		auto* renderer = Graphics::Renderer::GetInstance();

		renderer->ClearText();
		renderer->AddText("InGameScene Start");
		renderer->Render();
		renderer->ClearText();

		System::EntityManager::GetInstance()->Create();
		auto& reg = System::EntityManager::GetInstance()->GetRegistry();

		//// プレイヤー生成
		mPlayerParty.clear();
		auto hero = Charactors::PlayerFactory::CreatePlayer(reg, 0);
		mPlayerParty.push_back(hero);

		//// 階層管理用エンティティ作成
		mGameMngEntity = System::EntityManager::GetInstance()->CreateLocalEntity();
		reg.emplace<Component::HierarchyComponent>(mGameMngEntity, 1, 10);

		//// 初期設定
		mPrevFloor = 1;
		mEnemyParty.clear();
		mState = GameState::PlayerTurn;
		SpawnEnemy();

		mItems.push_back({ "Potion", ItemType::HealHP, 30 });
		mItems.push_back({ "Ether", ItemType::HealMP, 10 });

	}

	void InGameScene::Update()
	{
		auto* renderer = Graphics::Renderer::GetInstance();
		System::KeyInput::Update();
		switch (mState)
		{
		case GameState::PlayerTurn:
			PlayerTurn();
			break;
		case GameState::EnemyTurn:
			EnemyTurn();
			break;
		case GameState::BattleResult:
			renderer->AddText("Battle Clear!");
			renderer->AddText("[Enter] Next Floor");
			if (System::KeyInput::IsDown(VK_RETURN)) {
				renderer->ClearText();
				renderer->ClearConsole();
				auto& reg = System::EntityManager::GetInstance()->GetRegistry();
				auto& hierarchy = reg.get<Component::HierarchyComponent>(mGameMngEntity);

				hierarchy.Level++;        // フロア進行
				mPrevFloor = hierarchy.Level;

				SpawnEnemy();             // 敵再生成
				mState = GameState::PlayerTurn;
			}
		break;
		case GameState::GameOver:
			if (!mGameOverDrawn) {
				renderer->ClearText();
				renderer->AddText("Game Over");
				renderer->Render();
				mGameOverDrawn = true;
			}
			break;
		}

		//renderer->Render();
	}

	void InGameScene::SpawnEnemy() {
		auto& reg = System::EntityManager::GetInstance()->GetRegistry();

		// 古い敵を削除
		for (auto e : mEnemyParty) {
			if (reg.valid(e)) reg.destroy(e);
		}
		mEnemyParty.clear();

		// 敵の生成
		int floorIndex = mPrevFloor - 1;
		mEnemyParty = Charactors::EnemyFactory::CreateFloorEnemies(reg, floorIndex);

		Graphics::Renderer::GetInstance()->AddText("Enemies appeared!");

	}

	void InGameScene::PlayerTurn() {
		auto* renderer = Graphics::Renderer::GetInstance();
		auto& reg = System::EntityManager::GetInstance()->GetRegistry();

		// 先頭プレイヤー
		entt::entity activePlayer = entt::null;
		for (auto e : mPlayerParty) {
			if (reg.get<Component::CharactorStatusComp>(e).hp > 0) {
				activePlayer = e;
				break;
			}
		}
		// 味方全滅
		if (activePlayer == entt::null) {
			mState = GameState::GameOver;
			return;
		}

		// 先頭の敵
		entt::entity activeEnemy = entt::null;
		for (auto e : mEnemyParty) {
			if (reg.get<Component::CharactorStatusComp>(e).hp > 0) {
				activeEnemy = e;
				break;
			}
		}
		// 勝利
		if (activeEnemy == entt::null) {
			mState = GameState::BattleResult;
			return;
		}

		// 画面描画
		if (mNeedRedraw) {
			renderer->ClearText();
			renderer->AddText("Floor: " + std::to_string(mPrevFloor));

			renderer->AddText("--- Enemies ---");
			for (auto e : mEnemyParty) {
				auto& st = reg.get<Component::CharactorStatusComp>(e);
				renderer->AddText(
					st.Name + " (HP:" + std::to_string(st.hp) + ")"
				);
			}

			renderer->AddText("--- Players ---");
			for (auto p : mPlayerParty) {
				auto& st = reg.get<Component::CharactorStatusComp>(p);
				renderer->AddText(
					st.Name + " (HP:" + std::to_string(st.hp) +
					" MP:" + std::to_string(st.mp) + ")"
				);
			}

			renderer->AddText("");
			renderer->AddText("[1] Attack  [2] Magic(5MP)  [3] Item");
			renderer->Render();

			mNeedRedraw = false;
		}

		// 入力、行動処理
		bool isActionTaken = false;
		auto& pStatus = reg.get<Component::CharactorStatusComp>(activePlayer);
		auto& eStatus = reg.get<Component::CharactorStatusComp>(activeEnemy);

		if (System::KeyInput::IsDown('1')) { // 通常攻撃
			int damage = pStatus.FinalStasuts.ATK - eStatus.FinalStasuts.DEF / 2;
			if (damage < 1) { damage = 1; }

			eStatus.Damage(damage);
			renderer->AddText("Atk! Dealt " + std::to_string(damage) + " dmg.");
			isActionTaken = true;
		}
		else if (System::KeyInput::IsDown('2')) { // 魔法
			if (pStatus.mp >= 5) {
				pStatus.mp -= 5;
				int damage = pStatus.FinalStasuts.MAG;
				eStatus.Damage(damage);
				renderer->AddText("Magic! Dealt " + std::to_string(damage) + " dmg.");
				isActionTaken = true;
			}
			else {
				renderer->AddText("Not enough MP!");
			}
		}
		else if (System::KeyInput::IsDown('3')) {
			if (!mItems.empty()) {
				auto& item = mItems.front();

				if (item.type == ItemType::HealHP) {
					pStatus.hp += item.value;
					renderer->AddText(item.name + " used! +" + std::to_string(item.value) + " HP");
				}
				else if (item.type == ItemType::HealMP) {
					pStatus.mp += item.value;
					renderer->AddText(item.name + " used! +" + std::to_string(item.value) + " MP");
				}

				mItems.erase(mItems.begin());
				isActionTaken = true;
			}
			else {
				renderer->AddText("No items!");
			}
		}

		renderer->Render();

		// 行動完了後
		if (isActionTaken) {
			// 敵の全滅チェック
			bool allDead = true;
			for (auto e : mEnemyParty) {
				if (reg.get<Component::CharactorStatusComp>(e).hp > 0) {
					allDead = false;
					break;
				}
			}

			if (allDead) {
				mState = GameState::BattleResult; // 勝利
			}
			else {
				mNeedRedraw = true;
				mState = GameState::EnemyTurn; // 敵のターンへ
			}

			//	すぐに切り替わったらわかりにくいので止めますね
			std::this_thread::sleep_for(std::chrono::seconds(2));

		}


	}

	void InGameScene::EnemyTurn() {
		auto* renderer = Graphics::Renderer::GetInstance();
		auto& reg = System::EntityManager::GetInstance()->GetRegistry();

		if (!mEnemyActed) {
			renderer->ClearText();

			renderer->AddText("");
			renderer->AddText("Enemy Turn...");

			// 全ての敵
			for (auto enemyEntity : mEnemyParty) {
				auto& eStatus = reg.get<Component::CharactorStatusComp>(enemyEntity);
				if (eStatus.hp <= 0) continue;

				// ターゲット
				entt::entity target = entt::null;
				for (auto p : mPlayerParty) {
					if (reg.get<Component::CharactorStatusComp>(p).hp > 0) {
						target = p;
						break;
					}
				}

				if (target == entt::null) {
					mState = GameState::GameOver;
					return;
				}


				// 攻撃
				auto& pStatus = reg.get<Component::CharactorStatusComp>(target);
				int damage = eStatus.FinalStasuts.ATK - pStatus.FinalStasuts.DEF / 2;
				if (damage < 1) { damage = 1; }

				pStatus.Damage(damage);
				renderer->AddText(
					eStatus.Name + " attacks " +
					pStatus.Name + "! (" +
					std::to_string(damage) + " dmg)"
				);
			}

			renderer->AddText("(Press Enter)");
			renderer->AddText("");
			renderer->Render();

			mEnemyActed = true;
			return;
		}

		if (System::KeyInput::IsDown(VK_RETURN)) {
			mEnemyActed = false;

			// 生存チェック
			bool playerAlive = false;
			for (auto p : mPlayerParty) {
				if (reg.get<Component::CharactorStatusComp>(p).hp > 0)
					playerAlive = true;
			}

			if (!playerAlive) {
				mState = GameState::GameOver;
			}
			else {
				mState = GameState::PlayerTurn;
			}
		}
	}

	void InGameScene::Finalize() {
		System::EntityManager::GetInstance()->AllClear();
	}
}