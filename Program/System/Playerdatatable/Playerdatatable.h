#pragma once
#include <iostream>
#include "Source/Chara/Status/CharactorStatusComponent.h"
namespace Charactors {
    // プレイヤーデータテーブルクラス
    class PlayerDataTable {
    public:

        //　プレイヤーデータの構造体
        static struct PlayerData {
            int id;                 // 0から始まるID
            std::string name;       // 名前
        };

        //　プレイヤーのIDでの取得
        PlayerData* GetPlayer(int id) {
            if (id < 0 || id >= static_cast<int>(mPlayer.size())) {
                return nullptr;
            }
            return &mPlayer[id];
        }

        // プレイヤー人数の取得
        int GetPlayerCont() const {
            return static_cast<int>(mPlayer.size());
        }
        //　プレイヤーデータの関数
        static void InitPlayer();

    private:
        //　プレイヤーデータの配列
        std::vector<PlayerData> mPlayer;
    };
}

