#include "CreateEnemy.h"

#include "../EnemyDataTable/EnemyDataTable.h"

namespace Charactors
{

	/// <summary>
	/// プレイヤー生成メソッド
	/// </summary>
	/// <param name="Reg">レジストリ</param>
	/// <param name="id">生成ID</param>
	/// <returns>エンティティ</returns>
	inline entt::entity EnemyFactory::CreateEnemy(entt::registry& Reg, int id)
	{
		//	エンティティID取得
		auto entity = System::EntityManager::GetInstance()->CreateLocalEntity();

		//	ステータス取得
		std::string name;
		Charactors::Status status;

		// データベースから取得
		auto data = EnemyDataTable::GetEnemyData(id);

		//	名前設定
		name = data->name;
		//	ステータス設定
		status = data->status;

		//	コンポーネントアタッチ
		Reg.emplace<Component::CharactorStatusComp>(entity, name, status);
		//	タグの付与
		Reg.emplace<Component::EnemyTag>(entity);

		return entity;
	}

	// 階層に応じた敵の生成処理
	//	エンティティを持ったvectorを返す
	std::vector<entt::entity> EnemyFactory::CreateFloorEnemies(entt::registry& Reg, int floor)
	{
		//	フロアに応じた敵IDリスト取得
		auto enemyIDList = EnemyDataTable::GetFloorEnemyTable(floor);

		if (enemyIDList == nullptr)
		{
			return std::vector<entt::entity>();
		}

		std::vector<entt::entity> enemyEntityList;

		//	敵生成
		for (auto id : *enemyIDList)
		{
			auto enemyEntity = CreateEnemy(Reg, id);
			enemyEntityList.push_back(enemyEntity);
		}
		return enemyEntityList;

	}

}