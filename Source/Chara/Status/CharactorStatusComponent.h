#pragma once
#include <string>
#include <algorithm>

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

}

namespace Component
{

	struct CharactorStatusComp
	{
		std::string Name = "Default";
		Charactors::Status BaseStatus;			//	基礎ステータス値
		Charactors::Status FinalStasuts;		//	最終ステータス値
		int hp = -1;							//	体力値
		int mp = -1;							//	魔力値

		CharactorStatusComp() = default;

		CharactorStatusComp(const std::string& aName, const Charactors::Status& aStatus)
			:Name(aName), BaseStatus(aStatus), FinalStasuts(aStatus),
			hp(FinalStasuts.HP), mp(FinalStasuts.MP)
		{
		}


		const int GetMaxHP()
		{
			return FinalStasuts.HP;
		}

		const int GetMaxMP()
		{
			return FinalStasuts.MP;
		}

		//	体力率取得
		const float GetHPRate()
		{
			return static_cast<float>(hp) / static_cast<float>(FinalStasuts.HP);
		}

		//	回復処理
		const void HpHeal(const int value)
		{
			//	マイナスの回復は無効
			if(value <= 0)
			{
				return;
			}

			hp = std::clamp(hp + value, 0, FinalStasuts.HP);
		}

		//	ダメージ処理
		const void Damage(const int value)
		{
			//	マイナスのダメージは無効
			if (value <= 0)
			{
				return;
			}

			hp = std::clamp(hp - value, 0, FinalStasuts.HP);
		}

		//	MP回復処理
		const void MpHeal(const int value)
		{
			//	マイナスの回復は無効
			if (value <= 0)
			{
				return;
			}

			mp = std::clamp(mp + value, 0, FinalStasuts.MP);
		}


	};

}