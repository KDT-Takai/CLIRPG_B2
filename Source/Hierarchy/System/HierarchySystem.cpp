#include "HierarchySystem.hpp"
#include "Scene/Event/SceneEventComponent.hpp"


void System::HierarchySystem::Update(entt::registry& Reg)
{
	auto view = Reg.view<Component::HierarchyComponent, Component::HierarchyPush>();

	view.each([&](auto Entity, Component::HierarchyComponent& Hierarchy) 
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
		});



}
