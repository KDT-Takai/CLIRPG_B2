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


#define DEBUG_SLEEP


namespace System {

	// インゲームシーンの名前の取得
	std::string InGameScene::GetName() const { return "InGameScene"; }
	//	インゲームシーンの初期化の更新
	void InGameScene::Initialize() {
		//　初期化処理
		auto* renderer = Graphics::Renderer::GetInstance();

		//　画面クリア
		renderer->ClearText();
		//　画面表示
		renderer->AddText("InGameScene Start");
		renderer->Render();
		//　画面クリア
		renderer->ClearText();
		//　エンティティマネージャーの初期化
		System::EntityManager::GetInstance()->Create();
		//　階層システムの登録
		auto& reg = System::EntityManager::GetInstance()->GetRegistry();

		// プレイヤー生成
		mPlayerParty.clear();
		auto hero = Charactors::PlayerFactory::CreatePlayer(reg, 0);
		mPlayerParty.push_back(hero);

		// 階層管理用エンティティ作成
		mGameMngEntity = System::EntityManager::GetInstance()->CreateLocalEntity();
		reg.emplace<Component::HierarchyComponent>(mGameMngEntity, 1, 10);

		// 初期設定
		mPrevFloor = 1;
		mEnemyParty.clear();
		mState = GameState::PlayerTurn;
		SpawnEnemy();

		//	アイテム初期化
		mItems.push_back({ "Potion", ItemType::HealHP, 30 });
		mItems.push_back({ "Ether", ItemType::HealMP, 10 });

	}

	//	インゲームシーンの更新
	void InGameScene::Update()
	{
		// 更新処理
		auto* renderer = Graphics::Renderer::GetInstance();
		// キー入力更新
		System::KeyInput::Update();

		// 状態分岐
		switch (mState)
		{
		case GameState::PlayerTurn:		// プレイヤーターン
			//　プレイヤーターン処理
			PlayerTurn();
			break;
		case GameState::EnemyTurn:		// 敵ターン
			//　敵ターン処理
			EnemyTurn();
			break;
		case GameState::BattleResult:	// 戦闘結果
			//renderer->AddText("Battle Clear!");
			//renderer->AddText("[Enter] Next Floor");
			// キー入力の確認
			if (System::KeyInput::IsDown(VK_RETURN)) {
				//　次のフロアへ
				renderer->ClearText();
				renderer->ClearConsole();
				// フロアレベル更新
				auto& reg = System::EntityManager::GetInstance()->GetRegistry();
				auto& hierarchy = reg.get<Component::HierarchyComponent>(mGameMngEntity);

				hierarchy.Level++;        // フロア進行
				mPrevFloor = hierarchy.Level;

				SpawnEnemy();             // 敵再生成
				mState = GameState::PlayerTurn;
			}
		break;
		case GameState::GameOver:		// ゲームオーバー
			// ゲームオーバー表示
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

	//	敵の生成
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
		Graphics::Renderer::GetInstance()->Render();
		Graphics::Renderer::GetInstance()->ClearText();
	}

	//	プレイヤーターン
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
			//　画面クリア
			renderer->ClearText();
			//　ステータス表示
			renderer->AddText("Floor: " + std::to_string(mPrevFloor));

			//　敵表示
			renderer->AddText("--- Enemies ---");
			for (auto e : mEnemyParty) {
				auto& st = reg.get<Component::CharactorStatusComp>(e);
				renderer->AddText(
					st.Name + " (HP:" + std::to_string(st.hp) + ")"
				);
			}

			//　味方表示
			renderer->AddText("--- Players ---");
			for (auto p : mPlayerParty) {
				auto& st = reg.get<Component::CharactorStatusComp>(p);
				renderer->AddText(
					st.Name + " (HP:" + std::to_string(st.hp) +
					" MP:" + std::to_string(st.mp) + ")"
				);
			}

			//　行動選択肢表示
			renderer->AddText("");
			renderer->AddText("[1] Attack  [2] Magic(5MP)  [3] Item");
			renderer->Render();
			renderer->ClearText();

			mNeedRedraw = false;
		}

		// 入力、行動処理
		bool isActionTaken = false;
		auto& pStatus = reg.get<Component::CharactorStatusComp>(activePlayer);
		auto& eStatus = reg.get<Component::CharactorStatusComp>(activeEnemy);

		//	選択段階分岐
		if(mSelect == System::SelectState::ActionSelect){

			//	通常攻撃
			if (System::KeyInput::IsDown('1')) { // 通常攻撃
				int damage = pStatus.FinalStasuts.ATK - eStatus.FinalStasuts.DEF / 2;
				if (damage < 1) { damage = 1; }

				eStatus.Damage(damage);
				renderer->AddText("Atk! Dealt " + std::to_string(damage) + " dmg.");
				isActionTaken = true;
			}
			//	魔法の使用
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
			//	アイテムの使用
			else if (System::KeyInput::IsDown('3')) {

				//	アイテム残量確認
				if (!mItems.empty()) {

					//	アイテムの数だけ選択肢を表示
					for (int i = 0;i<mItems.size();i++)
					{
						auto name = mItems[i].name;
						auto type = mItems[i].type;
						auto val = mItems[i].value;

						//	アイテムの案内テキスト表示
						std::string text = { "[" + std::to_string(i + 1) + "]" + name };
						renderer->AddText(text);
						
					}

				//	renderer->AddText()
					mSelect = SelectState::ItemSelect;
				}
				else {
					renderer->AddText("No items!");
				}
			}

		
		}
		//	アイテム選択
		else if (mSelect == System::SelectState::ItemSelect) {

			for (int i = 0; i < mItems.size(); i++)
			{
				//	対象のキーが入力されているか
				//	１のキーが49番なので、実数値を足して設定
				if (System::KeyInput::IsDown(49 + i))
				{
					
					//	アイテムの使用
					if (mItems[i].type == ItemType::HealHP) {
//						pStatus.hp += mItems[i].value;
						pStatus.HpHeal(mItems[i].value);
						renderer->AddText(mItems[i].name + " used! +" + std::to_string(mItems[i].value) + " HP");
					}
					else if (mItems[i].type == ItemType::HealMP) {
//						pStatus.mp += mItems[i].value;
						pStatus.MpHeal(mItems[i].value);
						renderer->AddText(mItems[i].name + " used! +" + std::to_string(mItems[i].value) + " MP");
					}

					//	使用したアイテムを削除
					mItems.erase(mItems.begin() + i);

					//	フラグ管理
					mSelect = SelectState::ActionSelect;
					isActionTaken = true;

					break;
				}

			}

		}
		//	画面更新
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

			//　勝利と敵のターンの分岐
			if (allDead) {
				mState = GameState::BattleResult; // 勝利
				renderer->ClearConsole();		//	画面クリア
				renderer->ClearText();			//	テキストクリア
				renderer->AddText("Battle Clear!");	//	勝利メッセージ
				renderer->AddText("[Enter] Next Floor");	//	次のフロア案内
				renderer->Render();				//	画面描画
				mNeedRedraw = true;				//	次のフロアへ行くまで描画維持
			}
			// 敵生存時
			else {
				mNeedRedraw = true;			//	次のターン描画フラグ
				mState = GameState::EnemyTurn; // 敵のターンへ
			}
#ifdef DEBUG_SLEEP
			//	すぐに切り替わったらわかりにくいので止めますね
			std::this_thread::sleep_for(std::chrono::seconds(1));
#endif // DEBUG_SLEEP

		}


	}

	//	敵ターン
	void InGameScene::EnemyTurn() {
		//　敵のターンの処理
		auto* renderer = Graphics::Renderer::GetInstance();
		auto& reg = System::EntityManager::GetInstance()->GetRegistry();

		//	敵の行動処理
		if (!mEnemyActed) {
			//　画面クリア
			renderer->ClearText();

			//　追加テキスト
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

				// 味方全滅
				if (target == entt::null) {
					mState = GameState::GameOver;
					return;
				}


				// 攻撃
				auto& pStatus = reg.get<Component::CharactorStatusComp>(target);
				int damage = eStatus.FinalStasuts.ATK - pStatus.FinalStasuts.DEF / 2;
				if (damage < 1) { damage = 1; }

				// ダメージ適用
				pStatus.Damage(damage);
				renderer->AddText(
					eStatus.Name + " attacks " +
					pStatus.Name + "! (" +
					std::to_string(damage) + " dmg)"
				);
			}

			//　行動終了案内
			renderer->AddText("(Press Enter)");
			renderer->AddText("");
			renderer->Render();

			//　行動済みフラグON
			mEnemyActed = true;
			return;
		}
		//　行動終了後、Enterキー待ち
		if (System::KeyInput::IsDown(VK_RETURN)) {
			mEnemyActed = false;

			// 生存チェック
			bool playerAlive = false;
			for (auto p : mPlayerParty) {
				if (reg.get<Component::CharactorStatusComp>(p).hp > 0)
					playerAlive = true;
			}

			//　状態遷移
			if (!playerAlive) {
				mState = GameState::GameOver;
			}
			// 味方生存時
			else {
				mState = GameState::PlayerTurn;
			}
		}
	}

	//	インゲームシーンの終了処理
	void InGameScene::Finalize() {
		System::EntityManager::GetInstance()->AllClear();
	}
}