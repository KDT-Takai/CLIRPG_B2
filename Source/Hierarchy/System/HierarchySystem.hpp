#pragma once
#include "System/SystemManager/Base/ISystem.hpp"
#include "../HierarchyComponent.hpp"

namespace System
{
	class HierarchySystem : public BaseSystem<Component::HierarchyComponent, Component::HierarchyPush>
	{
	public:
		/// <summary>
		/// ó‘ÔXV
		/// </summary>
		void UpdateEntity(entt::registry& Reg,entt::entity Entity, Component::HierarchyComponent& Hierarchy, Component::HierarchyPush&)override;
	private:

	};
}