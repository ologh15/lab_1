#include "item.h"
#include <iostream>

Item::Item() : name("Unknown"), power(0) {}

Item::Item(std::string n, int p) : name(n), power(p) {}

Item::~Item() {
    std::cout << "Item destroyed: " << name << std::endl;
}

void Item::showInfo() const {
    std::cout << "Item: " << name << ", Power: " << power << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item.name << " " << item.power;
    return out;
}

std::istream& operator>>(std::istream& in, Item& item) {
    in >> item.name >> item.power;
    return in;
}

std::string Item::getName() const {
    return name;
}