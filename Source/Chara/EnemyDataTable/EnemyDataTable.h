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

        // 敵種類の取得
        //  いらないと思うけど一応作っておいているだけ
        static int GetEnemyCont() 
        {
            return static_cast<int>(enemy.size());
        }

    private:

        //　敵データの配列
        static std::vector<EnemyData> enemy;

    };
}

