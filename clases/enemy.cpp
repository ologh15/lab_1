#include "enemy.h"
#include <iostream>

Enemy::Enemy() : type("Unknown"), damage(0) {}

Enemy::Enemy(std::string t, int d) : type(t), damage(d) {}

Enemy::~Enemy() {
    std::cout << "Enemy destroyed: " << type << std::endl;
}

void Enemy::showInfo() const {
    std::cout << "Enemy: " << type << ", Damage: " << damage << std::endl;
}

bool Enemy::operator!() const {
    return damage <= 0;
}

std::ostream& operator<<(std::ostream& out, const Enemy& enemy) {
    out << enemy.type << " " << enemy.damage;
    return out;
}

std::istream& operator>>(std::istream& in, Enemy& enemy) {
    in >> enemy.type >> enemy.damage;
    return in;
}