#include "potion.h"
#include <iostream>

Potion::Potion()
    : Item("DefaultPotion", 0), healAmount(0) {}

Potion::Potion(std::string n, int p, int heal)
    : Item(n, p), healAmount(heal) {}

Potion::~Potion() {
    std::cout << "Potion destroyed" << std::endl;
}

void Potion::showInfo() const {
    Item::showInfo();
    std::cout << "Heal amount: " << healAmount << std::endl;
}

int Potion::getHealAmount() const {
    return healAmount;
}

void Potion::display() const {
    std::cout << "[Potion] ";
    showInfo();
}