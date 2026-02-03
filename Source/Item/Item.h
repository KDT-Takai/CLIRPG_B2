#pragma once
#include <string>

enum class ItemType {
    HealHP,
    HealMP,
    Revive
};

struct Item {
    std::string name;
    ItemType type;
    int value;
};
