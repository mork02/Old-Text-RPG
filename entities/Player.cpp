#include "Player.h"
#include <string>
#include <cmath>

bool name__ = false;

bool Player::set_username() {
    std::cout << "Enter your Username\n> ";
    if (name__ == false) {
        std::getline(std::cin, name);
        name__ = true;
        return true;
    } else {
        std::cin.get();
        std::getline(std::cin, name);
        return true;
    }
    return false;
}

std::string Player::return_username() {
    return name;
}

void Player::show_info_infight() {
    std::cout << name << " | Lvl. " << level << std::endl;
    std::cout << hp << " / " << max_hp << " HP" << std::endl;
    std::cout << "DMG: " << return_damage() << " | " << "DEF: " << return_defense() << " | " << "Magic-Shield Uses: " << magicShieldUses << std::endl; 
}

void Player::show_equipment() {
    std::cout << "Weapon: " << weapon_slot << " (Damage: " << weapon_damage << " - Defence: " << weapon_defense <<  " - Durability: " << weapon_durability << "/" << max_weapon_durability << ") \n" << "Armor: " << armor_slot << " (Defence: " << armor_defensiv << " - Damage: " << armor_damage << " - Durability: " << armor_durability << "/" << max_armor_durability << ")\n" << std::endl;
}

void Player::show_all() {
    std::cout << "Username: " << name << std::endl;
    std::cout << "HP: " << hp << " / " << max_hp << std::endl;
    std::cout << "Weapon: " << weapon_slot << " | " << "Durability: " << weapon_durability << "/" << max_weapon_durability<< std::endl;
    std::cout << "Damage: " << return_damage() << std::endl;
    std::cout << "Armor: " << armor_slot << " | " << "Durability: " <<armor_durability << "/" << max_armor_durability << std::endl;
    std::cout << "Defense: " << return_defense() << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Exp: " << exp << " / " << calculateExpForLevel() << std::endl;
    std::cout << "Gold: " << gold_amount << std::endl;
}

void Player::lose_life() {
    lifes--;
}

bool Player::check_lifes() {
    lose_life();
    if (lifes > 0) {
        std::cout << name << " died... You lose one Life, you have " << lifes << " left before the game ends!" << std::endl;
        heal_max();
        return true;
    } else {
        std::cout << name << " lost all lives. Thank you for playing! Good luck next time." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Press Enter to end the game.";
        std::cin.get();
        return false;
    }
}


int Player::healing_cost() {
    return pow(level, 3);
}

int Player::forge_cost(int w_or_a) {
    if (w_or_a == 1) {
        return weapon_damage * 1.5;
    } else if (w_or_a == 2) {
        return armor_defensiv * 1.5;
    } 
    return 0;
}

void Player::check_lvlup(bool _lvl) {
    if (_lvl) {
        if (level == 1) {
            hp = 25;
            max_hp = 25;
            normal_damage = 1;
            normal_defense = 0;
        } else if (level == 2) {
            hp = 35;
            max_hp = 35;
            normal_damage = 3;
            normal_defense = 1;
        } else if (level == 3) {
            hp = 50;
            max_hp = 50;
            normal_damage = 4;
            normal_defense = 2;
        } else if (level == 4) {
            hp = 75;
            max_hp = 75;
            normal_damage = 4;
            normal_defense = 3;
        } else if (level == 5) {
            hp = 100;
            max_hp = 100;
            normal_damage = 5;
            normal_defense = 4;
        } else if (level == 6) {
            hp = 120;
            max_hp = 120;
            normal_damage = 6;
            normal_defense = 5;
        } else if (level == 7) {
            hp = 140;
            max_hp = 140;
            normal_damage = 8;
            normal_defense = 7;
        } else if (level == 8) {
            hp = 160;
            max_hp = 160;
            normal_damage = 10;
            normal_defense = 9;
        } else if (level == 9) {
            hp = 180;
            max_hp = 180;
            normal_damage = 15;
            normal_defense = 15;
        } else if (level == 10) {
            hp = 200;
            max_hp = 200;
            normal_damage = 20;
            normal_defense = 20;
        } else {
            hp = 200 + level;
            max_hp = 200 + level;
            normal_damage = 20 + (level / 2);
            normal_defense = 20 + (level / 2);
        }
        _lvl = false;
    }
}

void Player::useMagicBlock() {
    if (magicShieldUses > 0) {
        magicShieldActiv = true;
        magicShieldDuration = 1;
        magicShieldUses--;
        std::cout << "You activate Magic Block. Incoming damage will be reduced for this and the next round.\n";
    } else {
        std::cout << "You've exhausted all uses of Magic Block for this fight.\n";
    }
}

void Player::reduceMagicShieldDuration() {
    if (magicShieldDuration > 0) {
        magicShieldDuration--;
        if (magicShieldDuration == 0) {
            std::cout << "Magic Block wears off.\n";
            magicShieldActiv = false;
        }
    }
}

int Player::getMagicShieldDuration() {
    return magicShieldDuration;
}

int Player::getMagicShieldUses() {
    return magicShieldUses;
}

void Player::resetMagicShieldUses() {
    magicShieldUses = 1;
}

bool Player::equip(Item* _item) {
    if (_item->get_categorie() == 'S') {
        if (weapon_slot == "None") {
            weapon_slot = _item->get_name();
            weapon_damage = _item->getDamage();
            weapon_defense = _item->getDefense();
            weapon_durability = _item->get_durability();
            max_weapon_durability = _item->get_max_durability();
            weapon_price = _item->return_price();
            max_armor_price = _item->return_price();
            weapon_id = _item->get_id();
            return true;
        }
    }
    if (_item->get_categorie() == 'A') {
        if (armor_slot == "None") {
            armor_slot = _item->get_name();
            armor_damage = _item->getDamage();
            armor_defensiv = _item->getDefense();
            armor_durability = _item->get_durability();
            max_armor_durability = _item->get_max_durability();
            armor_price = _item->return_price();
            max_armor_price = _item->return_price();
            armor_id = _item->get_id();
            return true;
        }
    }
    return false;
}

void Player::reset_weapon() {
    weapon_damage = 0;
    weapon_defense = 0;
    weapon_durability = 0;
    max_weapon_durability = 0;
    weapon_slot = "None";
    weapon_id = 0;
}

void Player::reset_armor() {
    armor_defensiv = 0;
    armor_damage = 0;
    armor_durability = 0;
    max_armor_durability = 0;
    armor_slot = "None";
    armor_id = 0;
}

int Player::return_weaponID() {
    return weapon_id;
}

int Player::return_armorID() {
    return armor_id;
}

void Player::reset_durability(int _num) {
    if (_num == 1) {
        weapon_durability = max_weapon_durability;
    } else if (_num == 2) {
        armor_durability = max_armor_durability;
    }
    
}

void Player::reduce_weapon_durability() {
    if (weapon_slot != "None") {
        weapon_durability--;
        if (weapon_durability <= 0) {
            std::cout << "Your " << weapon_slot << " breaks apart." << std::endl;
            weapon_slot = "None";
            weapon_damage = 0;
            weapon_defense = 0;
            weapon_durability = 0;
            max_weapon_durability = 0;
        }
    }
}

void Player::reduce_armorn_durability() {
    if (armor_slot != "None") {
        armor_durability--;
        if (armor_durability <= 0) {
            std::cout << "Your " << armor_slot << " breaks apart." << std::endl;
            armor_slot = "None";
            armor_defensiv = 0;
            weapon_defense = 0;
            armor_durability = 0;
            max_armor_durability = 0;
        }
    }
}

Item* Player::unequipWeapon() {
        Item* sword = new Item(weapon_id, 'S', weapon_slot, weapon_damage, weapon_defense, weapon_durability, max_weapon_durability, weapon_price, max_weapon_price, 0);
        reset_weapon();
        return sword;
}

Item* Player::unequipArmor() {
        Item* armor = new Item(armor_id, 'A', armor_slot, armor_damage, armor_defensiv, armor_durability, max_armor_durability, armor_price, max_armor_price, 0);
        reset_armor();
        return armor;
}

void Player::clearFile() {
    std::ofstream file("saveGame.txt", std::ofstream::out | std::ofstream::trunc);
    file.close();
}

// IMPORT THIS INTO THE MAINFILE TO GET THE UPDATED PLAYER STATS
// NOW IT TAKES THE START STATS

/*void Player::saveGame() {
    std::ofstream file("saveGame.txt");

    if (file.is_open()) {
        file << name << std::endl;
        file << hp << " " << max_hp<< std::endl;
        file << level << " " << exp << std::endl;
        file << weapon_slot << std::endl;
        file << weapon_id << " " << weapon_price << " " << weapon_durability << " " << max_weapon_durability << std::endl;
        file << normal_damage << " " << weapon_damage << " " << armor_damage << std::endl;
        file << armor_slot << std::endl;
        file << armor_id << " " << armor_price<< " " << armor_durability << " " << max_armor_durability << std::endl;
        file << normal_defense << " " << armor_defensiv << " " << weapon_defense << std::endl;
        file << gold_amount << std::endl;
        file << magicShieldDuration << std::endl;
        file << magicShieldUses << std::endl;
        file << magicShieldActiv << std::endl;
        file << lifes << std::endl;

        file.close();
        std::cout << "Game saved successfully." << std::endl;
    } else {
        std::cerr << "Error: Unable to save game data to file." << std::endl;
    }
}

bool Player::loadGame() {
    std::ifstream file("saveGame.txt");

    if (file.is_open() && file.peek() != std::ifstream::traits_type::eof()) {
        file >> name;
        file >> hp >> max_hp;
        file >> level >> exp;
        file >> weapon_slot;
        file >> weapon_id >> weapon_price >> weapon_durability >> max_weapon_durability;
        file >> normal_damage >> weapon_damage >> armor_damage;
        file >> armor_slot;
        file >> armor_id >> armor_price >> armor_durability >> max_armor_durability;
        file >> normal_defense >> armor_defensiv >> weapon_defense;
        file >> gold_amount;
        file >> magicShieldDuration;
        file >> magicShieldUses;
        file >> magicShieldActiv;
        file >> lifes;

        file.close();
        std::cout << "Game loaded successfully." << std::endl;
        return true;
    } else {
        std::cerr << "Error: Unable to load game data from file." << std::endl;
        return false;
    }
}
*/
