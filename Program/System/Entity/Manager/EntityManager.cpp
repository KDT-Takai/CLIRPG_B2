#include "EntityManager.hpp"
#include "../System/Entity/ObjectTag/ObjectTag.hpp"

/// <summary>
/// Create a new entity.
/// </summary>
/// <returns>Newly created entity ID, or entt::null on failure.</returns>
entt::entity System::EntityManager::CreateEntity() {
    return mRegistry.create();
}

/// <summary>
/// Destroy an entity.
/// </summary>
/// <param name="entity">Entity to destroy.</param>
void System::EntityManager::Destroy(entt::entity entity) {
    if (entity != entt::null) {
        mRegistry.destroy(entity);
    }
}

/// <summary>
/// Create a new local entity with LocalObjectTag.
/// </summary>
/// <returns>Newly created entity ID.</returns>
entt::entity System::EntityManager::CreateLocalEntity() {
    auto entity = mRegistry.create();
    mRegistry.emplace<LocalObjectTag>(entity);
    return entity;
}

/// <summary>
/// Create a new global entity with GlobalObjectTag.
/// </summary>
/// <returns>Newly created entity ID.</returns>
entt::entity System::EntityManager::CreateGlobalEntity() {
    auto entity = mRegistry.create();
    mRegistry.emplace<GlobalObjectTag>(entity);
    return entity;
}

/// <summary>
/// Clear all components from an entity.
/// </summary>
/// <param name="entity">Target entity.</param>
void System::EntityManager::Clear(entt::entity entity) {
    if (entity != entt::null) {
        mRegistry.remove<LocalObjectTag, GlobalObjectTag>(entity);
    }
}

/// <summary>
/// Clear all entities with LocalObjectTag.
/// </summary>
void System::EntityManager::AllClear() {
    auto view = mRegistry | entt::is_a<entt::tag_t<LocalObjectTag>>;
    for (auto entity : view) {
        mRegistry.destroy(entity);
    }
}

/// <summary>
/// Get the underlying registry reference.
/// </summary>
/// <returns>Registry reference.</returns>
entt::registry& System::EntityManager::GetRegistry() {
    return mRegistry;
}
