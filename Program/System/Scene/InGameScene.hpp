#pragma once
#include"System/IScene/IScene.hpp"
#include"entt/entt.hpp"
#include"Item/Item.h"

/// <summary>
/// In-game battle scene.
/// </summary>
namespace System {
	/// <summary>
	/// Battle state enumeration.
	/// </summary>
	enum class GameState {
		PlayerTurn,
		EnemyTurn,
		BattleResult,
		GameClear,
		GameOver
	};

	/// <summary>
	/// Selection state enumeration.
	/// </summary>
	enum class SelectState
	{
		ActionSelect,		/// Action selection
		ItemSelect,			/// Item selection
	};

	class InGameScene final : public IScene {
	public:
		std::string GetName() const override;

		void Initialize() override;
		void Update() override;
		void Finalize() override;
	private:
		/// <summary>
		/// Spawn enemy entities.
		/// </summary>
		void SpawnEnemy();
		/// <summary>
		/// Execute player turn logic.
		/// </summary>
		void PlayerTurn();
		/// <summary>
		/// Execute enemy turn logic.
		/// </summary>
		void EnemyTurn();
	private:
		/// <summary>
		/// Entity registry for managing game entities.
		/// Using entt::registry provides proper lifecycle management.
		/// </summary>
		entt::registry mRegistry;

		/// <summary>
		/// Player party entity IDs (for reference tracking).
		/// </summary>
		std::vector<entt::entity> mPlayerParty;
		/// <summary>
		/// Enemy party entity IDs.
		/// </summary>
		std::vector<entt::entity> mEnemyParty;
		/// <summary>
		/// Available items in the battle.
		/// </summary>
		std::vector<Item> mItems;

		entt::entity mGameMngEntity = entt::null;
		GameState mState = GameState::PlayerTurn;
		SelectState mSelect = SelectState::ActionSelect;

		int mPrevFloor = 0;
		bool mNeedRedraw = true;
		bool mEnemyActed = false;
		bool mGameOverDrawn = false;
	};
}
