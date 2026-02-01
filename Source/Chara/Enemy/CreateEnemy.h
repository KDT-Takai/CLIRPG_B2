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

		//	¶¬
		static entt::entity CreateEnemy(entt::registry& Reg, int id);

		//	ƒtƒƒA‚É‰‚¶‚½“G¶¬
		static std::vector<entt::entity> CreateFloorEnemies(entt::registry& Reg, int floor);

	};


};