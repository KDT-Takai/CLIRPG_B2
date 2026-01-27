#pragma once
#include <string>

namespace Charactors
{

	struct Status
	{
		int HP = 1;
		int MP = 1;
		int ATK = 1;
		int DEF = 1;
		int MAG = 1;
	};

	struct Level
	{
		int Level = 1;
		int Exp = 0;
	};
}

namespace Component
{

	struct CharactorStatusComp
	{
		std::string Name = "Default";
		Charactors::Status FixedStatus;
		Charactors::Status CurrentStasuts;
		Charactors::Level Level;

		CharactorStatusComp() = default;

		CharactorStatusComp(const std::string& aName, const Charactors::Status& aStatus)
			:Name(aName), FixedStatus(aStatus), CurrentStasuts(aStatus)
		{
		}
		

		CharactorStatusComp(const std::string& aName, const Charactors::Status& aStatus,
			const Charactors::Level& aLevel)
			:Name(aName), FixedStatus(aStatus), CurrentStasuts(aStatus),Level(aLevel)
		{
		}

	};

}