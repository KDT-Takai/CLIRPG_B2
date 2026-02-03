#include "CreatePlayer.h"

#include "../Playerdatatable/Playerdatatable.h"

namespace Charactors
{

	/// <summary>
	/// プレイヤー生成メソッド
	/// </summary>
	/// <param name="Reg">レジストリ</param>
	/// <param name="id">生成ID</param>
	/// <returns>エンティティ</returns>
	entt::entity PlayerFactory::CreatePlayer(entt::registry& Reg,int id)
	{
		//	エンティティID取得
		auto entity = System::EntityManager::GetInstance()->CreateLocalEntity();
		
		//	ステータス取得
		std::string name;
		Charactors::Status status;

		// データベースから取得
		auto data = PlayerDataTable::GetPlayerData(id);

		//	名前設定
		name = data->name;
		//	ステータス設定
		status = data->status;

		//	コンポーネントアタッチ
		Reg.emplace<Component::CharactorStatusComp>(entity, name, status);
		//	タグの付与
		Reg.emplace<Component::PlayerTag>(entity);

		return entity;
	}

}