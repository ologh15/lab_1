#pragma once
#include <string>

class Enemy {
private:
    std::string type;
    int damage;

public:
    Enemy();
    Enemy(std::string t, int d);

    ~Enemy();

    void showInfo() const;
};