#include "CreatePlayer.h"

#include "../PlayerDataTable/PlayerDataTable.h"

namespace Charactors
{

    /// <summary>
    /// プレイヤーエンティティの作成
    /// </summary>
    /// <param name="Reg">登録管理</param>
    /// <param name="id">プレイヤー ID</param>
    /// <returns>生成されたエンティティ ID</returns>
    entt::entity PlayerFactory::CreatePlayer(entt::registry& Reg, int id)
    {
        // エンティティ ID 取得
        auto entity = System::EntityManager::GetInstance()->CreateLocalEntity();

        // ステータス定義を取得
        std::string name;
        Charactors::Status status;

        // データテーブルから読み取り
        auto data = PlayerDataTable::GetPlayerData(id);

        // 名前をコピー
        name = data->name;
        // ステータスをコピー
        status = data->status;

        // コンポーネントの追加
        Reg.emplace<Component::CharactorStatusComp>(entity, name, status);
        // タグの追加
        Reg.emplace<Component::PlayerTag>(entity);

        return entity;
    }

}
