#pragma once
#include "System/IScene/IScene.hpp"
#include "entt/entt.hpp"
#include "Item/Item.h"

//　インゲーム画面用のシーンクラス
//　ISceneを継承しSceneManagerから管理・遷移
namespace System {
	// ゲームの状態管理用
	enum class GameState {
		PlayerTurn,		// プレイヤーターン
		EnemyTurn,		// 敵ターン
		BattleResult,	// バトル結果
		GameClear,		// ゲームクリア
		GameOver,		// ゲームオーバー
	};

	//	入力の選択状態管理用
	enum class SelectState
	{
		ActionSelect,		//	行動選択
		ItemSelect,			//	アイテム選択
	};

	//　インゲームシーンクラス
	class InGameScene final : public IScene {
	public:
		// シーン名の取得
		std::string GetName() const override;

		//	インゲームシーンの初期化・更新・終了処理
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
		//	アイテム
		std::vector<Item> mItems;
		
		// 階層管理用エンティティ
		entt::entity mGameMngEntity = entt::null;
		// ゲーム状態
		GameState mState = GameState::PlayerTurn;
		// 選択状態
		SelectState mSelect = SelectState::ActionSelect;

		// 前の階層
		int mPrevFloor = 0;	
		// 画面再描画フラグ
		bool mNeedRedraw = true;
		// 敵行動済みフラグ
		bool mEnemyActed = false;
		// ゲームオーバー画面描画済みフラグ
		bool mGameOverDrawn = false;
	};
}