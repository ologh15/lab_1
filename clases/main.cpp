#include <iostream>
#include <utility>
#include "character.h"
#include "item.h"
#include "enemy.h"
#include "Boss.h"
#include "Hero.h"

int main() {

    // Character hero1;
    // Character hero2("Knight", 150, 5);
    //
    // hero1.showInfo();
    // hero2.showInfo();

    Item item1("Sword", 25);
    item1.showInfo();

    Enemy enemy1("DragonName", 200, 10, "Dragon", 50);
    enemy1.showInfo();

    Boss boss1("DarkLord", 500, 20, "Demon", 80, 150);
    boss1.showInfo();

    Item sword("Sword", 50);
    Hero hero("Oleg", 200, 10, sword);

    hero.showInfo();

    // Character hero3 = hero2;
    // Character hero4 = std::move(hero3);
    //
    // hero2 += 20;
    //
    // std::cout << hero2 << std::endl;
    //
    // std::cin >> hero2;

    return 0;
}