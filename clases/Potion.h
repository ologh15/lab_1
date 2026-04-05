#pragma once
#include "item.h"
#include <string>
#include <iostream>

class Potion : public Item {
private:
    int healAmount;

public:
    Potion();
    Potion(std::string n, int p, int heal);
    ~Potion();

    void showInfo() const;
    int getHealAmount() const;
};