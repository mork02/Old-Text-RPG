#pragma once
#include "Item.h"
#include <vector>

// ID | CATEGORY | NAME | DNG | DEFENSIV | DURABILITY | MAX_DURABILITY | GOLD | DROPCHANCE

std::vector<Item> Equipment {
    Item(1, 'S', "Old Rusty Iron Sword", 2, 0, 10, 10, 4, 5, 0),
    Item(2, 'S', "Iron Sword", 5, 0, 25, 25, 30, 20, 5),
    Item(3, 'S', "Slime Wip", 4, 1, 15, 15, 10, 10, 10),
    Item(4, 'S', "Golden Slime Wip", 6, 1, 15, 15, 20, 20, 5),
    Item(5, 'S', "Wolfs Teeth Dagger", 5, -1, 20, 20, 15, 15, 10),
    Item(6, 'S', "Goblin Club", 8, -2, 25, 25, 15, 15, 5),
    Item(7, 'S', "Skeleton Bone", 4, -2, 40, 40, 10, 10, 55),
    Item(8, 'S', "Golden-Tiger Tooth", 15, 0, 40, 40 , 40, 40, 3),
    Item(9, 'S', "Old Smith Sword", 1, 0, 5, 5, 1, 5, 0),
    Item(10, 'S', "Iron Dagger", 6, -2, 20, 20, 25, 20, 0),
    Item(11, 'S', "Noble piece of Wood", 1, 0, 1, 1, 10, 10, 100),
    Item(12, 'S', "Troll Sword", 10, 0, 20, 20, 12, 12, 15),
    Item(12, 'S', "Troll Dagger", 12, -2, 20, 20, 12, 12, 15),
    Item(13, 'S', "Zweihänder", 9, -3, 25, 25, 35, 25, 0),
    Item(14, 'S', "Warlord Greatsword", 26, 0, 50, 50, 120, 60, 3),
    Item(15, 'S', "Champions Sword", 20, 0, 40, 40, 80, 50, 5),
    Item(16, 'S', "Arctic Dragon Sword", 100, 80, 80, 80, 500, 500, 100),

    Item(101, 'A', "Old Leather Armor", 0, 2, 15, 15, 4, 5, 0),
    Item(102, 'A', "Iron Armor", 0, 6, 25, 25, 35, 35, 0),
    Item(103, 'A', "Slime Armor", 1, 2, 10, 10, 10, 10, 15),
    Item(104, 'A', "Golden Slime Armor", 6, 3, 15, 15, 15, 15, 5),
    Item(105, 'A', "Wolf Leather Armor", 4, 2, 20, 20, 10, 10, 10),
    Item(106, 'A', "Beran Leather Armor", 1, 12, 40, 40, 30, 30, 3),
    Item(107, 'A', "Golden-Tiger Armor", 8, 3, 40, 40, 30, 30, 3),
    Item(108, 'A', "Old Smith Leather Armor", 0, 1, 5, 5, 1, 5, 0),
    Item(109, 'A', "Thin Troll Armor", 3, 9, 20, 20, 15, 15, 10),
    Item(110, 'A', "Leather Armor", 2, 3, 20, 20, 30, 30, 0),
    Item(111, 'A', "Warlord Fat Armor", -2, 19, 50, 50, 120, 60, 3),
    Item(112, 'A', "Shaman Armor", 10, 6, 20, 20, 35, 30, 10),
    Item(113, 'A', "Arctic Dragon Armor", 20, 40, 100, 100, 500, 500, 100)

};

Item* getequipmentItem(std::size_t id) {
    for (Item& item : Equipment) {
        if (item.get_id() == id) {
            return &item;
        }
    }

    std::cout << "No item with ID " << id << " found in inventory." << std::endl;
    return nullptr;
}