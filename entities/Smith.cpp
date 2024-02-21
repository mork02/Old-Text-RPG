#include "Smith.h"


void Smith::displayWeaponItems() {
    size_t size = weaponShop.size();
    size_t index = 0;
    for (const auto& item : weaponShop) {
        if (item->get_categorie() == 'S') { 
            std::cout << "ID: " << item->get_id() << " | " << item->get_name() << " | " << "Damage: " << item->getDamage() << " | " << "Defensiv: " << item->getDefense() << " | " << "Durability: " << item->get_durability() << " | Price: " << item->return_price() << std::endl;
        } if (index == size - 1) {
            continue;
        }
        ++index;
    }
    std::cout << "+------------------------------------------+" << std::endl;
}

void Smith::openWeaponShop(int _level) {
    if (_level <= 3) {
        addSword(new Item(9, 'S', "Old Smith Sword", 1, 0, 5, 5, 1, 5, 0));
        addSword(new Item(2, 'S', "Iron Sword", 5, 0, 25, 25, 30, 20, 5));
        addSword(new Item(10, 'S', "Iron Dagger", 4, 0, 20, 20, 20, 20, 0));
        addSword(new Item(13, 'S', "Zweihänder", 9, -3, 25, 25, 35, 25, 0));
    } else if (_level <= 7) {
        addSword(new Item(2, 'S', "Iron Sword+", 7, 0, 25, 25, 30, 20, 5));
        addSword(new Item(10, 'S', "Iron Dagger+", 6, 0, 20, 20, 20, 20, 0));
        addSword(new Item(13, 'S', "Zweihänder+", 12, -3, 25, 25, 35, 25, 0));
    } else {
        addSword(new Item(2, 'S', "Smith | Iron Sword", 15, 0, 25, 25, 30, 20, 5));
        addSword(new Item(10, 'S', "Smith | Iron Dagger", 16, 0, 20, 20, 20, 20, 0));
        addSword(new Item(13, 'S', "Smith | Zweihänder", 21, -6, 25, 25, 35, 25, 0));
    }
    displayWeaponItems();
}

std::vector<Item*> Smith::getWeaponVector() {
    return weaponShop;
}

void Smith::addSword(Item* _item) {
    weaponShop.push_back(_item);
}

Item* Smith::buyWeaponItem(int _id) {
    for (Item* item : weaponShop) {
        if (item->get_id() == _id) {
            return item;
        }
    }
    return nullptr;
}

//

void Smith::displayArmorItems() {
    size_t size = armorShop.size();
    size_t index = 0;
    for (const auto& item : armorShop) {
        if (item->get_categorie() == 'A') {
                std::cout << "ID: " << item->get_id() << " | " << item->get_name() << " | " << "Defense: " << item->getDefense() << " | " << "Damage: " << item->getDamage() << " | " << "Durability: " << item->get_durability() << "/" << item->get_max_durability() << " | Price: " << item->return_price() << std::endl;
        }
        ++index;
    }
    std::cout << "+------------------------------------------+" << std::endl;
}

void Smith::openArmorShop(int _level) {
    if (_level <= 3) {
        addArmor(new Item(108, 'A', "Old Smith Leather Armor", 0, 1, 5, 5, 1, 5, 0));
        addArmor(new Item(102, 'A', "Iron Armor", 0, 6, 25, 25, 25, 25, 0));
        addArmor(new Item(110, 'A', "Leather Armor", 2, 3, 20, 20, 30, 30, 0));
    } else if (_level <= 7) {
        addArmor(new Item(102, 'A', "Iron Armor+", 0, 9, 25, 25, 25, 25, 0));
        addArmor(new Item(110, 'A', "Leather Armor+", 4, 6, 20, 20, 30, 30, 0));
    } else {
        addArmor(new Item(102, 'A', "Smith | Iron Armor", 0, 18, 25, 25, 25, 25, 0));
        addArmor(new Item(110, 'A', "Smith | Leather Armor", 9, 13, 20, 20, 30, 30, 0));
    }
    displayArmorItems();
}

std::vector<Item*> Smith::getArmorVector() {
    return armorShop;
}

void Smith::addArmor(Item* _item) {
    armorShop.push_back(_item);
}

Item* Smith::buyArmorItem(int _id) {
    for (Item* item : armorShop) {
        if (item->get_id() == _id) {
            return item;
        }
    }
    return nullptr;
}

//

Item* Smith::mergeItem(Item* _item) {
    return new Item(_item->get_id(), _item->get_categorie(), _item->get_name() + "+", _item->getDamage() + round(cbrt(_item->getDamage() * 2)), _item->getDefense() + round(cbrt(_item->getDefense() * 2)), _item->get_durability(), _item->get_max_durability(), _item->return_price(), round(_item->return_upgrade_price() * 3), _item->return_itemDropChance());
}

void Smith::clearShop() {
    weaponShop.clear();
    armorShop.clear();
}

int Smith::craftCost(Item* _item) {
    return _item->return_price();
}