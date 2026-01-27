#pragma once
#pragma once
#include "entt/entt.hpp"
#include "System/Entity/Manager/EntityManager.hpp"

#include "../Status/CharactorStatusComponent.h"
#include "../Tag/CharactorTags.h"



namespace Charactors
{

	class EnemyFactory
	{
	public:

		//	ê∂ê¨
		static entt::entity CreateEnemy(entt::registry& Reg, int id);

	};


};