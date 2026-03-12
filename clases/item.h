#pragma once
#include <string>

class Item {
private:
    std::string name;
    int power;

public:
    Item();
    Item(std::string n, int p);

    ~Item();

    void showInfo() const;
};