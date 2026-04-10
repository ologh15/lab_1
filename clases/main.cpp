#include <iostream>
#include <utility>
#include "character.h"
#include "item.h"
#include "enemy.h"
#include "Boss.h"
#include "Hero.h"
#include "Potion.h"



void showCharacterByReference(const Character& character) {
    character.showInfo();
    character.attack();
}

int main() {

    // Character hero1;
    // // Character hero2("Knight", 150, 5);
    //
    // hero1.showInfo();
    // // hero2.showInfo();
    //
    // Item item1("Sword", 25);
    // item1.showInfo();
    //
    // Enemy enemy1("DragonName", 200, 10, "Dragon", 50);
    // enemy1.showInfo();
    //
    // Boss boss1("DarkLord", 500, 20, "Demon", 80, 150);
    // boss1.showInfo();
    //
    // Item sword("Sword", 50);
    // Hero hero("Oleg", 200, 10, sword);
    //
    // Potion potion1("HealthPotion", 10, 50);
    // potion1.showInfo();
    //
    // hero.showInfo();
    // Character* basePtr = new Hero("StaticHero", 180, 7, Item("Axe", 40));
    // basePtr->showInfo();
    // delete basePtr;
    //
    // Character temp;
    // std::cin >> temp;
    // std::cout << temp << std::endl;
    //
    // Character hero3 = temp;
    // Character hero4 = std::move(hero3);
    //
    // // hero2 += 20;
    // //
    // // std::cout << hero2 << std::endl;
    // //
    // // std::cin >> hero2;
    //
    //



    Character* basePtr = new Hero("StaticHero", 180, 7, Item("Axe", 40));
    basePtr->showInfo();
    delete basePtr;

    std::cout << "\n--- Run-time polymorphism with base pointer ---" << std::endl;

    Character* ptr1 = new Hero("Artem", 150, 5, Item("Sword", 30));
    Character* ptr2 = new Enemy("Goblin", 80, 2, "Monster", 15);
    Character* ptr3 = new Boss("Diablo", 400, 10, "Demon", 40, 100);

    ptr1->showInfo();
    ptr1->attack();
    std::cout << std::endl;

    ptr2->showInfo();
    ptr2->attack();
    std::cout << std::endl;

    ptr3->showInfo();
    ptr3->attack();
    std::cout << std::endl;

    delete ptr1;
    delete ptr2;
    delete ptr3;




    std::cout << "\n--- Run-time polymorphism with base reference ---" << std::endl;

    Hero heroRef("Leon", 170, 6, Item("Bow", 25));
    Enemy enemyRef("Orc", 120, 3, "Warrior", 20);
    Boss bossRef("Azmodan", 500, 12, "Demon", 50, 120);

    showCharacterByReference(heroRef);
    std::cout << std::endl;

    showCharacterByReference(enemyRef);
    std::cout << std::endl;

    showCharacterByReference(bossRef);
    std::cout << std::endl;



    return 0;
}
