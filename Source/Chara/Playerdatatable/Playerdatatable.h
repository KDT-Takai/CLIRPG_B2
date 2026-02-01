#pragma once
#include <iostream>
#include "../Status/CharactorStatusComponent.h"
#include <vector>

namespace Charactors {

    // プレイヤーデータテーブルクラス
    class PlayerDataTable {
    public:

        //　プレイヤーデータの構造体
        static struct PlayerData {
            int id;                 // 0から始まるID
			std::string name;      // キャラクター名
            Charactors::Status statusComp;
        };

        //　プレイヤーのIDでの取得
        static PlayerData* GetPlayer(int id) 
        {
            if (id < 0 || id >= static_cast<int>(mPlayer.size())) 
            {
                return nullptr;
            }
            return &mPlayer[id];
        }

        // プレイヤー人数の取得
        int GetPlayerCont() const
        {
            return static_cast<int>(mPlayer.size());
        }

    private:

        //　プレイヤーデータの配列
        static std::vector<PlayerData> mPlayer;
    };
}

