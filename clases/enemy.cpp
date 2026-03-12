#include "Enemy.h"
#include <iostream>

Enemy::Enemy() : Enemy("Goblin", 15) {}

Enemy::Enemy(std::string t, int d)
    : type(t), damage(d) {}

Enemy::~Enemy() {
    std::cout << "Enemy destroyed\n";
}

void Enemy::showInfo() const {
    std::cout << "Enemy: " << type << " Damage: " << damage << std::endl;
}