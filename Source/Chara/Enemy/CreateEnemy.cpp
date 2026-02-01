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

}