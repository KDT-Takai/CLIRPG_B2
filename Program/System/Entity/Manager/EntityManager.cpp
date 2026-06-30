#include "EntityManager.hpp"

entt::entity System::EntityManager::CreateEntity() {
    return mRegistry.create();
}

void System::EntityManager::Destroy(entt::entity entity) {
    if (entity != entt::null) {
        mRegistry.destroy(entity);
    }
}

entt::entity System::EntityManager::CreateLocalEntity() {
    auto entity = mRegistry.create();
    mRegistry.emplace<LocalObjectTag>(entity);
    return entity;
}

void System::EntityManager::Clear(entt::entity entity) {
    if (entity != entt::null) {
        mRegistry.remove<LocalObjectTag, GlobalObjectTag>(entity);
    }
}

void System::EntityManager::AllClear() {
    auto view = mRegistry.view<LocalObjectTag>();
    for (auto entity : view) {
        mRegistry.destroy(entity);
    }
}

entt::registry& System::EntityManager::GetRegistry() {
    return mRegistry;
}
