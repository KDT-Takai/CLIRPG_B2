#pragma once
#include <iostream>
#include "../Status/CharactorStatusComponent.h"
#include <vector>

namespace Charactors
{

    //　敵データの構造体
    struct EnemyData
    {
        int id;                 // 0から始まるID
        std::string name;       // キャラクター名
        Charactors::Status status;
    };


    // 敵データテーブルクラス
    class EnemyDataTable
    {
    public:


        //　敵のIDでの取得
        static EnemyData* GetEnemyData(int id)
        {
            if (id < 0 || id >= static_cast<int>(enemy.size()))
            {
                return nullptr;
            }
            return &enemy[id];
        }

        //  階層毎の出現敵IDリストの取得
        //  ０階から始まる想定なので注意
		static const std::vector<int>* GetFloorEnemyTable(int floor)
        {
            
            if (floor < 0 || floor >= static_cast<int>(floorEnemyTable.size()))
            {
                return nullptr;
			}

            return &floorEnemyTable[floor];
		}



    private:

        //　敵データの配列
        static std::vector<EnemyData> enemy;

        static std::vector<std::vector<int>> floorEnemyTable;

    };
}

