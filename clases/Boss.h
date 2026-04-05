#pragma once
#include "enemy.h"
#include <string>
#include <iostream>

class Boss : public Enemy {
private:
    int specialAttack;

public:
    Boss();
    Boss(std::string n, int h, int lvl, std::string t, int d, int sa);
    ~Boss();

    void showInfo() const;
};