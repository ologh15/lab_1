#include "enemy.h"
#include <iostream>

Enemy::Enemy()
    : Character("UnknownEnemy", 50, 1), type("Unknown"), damage(0) {}

Enemy::Enemy(std::string n, int h, int lvl, std::string t, int d)
    : Character(n, h, lvl), type(t), damage(d) {}

Enemy::~Enemy() {
    std::cout << "Enemy destroyed: " << type << std::endl;
}

void Enemy::showInfo() const {
    Character::showInfo();
    std::cout << "Type: " << type << ", Damage: " << damage << std::endl;
}

bool Enemy::operator!() const {
    return damage <= 0;
}

std::ostream& operator<<(std::ostream& out, const Enemy& enemy) {
    out << enemy.getName() << " "
        << enemy.getHealth() << " "
        << enemy.getLevel() << " "
        << enemy.type << " "
        << enemy.damage;
    return out;
}