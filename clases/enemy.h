#pragma once
#include "character.h"
#include <string>
#include <iostream>

class Enemy : public Character {
private:
    std::string type;
    int damage;

public:
    Enemy();
    Enemy(std::string n, int h, int lvl, std::string t, int d);
    ~Enemy();

    void showInfo() const;
    bool operator!() const;

    friend std::ostream& operator<<(std::ostream& out, const Enemy& enemy);
    friend std::istream& operator>>(std::istream& in, Enemy& enemy);
};