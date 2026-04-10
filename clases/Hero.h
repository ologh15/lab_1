#pragma once
#include "character.h"
#include "IDisplay.h"
#include "item.h"


class Hero : public Character, public IDisplay {
private:
    Item item;

public:
    Hero();
    Hero(std::string n, int h, int lvl, Item i);
    ~Hero();

    void showInfo() const override;
    void attack() const override;
    void display() const override;
};