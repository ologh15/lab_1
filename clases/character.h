#pragma once
#include <string>
#include <iostream>

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

    std::string getName() const;
    int getHealth() const;
    int getLevel() const;

    Character& setLevel(int level);

    static int getCharacterCount();

    Character& operator+=(int hp);
    Character operator+(int hp) const;
    bool operator!() const;

    friend std::ostream& operator<<(std::ostream& os, const Character& c);
    friend std::istream& operator>>(std::istream& is, Character& c);
};