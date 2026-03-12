#include "Item.h"
#include <iostream>

Item::Item() : Item("Potion", 10) {}

Item::Item(std::string n, int p)
    : name(n), power(p) {}

Item::~Item() {
    std::cout << "Item destroyed\n";
}

void Item::showInfo() const {
    std::cout << "Item: " << name << " Power: " << power << std::endl;
}