#pragma once
#include <iostream>
#include "Item.h"

class Weapon {
public:
    Weapon(int _damage) : damage(_damage) {}
    int getDamage() const { return damage; }
protected:
    int damage;
};