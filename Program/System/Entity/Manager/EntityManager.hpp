#pragma once

#include "System/Singleton/Singleton.hpp"
#include "entt/entt.hpp"
#include "../System/Entity/ObjectTag/ObjectTag.hpp"

namespace System {

/// <summary>
/// Entity Component System (ECS) Manager.
/// Provides entity lifecycle management and component operations.
/// </summary>
class EntityManager : public Singleton<EntityManager> {
    GENERATE_SINGLETON_BODY(EntityManager);

public:

    /// <summary>
    /// Create a new local entity (for current scene).
    /// </summary>
    /// <returns>Newly created entity ID, or entt::null on failure.</returns>
    [[nodiscard]] entt::entity CreateEntity();

    /// <summary>
    /// Destroy an entity.
    /// </summary>
    /// <param name="entity">Entity to destroy.</param>
    void Destroy(entt::entity entity);

    /// <summary>
    /// Add a component to an entity.
    /// </summary>
    /// <typeparam name="T">Component type.</typeparam>
    /// <param name="entity">Target entity.</param>
    /// <param name... Args>Constructor arguments for the component.</param>
    /// <returns>Reference to the newly created component.</returns>
    template<typename T, typename... Args>
    [[nodiscard]] T& AddComponent(entt::entity entity, Args&&... args) {
        return mRegistry.emplace<T>(entity, std::forward<Args>(args)...);
    }

    /// <summary>
    /// Remove a component from an entity.
    /// </summary>
    /// <typeparam name="T">Component type to remove.</typeparam>
    /// <param name="entity">Target entity.</param>
    void RemoveComponent(entt::entity entity);

    /// <summary>
    /// Get a component reference by entity.
    /// Throws if component doesn't exist.
    /// </summary>
    /// <typeparam name="T">Component type.</typeparam>
    /// <param name="entity">Target entity.</param>
    /// <returns>Reference to the component.</returns>
    template<typename T>
    [[nodiscard]] const T& GetComponent(entt::entity entity) const {
        return mRegistry.get<T>(entity);
    }

    /// <summary>
    /// Get a mutable component reference by entity.
    /// Throws if component doesn't exist.
    /// </summary>
    /// <typeparam name="T">Component type.</typeparam>
    /// <param name="entity">Target entity.</param>
    /// <returns>Mutable reference to the component.</returns>
    template<typename T>
    [[nodiscard]] T& GetMutableComponent(entt::entity entity) {
        return mRegistry.get<T>(entity);
    }

    /// <summary>
    /// Query entities with specific components.
    /// </summary>
    /// <typeparam name="T">Required component type.</typeparam>
    /// <returns>Iterator range over matching entities.</returns>
    template<typename T>
    auto View() {
        return mRegistry.view<T>();
    }

    /// <summary>
    /// Query entities with multiple components.
    /// </summary>
    /// <tparam name="Ts">Required component types.</tparam>
    /// <returns>Iterator range over matching entities.</returns>
    template<typename... Ts>
    auto View() {
        return mRegistry.view<Ts...>();
    }

    /// <summary>
    /// Clear all components from an entity.
    /// </summary>
    /// <param name="entity">Target entity.</param>
    void Clear(entt::entity entity);

    /// <summary>
    /// Get the underlying registry reference.
    /// </summary>
    /// <returns>Registry reference.</returns>
    [[nodiscard]] entt::registry& GetRegistry();
    
    /// <summary>
    /// Create a new local entity with LocalObjectTag.
    /// </summary>
    /// <returns>Newly created entity ID.</returns>
    [[nodiscard]] entt::entity CreateLocalEntity() {
        return mRegistry.create();
    }

    /// <summary>
    /// Clear all entities with LocalObjectTag.
    /// </summary>
    void AllClear() {
        auto view = mRegistry | entt::is_a<entt::tag_t<LocalObjectTag>>;
        for (auto entity : view) {
            mRegistry.destroy(entity);
        }
    }

private:

    /// <summary>
    /// EnTT registry for managing game entities.
    /// </summary>
    entt::registry mRegistry;
};

} // namespace System
