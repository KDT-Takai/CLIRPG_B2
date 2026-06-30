#pragma once

#include "System/Singleton/Singleton.hpp"
#include "entt/entt.hpp"
#include "../ObjectTag/ObjectTag.hpp"

namespace System {

class EntityManager : public Singleton<EntityManager> {
    GENERATE_SINGLETON_BODY(EntityManager);

    friend struct std::default_delete<EntityManager>;

public:
    [[nodiscard]] entt::entity CreateEntity();
    void Destroy(entt::entity entity);

    template<typename T, typename... Args>
    [[nodiscard]] T& AddComponent(entt::entity entity, Args&&... args) {
        return mRegistry.emplace<T>(entity, std::forward<Args>(args)...);
    }

    void RemoveComponent(entt::entity entity);

    template<typename T>
    [[nodiscard]] const T& GetComponent(entt::entity entity) const {
        return mRegistry.get<T>(entity);
    }

    template<typename T>
    [[nodiscard]] T& GetMutableComponent(entt::entity entity) {
        return mRegistry.get<T>(entity);
    }

    template<typename T>
    auto View() {
        return mRegistry.view<T>();
    }

    template<typename... Ts>
    auto View() {
        return mRegistry.view<Ts...>();
    }

    void Clear(entt::entity entity);
    [[nodiscard]] entt::registry& GetRegistry();

    [[nodiscard]] entt::entity CreateLocalEntity();
    void AllClear();

private:
    entt::registry mRegistry;
};

} // namespace System
