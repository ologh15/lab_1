#include "Character.h"
#include <iostream>

// delegation constructor
Character::Character() : Character("Hero", 100, 1) {
    std::cout << "delegation constructor called\n";
}

// constructor with args
Character::Character(std::string n, int h, int lvl)
    : name(n), health(h), level(lvl) {
    characterCount++;
}

// copy constructor
Character::Character(const Character& other)
    : name(other.name), health(other.health), level(other.level) {
    characterCount++;
}

// move constructor
Character::Character(Character&& other) noexcept
    : name(other.name), health(other.health), level(other.level) {

    other.name = "";
    other.health = 0;
    other.level = 0;
}

// destructor
Character::~Character() {
    std::cout << "Character destroyed: " << name << std::endl;
    characterCount--;
}

void Character::showInfo() const {
    std::cout << name << " HP:" << health << " Level:" << level << std::endl;
}

int Character::characterCount = 0;

int Character::getCharacterCount() {
    return characterCount;
}

Character& Character::operator+=(int hp) {
    health += hp;
    return *this;
}

bool Character::operator!() const {
    return health <= 0;
}