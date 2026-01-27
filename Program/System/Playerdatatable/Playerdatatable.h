#pragma once
#include <iostream>
#include <vector>
#include <string>

// ステータス構造体
struct Status {
    int hp;
    int mp;
    int attack;
    int defense;
};

// レベル構造体
struct Level {
    int level;
    int exp;
    int nextExp;
};

struct PlayerData {
    int id;                 // 0から始まるID
    std::string name;       // 名前
    Status status;          // ステータス
    Level level;            // レベル情報
};


