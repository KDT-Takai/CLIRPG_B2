#include "Playerdatatable.h"

//　プレイヤーデータの関数
void InitPlayer() {
    //　プレイヤーデータテーブルの作成
    PlayerDataTable table;

    //　プレイヤーのステータス
    Status status = { 100,50,20,10 };
    //　プレイヤーのレベル
    Level level = { 1,0,100 };
	//　プレイヤーの追加
    table.AddPlayer("勇者", status, level);
    
    //　プレイヤーの取得と表示
    PlayerData* player = table.GetPlayer(0);
    if (player) {
        std::cout << player->name << " Lv." << player->level.level << std::endl;
        std::cout << "HP: " << player->status.hp << std::endl;
        std::cout << "MP: " << player->status.mp << std::endl;
        std::cout << "攻撃力: " << player->status.attack << std::endl;
        std::cout << "防御力: " << player->status.defense << std::endl;

    }
}
