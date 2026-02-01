#include "EnemyDataTable.h"

//	静的メンバ変数の定義
std::vector<Charactors::EnemyData> Charactors::EnemyDataTable::enemy =
{
	//	必要データを追加
	{0, "Slime",Charactors::Status(30, 10, 5, 2, 1) },
	{1, "Goblin",Charactors::Status(50, 20, 10, 5, 3) },
	{2, "Orc",Charactors::Status(80, 15, 15, 10, 2) },
};