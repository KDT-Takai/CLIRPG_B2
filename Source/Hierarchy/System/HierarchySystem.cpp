#include "HierarchySystem.hpp"
#include "Scene/Event/SceneEventComponent.hpp"

/// <summary>
/// ó‘ÔXV
/// </summary>
void System::HierarchySystem::UpdateEntity(entt::registry& Reg,entt::entity Entity, Component::HierarchyComponent& Hierarchy, Component::HierarchyPush&)
{
	//	ŠK‘w‚ği‚ß‚é
	Hierarchy.Level++;
	//	ŠK‘w‚ği‚ß‚é’Ê’m‚ğÁ‚·
	Reg.erase<Component::HierarchyPush>(Entity);

	//	10ŠK‘w‚ğƒNƒŠƒA‚µ‚½‚ç
	if (Hierarchy.Level > Hierarchy.LevelMax)
	{
		//	ƒNƒŠƒA’Ê’m
		Reg.emplace<Component::GameClear>(Entity);
		//	ŠK‘wŠÇ—‚¢‚ç‚È‚¢‚©‚çíœ
		Reg.erase<Component::HierarchyComponent>(Entity);
	}


}
