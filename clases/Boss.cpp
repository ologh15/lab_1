#include "boss.h"
#include <iostream>

Boss::Boss()
    : Enemy("Boss", 300, 10, "DragonBoss", 50), specialAttack(100) {}

Boss::Boss(std::string n, int h, int lvl, std::string t, int d, int sa)
    : Enemy(n, h, lvl, t, d), specialAttack(sa) {}

Boss::~Boss() {
    std::cout << "Boss destroyed\n";
}

void Boss::showInfo() const {
    Enemy::showInfo();
    std::cout << "Special attack: " << specialAttack << std::endl;
}

void Boss::attack() const {
    std::cout << getName() << " uses special attack: " << specialAttack << std::endl;
}
