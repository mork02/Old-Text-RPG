#pragma once
#include <iostream>
#include <vector>
#include "NPC.h"
#include "../item/Item_list.h"

// NPC(0, "BSP", 0, 0, 0, 0, 0, 0, 0, 0, {  }),

// Forest (lv. 1-2)
std::vector<NPC> getforest_vec() {
    //AREA ID | NAME | HP | MAX_HP | DMG | DEF | run chance | LVL | EXP | Gold drop | ITEN DROPS

    std::vector<NPC> forest_vector = {
        NPC(1, "Green Slime", 8, 8, 2, 0, 95, 1, 2, 2, { Item(3, 'S', "Slime Wip", 4, 1, 15, 15, 10, 10, 15),  Item(103, 'A', "Slime Armor", 1, 2, 10, 10, 10, 10, 15) }),
        NPC(1, "Blue Slime", 10, 10, 4, 0, 95, 1, 3, 3, { Item(3, 'S', "Slime Wip", 4, 1, 15, 15, 10, 10, 10),  Item(103, 'A', "Slime Armor", 1, 2, 10, 10, 10, 10, 15) }),
        NPC(1, "Red Slime", 15, 15, 5, 0, 95, 2, 5, 3, { Item(3, 'S', "Slime Wip", 4, 1, 15, 15, 10, 10, 10),  Item(103, 'A', "Slime Armor", 1, 2, 10, 10, 10, 10, 15) }),
        NPC(1, "Golden Slime", 25, 25, 5, 0, 80, 3, 5, 10, { Item(4, 'S', "Golden Slime Wip", 6, 1, 15, 15, 20, 20, 5), Item(104, 'A', "Golden Slime Armor", 6, 3, 15, 20, 15, 15, 5) }),
        NPC(1, "Wolf", 10, 10, 6, 1, 60, 2, 6, 5, { Item(5, 'S', "Wolfs Teeth Dagger", 5, -1, 20, 20, 15, 15, 10), Item(105, 'A', "Wolf Leather Armor", 4, 2, 20, 20, 10, 10, 10) }),
        NPC(1, "Ajoch-Wolf", 15, 15, 8, 1, 50, 2, 9, 7, { Item(5, 'S', "Wolfs Teeth Dagger", 5, -1, 20, 20, 15, 15, 10), Item(105, 'A', "Wolf Leather Armor", 4, 2, 20, 20, 10, 10, 10) }),
        NPC(1, "Dire Wolf", 18, 18, 11, 2, 50, 3, 11, 10, { Item(5, 'S', "Wolfs Teeth Dagger", 5, -1, 20, 20, 15, 15, 10), Item(105, 'A', "Wolf Leather Armor", 4, 2, 20, 20, 10, 10, 10) }),
        NPC(1, "Goblin", 13, 13, 8, 0, 50, 2, 7, 8, { Item(6, 'S', "Goblin Club", 8, -2, 25, 25, 15, 15, 5) }),
        NPC(1, "Skeleton", 3, 3, 3, 0, 100, 1, 4, 2, { Item(7, 'S', "Skeleton Bone", 4, 0, 50, 50, 10, 10, 55) }),
        NPC(1, "Bear", 17, 17, 5, 6, 40, 3, 10, 11, {  }),
        NPC(1, "Beran", 23, 23, 8, 9, 35, 4, 14, 14, { Item(106, 'A', "Beran Leather Armor", 1, 12, 40, 40, 30, 30, 3) }),
        NPC(1, "Golden-Tiger", 25, 25, 13, 4, 20, 4, 14, 14, { Item(8, 'S', "Golden-Tiger Tooth", 15, 0, 40, 40, 30, 30, 3), Item(107, 'A', "Golden-Tiger Armor", 8, 3, 40, 40, 30, 30, 3) })
    };
    return forest_vector;
}

// Abandoned Mine (lv 3-6)
std::vector<NPC> getmine_vec() {
    //AREA ID | NAME | HP | MAX_HP | DMG | DEF | run chance | LVL | EXP | Gold drop | ITEN DROPS

    std::vector<NPC> mine_vector = {
        NPC(2, "Troll's Dog", 13, 13, 7, 3, 45, 3, 10, 5, {  }),
        NPC(2, "Worker Troll", 15, 15, 6, 5, 75, 3, 12, 7, { Item(13, 'S', "Troll Dagger", 12, -2, 20, 20, 12, 12, 15), Item(109, 'A', "Thin Troll Armor", 0, 9, 20, 20, 15, 15, 10) }),
        NPC(2, "Guard Troll", 19, 19, 10, 8, 55, 4, 16, 9, { Item(12, 'S', "Troll Sword", 10, 0, 20, 20, 12, 12, 15), Item(109, 'A', "Thin Troll Armor", 0, 9, 20, 20, 15, 15, 10) }),
        NPC(2, "Big Door", 1, 1, 0, 30, 0, 1, 1, 0, { Item(11, 'S', "Noble piece of Wood", 1, 0, 1, 1, 10, 10, 100) }),
        NPC(2, "Troll Bodyguard", 23, 23, 15, 8, 55, 4, 18, 11, { Item(12, 'S', "Troll Sword", 10, 0, 20, 20, 12, 12, 15) }),
        NPC(2, "Troll Shaman", 10, 10, 6, 14, 100, 5, 18, 12, { Item(112, 'A', "Shaman Armor", 10, 6, 20, 20, 35, 30, 10) }),
        NPC(2, "Troll Berserker", 26, 26, 20, 1, 45, 5, 20, 15, { Item(12, 'S', "Troll Sword", 10, 0, 20, 20, 12, 12, 15) }),
        NPC(2, "Troll Champion", 30, 30, 20, 15, 35, 6, 25, 20, { Item(15, 'S', "Champions Sword", 20, 0, 40, 40, 80, 50, 5) }),
        NPC(2, "Troll Warlord", 45, 45, 26, 18, 45, 6, 30, 25, { Item(14, 'S', "Warlord Greatsword", 26, 0, 50, 50, 120, 60, 3), Item(111, 'A', "Warlord Fat Armor", -2, 19, 50, 50, 120, 60, 3) })

    };
    return mine_vector;
}

// Mountain (lv 6-9)
std::vector<NPC> getmountain_vec() {
    //AREA ID | NAME | HP | MAX_HP | DMG | DEF | run chance | LVL | EXP | Gold drop | ITEN DROPS

    std::vector<NPC> mountain_vector = {
        NPC(3, "Snowman", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(3, "Frost Giant", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(3, "Ghost Yeti", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(3, "Avalanche Yeti", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(3, "Baby Wyvern", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(3, "Frost Wolf", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(3, "Red Wyvern", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(3, "Ice Elemental", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(3, "Glacial Bear", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(3, "Frozen Yeti", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(3, "Arctic Dragon", 200, 200, 100, 80, 10, 10, 600, 280, { Item(16, 'S', "Arctic Dragon Sword", 80, 60, 80, 80, 500, 500, 100), Item(113, 'A', "Arctic Dragon Armor", 20, 40, 100, 100, 500, 500, 100) })

    };
    return mountain_vector;
}

// End of World (lv 10>)
std::vector<NPC> getendofworld_vec() {
    //AREA ID | NAME | HP | MAX_HP | DMG | DEF | run chance | LVL | EXP | Gold drop | ITEN DROPS

    std::vector<NPC> endofworld_vector = {
        NPC(0, "ENDGAME Green Slime", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Blue Slime", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Golden Slime", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Wolf", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Ajoch-Wolf", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Red Slime", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Goblin", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Skeleton", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Dire Wolf", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Orc Warrior", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Bear", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Beran", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Golden-Tiger", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Troll's Dog", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Worker Troll", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Guard Troll", 0, 0, 0, 0, 0, 0, 0, 0, {  }),
        NPC(0, "ENDGAME Troll Bodyguard", 0, 0, 0, 0, 0, 0, 0, 0, { }),
        NPC(0, "ENDGAME Troll Boss", 0, 0, 0, 0, 0, 0, 0, 0, { }),
        NPC(0, "ENDGAME Frost Giant", 0, 0, 0, 0, 0, 0, 0, 0, { }),
        NPC(0, "ENDGAME Ghost Yeti", 0, 0, 0, 0, 0, 0, 0, 0, { }),
        NPC(0, "ENDGAME Avalanche Yeti", 0, 0, 0, 0, 0, 0, 0, 0, { }),
        NPC(0, "ENDGAME Baby Wyvern", 0, 0, 0, 0, 0, 0, 0, 0, { }),
        NPC(0, "ENDGAME Red Wyvern", 0, 0, 0, 0, 0, 0, 0, 0, { }),
        NPC(0, "ENDGAME Ice Elemental", 0, 0, 0, 0, 0, 0, 0, 0, { }),
        NPC(0, "ENDGAME Frost Wolf", 0, 0, 0, 0, 0, 0, 0, 0, { }),
        NPC(0, "ENDGAME Glacial Bear", 0, 0, 0, 0, 0, 0, 0, 0, { }),
        NPC(0, "ENDGAME Frozen Yeti", 0, 0, 0, 0, 0, 0, 0, 0, { }),
        NPC(0, "ENDGAME Arctic Dragon", 0, 0, 0, 0, 0, 0, 0, 0, { })
    };
    return endofworld_vector;
}

