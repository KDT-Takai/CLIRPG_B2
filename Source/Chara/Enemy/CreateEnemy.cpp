#include "CreateEnemy.h"

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
		auto entity = System::EntityManager::GetInstance()->CreateGlobalEntity();

		//	ステータス取得
		std::string name;
		Charactors::Status status;
		Charactors::Level level;

		// データベースから取得

		//	TODO: データベース実装後に修正

		//	名前設定
		//	ステータス設定
		//	レベル設定


		//	コンポーネントアタッチ
		Reg.emplace<Component::CharactorStatusComp>(entity, name, status, level);
		//	タグの付与
		Reg.emplace<Component::EnemyTag>(entity);

		return entity;
	}

}