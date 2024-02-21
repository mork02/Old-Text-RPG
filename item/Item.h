#pragma once
#include <iostream>
#include <math.h>
#include "Weapon.h"
#include "Armor.h"

class Item : public Weapon, public Armor {
public:
    Item(int _id, char _categorie, std::string _name, int _damage, int _defensiv, int _durability, int _max_durability, int _price, int _upgrade_price, int _itemDropChance) : 
    id(_id), categorie(_categorie), name(_name), durability(_durability), max_durability(_max_durability), Weapon(_damage), Armor(_defensiv), price(_price), upgrade_price(_upgrade_price), itemDropChance(_itemDropChance) {}

    int get_id() const { return id; }
    char get_categorie() const { return categorie; }
    const std::string& get_name() const { return name; }
    int get_durability() const { return durability; }
    int get_max_durability() const { return max_durability; }
    int return_price() { return price; }
    int return_upgrade_price() { return round(upgrade_price / 1.35); }
    int return_itemDropChance() { return itemDropChance; }
    int sell_item() { return round(price / 1.5); }

protected:
    int id, price, upgrade_price, durability, max_durability;
    int itemDropChance;
    std::string name;
    char categorie;
};

