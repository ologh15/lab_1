#include "hero.h"
#include "item.h"
#include <iostream>

Hero::Hero()
    : Character("Hero", 100, 1), item("Default", 10) {}

Hero::Hero(std::string n, int h, int lvl, Item i)
    : Character(n, h, lvl), item(i) {}

Hero::~Hero() {
    std::cout << "Hero destroyed\n";
}

void Hero::showInfo() const {
    Character::showInfo();
    item.showInfo();
}

void Hero::attack() const {
    std::cout << getName() << " attacks with " << item.getName() << std::endl;
}

void Hero::display() const {
    std::cout << "[Hero] ";
    showInfo();
}