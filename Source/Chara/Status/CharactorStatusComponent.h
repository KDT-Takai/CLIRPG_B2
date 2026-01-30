#pragma once
#include <string>
#include <windows.h>

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
		Charactors::Status BaseStatus;			//	基礎ステータス値
		Charactors::Status FinalStasuts;		//	最終ステータス値
		Charactors::Level Level;				//	レベル
		int hp = -1;							//	体力値

		CharactorStatusComp() = default;

		CharactorStatusComp(const std::string& aName, const Charactors::Status& aStatus)
			:Name(aName), BaseStatus(aStatus), FinalStasuts(aStatus),hp(FinalStasuts.HP)
		{
		}
		

		CharactorStatusComp(const std::string& aName, const Charactors::Status& aStatus,
			const Charactors::Level& aLevel)
			:Name(aName), BaseStatus(aStatus), FinalStasuts(aStatus),Level(aLevel), hp(FinalStasuts.HP)
		{
		}

		const int GetMaxHP()
		{
			return FinalStasuts.HP;
		}

		const int GetHP()
		{
			return hp;
		}

		const void Heal(const int value)
		{
			hp = std::max(hp+value,)
		}
	};

}