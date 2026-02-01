#pragma once
#include <iostream>
#include "../Status/CharactorStatusComponent.h"
#include <vector>

namespace Charactors
{

    //　プレイヤーデータの構造体
    struct PlayerData 
    {
        int id;                 // 0から始まるID
        std::string name;      // キャラクター名
        Charactors::Status statusComp;
    };


    // プレイヤーデータテーブルクラス
    class PlayerDataTable 
    {
    public:


        //　プレイヤーのIDでの取得
        static PlayerData* GetPlayer(int id) 
        {
            if (id < 0 || id >= static_cast<int>(player.size())) 
            {
                return nullptr;
            }
            return &player[id];
        }

        // プレイヤー人数の取得
        //  いらないと思うけど一応作っておいているだけ
        static int GetPlayerCont()
        {
            return static_cast<int>(player.size());
        }

    private:

        //　プレイヤーデータの配列
        static std::vector<PlayerData> player;

    };
}

