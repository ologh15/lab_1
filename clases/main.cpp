#include "Character.h"
#include "Item.h"
#include "Enemy.h"

int main() {

    Character hero("Knight", 150, 5);
    hero.showInfo();

    Item sword("Sword", 25);
    sword.showInfo();

    Enemy dragon("Dragon", 50);
    dragon.showInfo();

    return 0;
}