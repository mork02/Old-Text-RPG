// npc.h
#pragma once
#include <iostream>
#include <vector>
#include "stats/Health.h"
#include "stats/Damage.h"
#include "stats/Defense.h"
#include "stats/Level.h"
#include "stats/Gold.h"
#include "../item/Item.h"

class NPC : public Health, public Damage, public Defense, public Level, public Gold {
public:

    NPC(int _area_id, std::string _name, int _hp, int _max_hp, int _damage, int _defense, int _run_chance, int _lvl, int _exp, int _gold, std::vector<Item> _mobItemDrop) : 
            area_id(_area_id),
            name(_name),
            Health(_hp, _max_hp),
            Damage(_damage, 0, 0),
            Defense(_defense, 0, 0),
            run_chance(_run_chance),
            Level(_lvl, _exp),
            Gold(_gold),
            itemDrops(_mobItemDrop)
        {}

    void afterfight();
    void show_info();
    void show_info_infight(int);
    int return_run_chance() { return run_chance; }
    int return_area_id() { return area_id; }
    Item dropRandomItem(int);
    std::vector<Item> return_itemDrops() { return itemDrops; }
    int getChance() { return rand() % 100; }
    std::string return_name();

private:
    int area_id;
    std::string name;
    std::vector<Item> itemDrops;
    int run_chance;
    
protected:
};