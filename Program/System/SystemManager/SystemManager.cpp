#include "SystemManager.hpp"

void System::SystemManager::Update(entt::registry& Reg)
{
	for (auto& system : mSystems)
	{
		system->Update(Reg);
	}
}
