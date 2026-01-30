#pragma once
#include <iostream>
#include "Source/Chara/Status/CharactorStatusComponent.h"
namespace Charactors {
    // プレイヤーデータテーブルクラス
    class PlayerDataTable {
    public:
        // ステータス構造体
        static struct Status {
            int hp;         //　hp
            int mp;         //  mp
            int attack;     // 攻撃力
            int defense;    // 防御力
        };

        // レベル構造体
        static struct Level {
            int level;      // レベル
            int exp;        // 経験値
            int nextExp;    // 次のレベルまでの経験値
        };

        //　プレイヤーデータの構造体
        static struct PlayerData {
            int id;                 // 0から始まるID
            std::string name;       // 名前
            Status status;          // ステータス
            Level level;            // レベル情報
        };
        // プレイヤーの追加
        void AddPlayer(const std::string& name, const Status& status, const Level& level) {
            int id = static_cast<int>(mPlayer.size());
            mPlayer.push_back({ id, name, status, level });
        }

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

