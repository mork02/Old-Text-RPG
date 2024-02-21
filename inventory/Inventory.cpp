#include <iostream>
#include <sstream>
#include "Inventory.h"

void Inventory::displayItems() const {
    size_t size = inventory.size();
    size_t index = 0;
    if (size > 0) {
        for (const auto& item : inventory) {
            if (item->get_categorie() == 'S') {
                std::cout << "ID: " << item->get_id() << " | " << item->get_name() << " | " << "Damage: " << item->getDamage() << " | " << "Defensiv: " << item->getDefense() << " | " << "Durability: " << item->get_durability()  << "/" << item->get_max_durability() << std::endl;
                
            } else if (item->get_categorie() == 'A') {
                std::cout << "ID: " << item->get_id() << " | " << item->get_name() << " | " << "Defense: " << item->getDefense() << " | " << "Damage: " << item->getDamage() << " | " << "Durability: " << item->get_durability()  << "/" << item->get_max_durability() << std::endl;
            }
            if (index == size - 1) {
                continue;
            }
            ++index;
        }
    }
    std::cout << "+------------------------------------------+" << std::endl;
}

void Inventory::displaySellItems() const {
    size_t size = inventory.size();
    size_t index = 0;
    if (size > 0) {
        for (const auto& item : inventory) {
            if (item->get_categorie() == 'S') {
                std::cout << "ID: " << item->get_id() << " | " << item->get_name() << " | " << "Damage: " << item->getDamage() << " | " << "Defensiv: " << item->getDefense() << " | " << "Durability: " << item->get_durability()  << "/" << item->get_max_durability() << " | Price: " << item->return_price() << std::endl;
                 
            } else if (item->get_categorie() == 'A') {
                std::cout << "ID: " << item->get_id() << " | " << item->get_name() << " | " << "Defense: " << item->getDefense() << " | " << "Damage: " << item->getDamage() << " | " << "Durability: " << item->get_durability()  << "/" << item->get_max_durability() << " | Price: " << item->return_price() << std::endl;
            }
            if (index == size - 1) {
                continue;
            }
            ++index;
        }
    }
    std::cout << "+------------------------------------------+" << std::endl;
}

void Inventory::displayMergeItems() {
    size_t size = inventory.size();
    size_t index = 0;
    if (size > 0) {
        for (const auto& item : inventory) {
            if (item->get_categorie() == 'S') {
                std::cout << "ID: " << item->get_id() << " | " << item->get_name() << " | " << "Damage: " << item->getDamage() << " | " << "Defensiv: " << item->getDefense() << " | " << "Durability: " << item->get_durability()  << "/" << item->get_max_durability() << " | \033[4mUpgrade Cost: " << item->return_upgrade_price() << "\033[0m" << std::endl;
                 
            } else if (item->get_categorie() == 'A') {
                std::cout << "ID: " << item->get_id() << " | " << item->get_name() << " | " << "Defense: " << item->getDefense() << " | " << "Damage: " << item->getDamage() << " | " << "Durability: " << item->get_durability()  << "/" << item->get_max_durability() << " | \033[4mUpgrade Cost: " << item->return_upgrade_price() << "\033[0m" << std::endl;
            }
            if (index == size - 1) {
                continue;
            }
            ++index;
        }
    }
    std::cout << "+------------------------------------------+" << std::endl;
}

void Inventory::addItem(Item* _item) {
    inventory.push_back(_item);
}

void Inventory::remove_item(int _item_id) {
    std::istringstream iss(std::to_string(_item_id));
    int id;
    if (!(iss >> id)) {
        std::cerr << "Invalid input. Please enter a valid item ID." << std::endl;
        return;
    }

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if ((*it)->get_id() == _item_id) {
            inventory.erase(it);
            return;
        }
    }

    std::cout << "Item with ID " << _item_id << " not found in inventory." << std::endl;
}

Item* Inventory::getinventoryItem(std::size_t id) {
    for (Item* item : inventory) {
        if (item->get_id() == id) {
            return item;
        }
    }

    std::cout << "No item with ID " << id << " found in inventory." << std::endl;
    return nullptr;
}

bool Inventory::isEmpty() const {
    return inventory.empty();
}

