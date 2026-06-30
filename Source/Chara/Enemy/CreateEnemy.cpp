#include "CreateEnemy.h"

#include "../EnemyDataTable/EnemyDataTable.h"

namespace Charactors
{

    /// <summary>
    /// 敵エンティティの作成
    /// </summary>
    /// <param name="Reg">登録管理</param>
    /// <param name="id">敵 ID</param>
    /// <returns>生成されたエンティティ ID</returns>
    inline entt::entity EnemyFactory::CreateEnemy(entt::registry& Reg, int id)
    {
        // エンティティ ID 取得
        auto entity = System::EntityManager::GetInstance()->CreateLocalEntity();

        // ステータス定義を取得
        std::string name;
        Charactors::Status status;

        // データテーブルから読み取り
        auto data = EnemyDataTable::GetEnemyData(id);

        // 名前をコピー
        name = data->name;
        // ステータスをコピー
        status = data->status;

        // コンポーネントの追加
        Reg.emplace<Component::CharactorStatusComp>(entity, name, status);
        // タグの追加
        Reg.emplace<Component::EnemyTag>(entity);

        return entity;
    }

    // 各階層に出現する敵エンティティのリストを作成
    // エンティティ ID のベクトルから生成
    std::vector<entt::entity> EnemyFactory::CreateFloorEnemies(entt::registry& Reg, int floor)
    {
        // 各階層に出現する敵 ID を取得
        auto enemyIDList = EnemyDataTable::GetFloorEnemyTable(floor);

        if (enemyIDList == nullptr)
        {
            return std::vector<entt::entity>();
        }

        std::vector<entt::entity> enemyEntityList;

        // 各敵を生成
        for (auto id : *enemyIDList)
        {
            auto enemyEntity = CreateEnemy(Reg, id);
            enemyEntityList.push_back(enemyEntity);
        }
        return enemyEntityList;

    }

}
