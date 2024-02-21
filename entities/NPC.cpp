// npc.cpp
#include "NPC.h"
#include <cmath>

Item NPC::dropRandomItem(int _dropChance) {
        int rand_num = getChance();
        if (rand_num < _dropChance) {
            int rand_index = rand() % itemDrops.size();
            return itemDrops[rand_index];
        } else {
            return Item(0, 'N', "", 0, 0, 0, 0, 0, 0, 0);
        }
    }

void NPC::show_info() {
    std::cout << "Name: " << name << " | Lvl. " << level << std::endl; 
    std::cout << hp << " / " << max_hp << " HP" << std::endl;
    std::cout << normal_damage << " DAMAGE" <<std::endl; 
    std::cout << normal_defense << " DEFESE"<< std::endl;
}

void NPC::show_info_infight(int difficulty) {
    std::cout << name << " | Lvl. " << level << std::endl; 
    std::cout << hp << " / " << max_hp << " HP" << std::endl;
    if (difficulty == 1) {
        std::cout << "MAX DMG: " << round(normal_damage / 1.5) << " | " << "DEF: " << normal_defense << " | Run-Chance: " << run_chance << "%" << std::endl; 
    } else if (difficulty == 2) {
        std::cout << "MAX DMG: " << normal_damage << " | " << "DEF: " << normal_defense << " | Run-Chance: " << run_chance << "%" << std::endl; 
    } else if (difficulty == 3) {
        std::cout << "MAX DMG: " << round(normal_damage * 1.5) << " | " << "DEF: " << normal_defense << " | Run-Chance: " << run_chance << "%" << std::endl; 

    }
}

void NPC::afterfight() {
    hp = max_hp;
}

std::string NPC::return_name() {
    return name;
}
