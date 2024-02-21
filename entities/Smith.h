#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "../item/Item.h"
#include "../inventory/Inventory.h"

class Smith {
public:
    Smith() {}

    void displayWeaponItems();
    void openWeaponShop(int);
    std::vector<Item*> getWeaponVector();
    void addSword(Item*);
    Item* buyWeaponItem(int);


    void displayArmorItems();
    void openArmorShop(int);
    std::vector<Item*> getArmorVector();
    void addArmor(Item*);
    Item* buyArmorItem(int);
    
    Item* mergeItem(Item*);
    void clearShop();
    int craftCost(Item*);

private:
    std::vector<Item*> weaponShop {};
    std::vector<Item*> armorShop {};
};