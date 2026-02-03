#pragma once
#include "System/IScene/IScene.hpp"
#include "entt/entt.hpp"
#include "Item/Item.h"

//　インゲーム画面用のシーンクラス
//　ISceneを継承しSceneManagerから管理・遷移
namespace System {
	// ゲームの状態管理用
	enum class GameState {
		PlayerTurn,
		EnemyTurn,
		BattleResult,
		GameClear,
		GameOver
	};

	class InGameScene final : public IScene {
	public:
		std::string GetName() const override;

		void Initialize() override;
		void Update() override;
		void Finalize() override;
	private:
		// 敵のスポーン
		void SpawnEnemy();
		// プレイヤーターン
		void PlayerTurn();
		// 敵ターン
		void EnemyTurn();
	private:
		// プレイヤーパーティ
		std::vector<entt::entity> mPlayerParty;
		// 敵パーティ
		std::vector<entt::entity> mEnemyParty;

		std::vector<Item> mItems;
		
		entt::entity mGameMngEntity = entt::null;
		GameState mState = GameState::PlayerTurn;

		int mPrevFloor = 0;
		bool mNeedRedraw = true;
		bool mEnemyActed = false;
		bool mGameOverDrawn = false;
	};
}