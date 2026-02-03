#include "EnemyDataTable.h"

//	静的メンバ変数の定義
std::vector<Charactors::EnemyData> Charactors::EnemyDataTable::enemy =
{
	//	必要データを追加
	{0, "Slime"	,Charactors::Status(30, 10, 5, 2, 1) },
	{1, "Goblin",Charactors::Status(50, 20, 10, 5, 3) },
	{2, "Orc"	,Charactors::Status(80, 15, 15, 10, 2) },
	{3, "Dragon", Charactors::Status(300, 50, 30, 20, 10)}, // 仮ボス
};

//	floorEnemyTableの定義
std::vector<std::vector<int>> Charactors::EnemyDataTable::floorEnemyTable =
{
	//	各階層ごとの出現敵IDリスト
	{0},        // 1F: Slime
	{0, 0},     // 2F: Slime, 
	{0, 1, 0},  // 3F: Slime,Goblin,Slime
	{1, 1},     // 4F: Goblin,Goblin
	{1, 2, 1},  // 5F: Goblin,Orc,Goblin
	{0, 1},
	{1, 2},
	{2, 1},
	{2, 2},
	{3},
};