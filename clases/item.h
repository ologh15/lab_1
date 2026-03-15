#pragma once
#include <string>
#include <iostream>

class Item {
private:
    std::string name;
    int power;

public:
    Item();
    Item(std::string n, int p);
    ~Item();

    void showInfo() const;

    friend std::ostream& operator<<(std::ostream& out, const Item& item);
    friend std::istream& operator>>(std::istream& in, Item& item);
};