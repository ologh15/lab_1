#pragma once
#include <string>

class Character {
private:
    std::string name;
    int health;
    int level;

    static int characterCount;

public:
    Character();
    Character(std::string n, int h, int lvl);

    Character(const Character& other);
    Character(Character&& other) noexcept;

    ~Character();

    void showInfo() const;
    int getCharacterCount();

    Character& operator+=(int hp);
    bool operator!() const;
};