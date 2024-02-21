#pragma once
#include <iostream>
#include "stats/Health.h"
#include "stats/Damage.h"
#include "stats/Defense.h"
#include "stats/Level.h"
#include "stats/Gold.h"
#include "../item/Item.h"

class Player : public Health, public Damage, public Defense, public Level, public Gold {
public:


    bool set_username();
    std::string return_username();
    void show_all();
    void show_equipment();
    void show_info_infight();
    int healing_cost();
    int forge_cost(int);
    void check_lvlup(bool);
    bool equip(Item*);
    void reset_weapon();
    void reset_durability(int);
    std::string return_weapon_slot() { return weapon_slot; }
    std::string return_armor_slot() { return armor_slot; }
    int return_Weapondurability() { return weapon_durability; }
    int return_MaxWeapondurability() { return max_weapon_durability; }
    int return_Armordurability() { return armor_durability; }
    int return_MaxArmordurability() { return max_armor_durability; }
    int return_weaponPrice() { return weapon_price; }
    int return_armorPrice() { return armor_price; }
    int return_weaponDMG() { return weapon_damage; }
    int return_armorDMG() { return armor_damage; }
    int return_armorDEF() { return armor_defensiv; }
    int return_weaponDEF() { return weapon_defense; }
    int return_lifes() { return lifes; }
    void lose_life();
    bool check_lifes();
    void reset_armor();
    int return_weaponID();
    int return_armorID();
    void useMagicBlock();
    void reduceMagicShieldDuration();
    int getMagicShieldDuration();
    int getMagicShieldUses();
    void resetMagicShieldUses();
    bool getMagicShieldActiv() { return magicShieldActiv; }
    void reduce_weapon_durability();
    void reduce_armorn_durability();
    Item* unequipWeapon();
    Item* unequipArmor();
    bool loadGame();
    void saveGame();
    void clearFile();

    Player() : 
        name("None"),
        Health(25, 25),
        Level(1, 0),
        weapon_slot("Old Rusty Iron Sword"),
        weapon_id(1),
        weapon_price(4),
        max_weapon_price(5),
        weapon_durability(15),
        max_weapon_durability(15),
        Damage(1, 2, 0),
        armor_slot("Old Leather Armor"),
        armor_id(101),
        armor_price(4),
        max_armor_price(5),
        armor_durability(15),
        max_armor_durability(15),
        Defense(0, 2, 0),
        Gold(0),
        magicShieldDuration(0), 
        magicShieldUses(1),
        magicShieldActiv(false),

        lifes(3)
    {}

private:
    int magicShieldDuration;
    int magicShieldUses;
    bool magicShieldActiv;
    std::string name, weapon_slot, armor_slot;
    int lifes;
    int weapon_id, armor_id, weapon_durability, armor_durability, max_weapon_durability, max_armor_durability, weapon_price, max_weapon_price, armor_price, max_armor_price;
};