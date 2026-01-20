#include "EntityManager.hpp"
#include"System/Entity/ObjectTag/ObjectTag.hpp"

/// <summary>
/// エンティティの生成
/// </summary>
/// <returns></returns>
entt::entity System::EntityManager::CreateEntity()
{
	return mRegistry.create();
}

/// <summary>
/// ローカルオブジェクトの作成
/// </summary>
/// <returns></returns>
entt::entity System::EntityManager::CreateLocalEntity()
{
	auto entity = CreateEntity();
	mRegistry.emplace<LocalObjectTag>(entity);
	return entity;
}

/// <summary>
/// Globalオブジェクトの生成
/// </summary>
/// <returns></returns>
entt::entity System::EntityManager::CreateGlobalEntity()
{
	auto entity = CreateEntity();
	mRegistry.emplace<GlobalObjectTag>(entity);
	return entity;
}

/// <summary>
/// 全ての削除
/// </summary>
void System::EntityManager::AllClear()
{
	mRegistry.clear();
}

/// <summary>
/// Localタグを持つオブジェクトの削除
/// </summary>
void System::EntityManager::ClearLocalEntitys()
{
	auto view = mRegistry.view<LocalObjectTag>();
	mRegistry.destroy(view.begin(), view.end());
}

/// <summary>
/// Globalタグを持つオブジェクトの削除
/// </summary>
void System::EntityManager::ClearGlobalEntitys()
{
	auto view = mRegistry.view<GlobalObjectTag>();
	mRegistry.destroy(view.begin(), view.end());
}

/// <summary>
/// registryの参照取得
/// </summary>
/// <returns></returns>
entt::registry& System::EntityManager::GetRegistry()
{
	return mRegistry;
}
