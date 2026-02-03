#pragma once
#include "System/SystemManager/Base/ISystem.hpp"
#include "../HierarchyComponent.hpp"

namespace System
{
	class HierarchySystem : public BaseSystem<Component::HierarchyComponent>
	{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="Reg"></param>
		void Update(entt::registry& Reg)override;
	private:

	};
}