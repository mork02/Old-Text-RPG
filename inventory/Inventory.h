#pragma once
#include <iostream>
#include <vector>
#include "../item/Item.h"

class Item;

class Inventory {
public:
    Inventory() {}

    Item* getinventoryItem(size_t id);
    void displayItems() const;
    void displaySellItems() const;
    void displayMergeItems();
    void addItem(Item*);
    bool isEmpty() const;
    void remove_item(int);
    std::vector<Item*> getInventory() { return inventory; }
    std::size_t getInventorySize() { return inventory.size(); }

private:
    std::vector<Item*> inventory;
};