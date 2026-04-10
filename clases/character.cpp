#include "character.h"
#include <iostream>
#include <utility>

int Character::characterCount = 0;

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
    : name(std::move(other.name)), health(other.health), level(other.level) {
    characterCount++;
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

std::string Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getLevel() const {
    return level;
}

Character& Character::setLevel(int level) {
    this->level = level;
    return *this;
}

int Character::getCharacterCount() {
    return characterCount;
}

Character& Character::operator+=(int hp) {
    health += hp;
    return *this;
}

// Character Character::operator+(int hp) const {
//     Character temp(*this);
//     temp.health += hp;
//     return temp;
// }

bool Character::operator!() const {
    return health <= 0;
}

std::ostream& operator<<(std::ostream& os, const Character& c) {
    os << "Name: " << c.name << ", HP: " << c.health << ", Level: " << c.level;
    return os;
}

std::istream& operator>>(std::istream& is, Character& c) {
    std::cout << "Enter name: ";
    is >> c.name;
    std::cout << "Enter health: ";
    is >> c.health;
    std::cout << "Enter level: ";
    is >> c.level;
    return is;
}