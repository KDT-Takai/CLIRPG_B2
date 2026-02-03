#pragma once
#include "entt/entt.hpp"
#include "System/Entity/Manager/EntityManager.hpp"

#include "../Status/CharactorStatusComponent.h"
#include "../Tag/CharactorTags.h"



namespace Charactors
{

	class PlayerFactory
	{
	public:

		//	ê∂ê¨
		static entt::entity CreatePlayer(entt::registry& Reg, int id);

	};


};