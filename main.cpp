#include <iostream>
#include <limits>
#include <conio.h>
#define NOMINMAX 1
#include <windows.h>
#include <random>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "inventory/Inventory.h"
#include "entities/Player.h"
#include "entities/NPC_list.h"
#include "entities/Smith.h"

void clear_screen() {
    system("cls");
}

void slow_print(const std::string& str) {
    for (size_t i = 0; i != str.size(); ++i) { 
        std::cout << str[i];
        Sleep(1);
    }
}

void pressEnterToContinue() {
    std::cin.clear();
    std::cout << "\033[4mPress Enter to Continue\033[0m";
    std::cin.get();
}

void clearIgnore() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize> :: max(), '\n');
}

void displayStartScreen(int selectedOption) {
    clear_screen();
    std::cout << "Welcome to my Text RPG!\n\033[4mWhat do you want to do?\033[0m\n\n";
    std::cout << (selectedOption == 1 ? "> "  : "  ") << "Start Game\n";
    std::cout << (selectedOption == 2 ? "> "  : "  ") << "Load Game\n";
    std::cout << (selectedOption == 3 ? "> "  : "  ") << "Quit\n";
}

void displayTownScreen(int selectedOption) {
    clear_screen();
    std::cout << "\033[4mWhere do you want to Travel?\033[0m\n\n";
    std::cout << (selectedOption == 1 ? "> "  : "  ") << "Select Area\n";
    std::cout << (selectedOption == 2 ? "> "  : "  ") << "Go to the Healer\n";
    std::cout << (selectedOption == 3 ? "> "  : "  ") << "Go to the Smith\n";
    std::cout << (selectedOption == 4 ? "> "  : "  ") << "Open Inventory\n";
    std::cout << (selectedOption == 5 ? "> "  : "  ") << "Show Stats\n";
    std::cout << (selectedOption == 6 ? "> "  : "  ") << "Open Settings\n";
}

void displayAreaScreen(int selectedOption) {
    clear_screen();
    std::cout << "\033[4mChoose Area:\033[0m\n\n";
    std::cout << (selectedOption == 1 ? "> "  : "  ") << "Forest Clearing (Required level 1)\n";
    std::cout << (selectedOption == 2 ? "> "  : "  ") << "Abandoned Mine (Required level 4)\n";
    std::cout << (selectedOption == 3 ? "> "  : "  ") << "Mountain Pass (Required level 7)\n";
    std::cout << (selectedOption == 4 ? "> "  : "  ") << "END OF WORLD (Required level 10)\n";
    std::cout << (selectedOption == 5 ? "> "  : "  ") << "Back to Town\n";
}

void displayFightScreen(int selectedOption, NPC mob, Player user, int game_difficulty) {
    clear_screen();
    mob.show_info_infight(game_difficulty);
    std::cout << "+------------------------------------------+" << std::endl;
    user.show_info_infight();
    std::cout << (selectedOption == 1 ? "> "  : "  ") << "Attack\n";
    std::cout << (selectedOption == 2 ? "> "  : "  ") << "Magic Shield\n";
    std::cout << (selectedOption == 3 ? "> "  : "  ") << "Inventory\n";
    std::cout << (selectedOption == 4 ? "> "  : "  ") << "Run\n";
}

void displayHealerScreen(int selectedOption, Player user) {
    clear_screen();
    std::cout << "ika:\nOh you again... do you want me to heal you?\n\033[4mNIt will cost you " << user.healing_cost() << " Gold\033[0m \n(Gold: " << user.return_gold() << ")\n\n";
    std::cout << (selectedOption == 1 ? "> "  : "  ") << "Yes\n";
    std::cout << (selectedOption == 2 ? "> "  : "  ") << "No\n";
}

void displaySmithScreen(int selectedOption) {
    clear_screen();
    std::cout << "Olli:\nHello my friend!\n\033[4mWhat do we want to forge together?\033[0m\n\n";
    std::cout << (selectedOption == 1 ? "> "  : "  ") << "Forge Equipment\n";
    std::cout << (selectedOption == 2 ? "> "  : "  ") << "Repair Equipment\n";
    std::cout << (selectedOption == 3 ? "> "  : "  ") << "Upgrade Equipment\n";
    std::cout << (selectedOption == 4 ? "> "  : "  ") << "Sell Equipment\n";
    std::cout << (selectedOption == 5 ? "> "  : "  ") << "Open Inventory\n"; 
    std::cout << (selectedOption == 6 ? "> "  : "  ") << "Go back to Town\n";
}

void displaySmithForgeScreen(int selectedOption) {
    clear_screen();
    std::cout << "Olli:\n\033[4mWhat Equipment do you want to Forge?\033[0m\n\n";
    std::cout << (selectedOption == 1 ? "> "  : "  ") << "Forge Weapon\n";
    std::cout << (selectedOption == 2 ? "> "  : "  ") << "Forge Armor\n";
    std::cout << (selectedOption == 3 ? "> "  : "  ") << "Back\n";
}

void displaySmithRepairScreen(int selectedOption, Player user) {
    clear_screen();
    std::cout << "Olli:\n\033[4mWhat Equipment do you want to Repair?\033[0m\n\n";
    user.show_equipment();
    std::cout << user.return_username() << "'s Gold: " << user.return_gold() << std::endl;
    std::cout << "\nWeapon repair cost: " << user.forge_cost(1) << "\nArmor repair cost: " << user.forge_cost(2) << std::endl; 
    std::cout << (selectedOption == 1 ? "> "  : "  ") << "Repair Weapon\n";
    std::cout << (selectedOption == 2 ? "> "  : "  ") << "Repair Armor\n";
    std::cout << (selectedOption == 3 ? "> "  : "  ") << "Back\n";
}

void displayInventoryScreen(int selectedOption, Player user, Inventory inv) {
    clear_screen();
    user.show_equipment();
    std::cout << "\033[4mInventory:\033[0m \n\n";
    inv.displayItems();
    std::cout << (selectedOption == 1 ? "> "  : "  ") << "Equip\n";
    std::cout << (selectedOption == 2 ? "> "  : "  ") << "unEquip\n";
    std::cout << (selectedOption == 3 ? "> "  : "  ") << "Remove\n";
    std::cout << (selectedOption == 4 ? "> "  : "  ") << "Back\n";

}

void displayInventoryUnequipScreen(int selectedOption, Player user) {
    clear_screen();
    user.show_equipment();
    std::cout << "\033[4mWhat item do you want to unEquip?\033[0m\n\n";
    std::cout << (selectedOption == 1 ? "> "  : "  ") << "unEquip Weapon\n";
    std::cout << (selectedOption == 2 ? "> "  : "  ") << "unEquip Armor\n";
    std::cout << (selectedOption == 3 ? "> "  : "  ") << "Back\n";

}

void displaySettingsScreen(int selectedOption) {
    clear_screen();
    std::cout << "\033[4mSettings:\033[0m\n\n";
    std::cout << (selectedOption == 1 ? "> "  : "  ") << "Change Username\n";
    std::cout << (selectedOption == 2 ? "> "  : "  ") << "Change Difficulty\n";
    std::cout << (selectedOption == 3 ? "> "  : "  ") << "Save Game\n";
    std::cout << (selectedOption == 4 ? "> "  : "  ") << "Back\n";

}

void displaySettingsDiffucultyScreen(int selectedOption) {
    clear_screen();
    std::cout << "\033[4mSet Difficulty:\033[0m\n\n";
    std::cout << (selectedOption == 1 ? "> "  : "  ") << "Easy\n";
    std::cout << (selectedOption == 2 ? "> "  : "  ") << "Normal\n";
    std::cout << (selectedOption == 3 ? "> "  : "  ") << "Hard\n";

}

int main() {
    srand(time(NULL));
    int selectedOption = 1;
    char key;

    Player user;
    Smith smith;
    Inventory inventory;
    NPC mob(0, "None", 0, 0, 0, 0, 0, 0, 0, 0, {});
    std::vector forest_clearing = getforest_vec();
    std::vector abandoned_mine = getmine_vec();
    std::vector mountain_pass = getmountain_vec();
    std::vector endofworld = getendofworld_vec();
    bool start_screen = true;
    bool prolog = false;
    bool in_town = false;
    bool first_time_healer = true;
    bool first_time_smith = true;
    bool chooce_area = false;
    bool fighting = false;
    int exp_drop;
    int gold_drop;
    int random_number;
    // 1 = Easy, 2 = Normal, 3 = Hard
    int game_difficulty = 2;
    int rand_damage;
    int choice;

    inventory.addItem(new Item(0, 'S', "DEV SWORD", 999, 999, 999, 999, 999, 999, 999));

    // Start screen
    while (start_screen) {
        do {
            displayStartScreen(selectedOption);

            key = _getch();

            switch (key) {
            case 72:
                selectedOption = (selectedOption > 1) ? selectedOption - 1 : 3;
                break;
            case 80:
                selectedOption = (selectedOption < 3) ? selectedOption + 1 : 1;
                break;
            case 27:
                return 0;
            }
        } while (key != 13);
        // Start game
        if (selectedOption  == 1) {
            start_screen = false;
            prolog = true;
            clear_screen();
            clear_screen(); slow_print(". "); Sleep(500); slow_print(". "); Sleep(500); slow_print(". "); Sleep(500); clear_screen();
            Sleep(1500);
        // Load game
        } else if (selectedOption  == 2) {
           // bool x = user.loadGame();
            // if (x) {
                start_screen = false;
                in_town = true;
                first_time_healer = false;
                first_time_smith = false;
            // }
            pressEnterToContinue();
        // Quit
        } else if (selectedOption  == 3) {
            return 0;
        } 
    }

    // prolog
    while (prolog) {
        clear_screen();
        slow_print("In the vast expanse of the wilderness, where the sun kisses the treetops and the wind whispers ancient secrets, a lone adventurer trudged through the dense forest.\nClad in worn leather armor that bore the scars of countless battles, he journeyed with a sense of purpose yet unsure of his destination.\n");
        slow_print("As he ventured deeper into the woods, the shadows grew longer, and the path became obscured by the thick foliage. Lost in thought and direction, \nthe adventurer stumbled upon a clearing where a Rusty Iron Sword lay embedded in the earth, its hilt beckoning to him like an old friend.\n");
        pressEnterToContinue();
        clear_screen();
        slow_print("Just then, a voice resonated from the shadows, breaking the serene atmosphere. 'Halt there, traveler,' it called, 'Before you proceed, I must know your name. What do they call you, brave soul?'\n");
        slow_print("Startled, the adventurer turned to face the source of the voice, a figure shrouded in mystery.\n");
        user.set_username();
        clear_screen();
        slow_print("'I am "); slow_print(user.return_username()); slow_print("! My purpose is clear: to seek destiny amidst these ancient trees.'\n");
        slow_print("With a knowing nod, the mysterious figure faded into the shadows, leaving the adventurer to ponder his encounter.\nGrasping the rusty sword with newfound resolve, he pressed on, the rhythmic sound of his footsteps echoing through the silent forest. \nAnd as the canopy parted ways, revealing the distant silhouette of a bustling town on the horizon, a spark of anticipation ignited within his soul.\n");
        slow_print("With newfound purpose and a Iron Sword at his side, the adventurer set forth towards the welcoming lights of the town,\nready to embark on a new chapter of his journey, where destiny awaited and tales of valor awaited to be written.\n");
        prolog = false;
        in_town = true;
        pressEnterToContinue();
    }

    // in town loop
    while (in_town) {
        selectedOption = 1;
        do {
            displayTownScreen(selectedOption);

            key = _getch();

            switch (key) {
            case 72:
                selectedOption = (selectedOption > 1) ? selectedOption - 1 : 6;
                break;
            case 80:
                selectedOption = (selectedOption < 6) ? selectedOption + 1 : 1;
                break;
            case 27:
                return 0;
            }
        } while (key != 13);  
        if (selectedOption == 1) {
            // Area
            selectedOption = 1;
            chooce_area = true;
            while (chooce_area) {
            do {
                displayAreaScreen(selectedOption);

                key = _getch();

                switch (key) {
                case 72:
                    selectedOption = (selectedOption > 1) ? selectedOption - 1 : 5;
                    break;
                case 80:
                    selectedOption = (selectedOption < 5) ? selectedOption + 1 : 1;
                    break;
                case 27:
                    return 0;
                }
            } while (key != 13); 
            int userlevel = user.return_lvl();
            // Forest Clearing
            if (selectedOption == 1) {
                if (userlevel >= 1) {
                    if (userlevel == 1) {
                        random_number = rand() % (forest_clearing.size() - 8);
                    } else if (userlevel > 2) {
                        random_number = rand() % forest_clearing.size();
                    } else {
                        random_number = rand() % (forest_clearing.size() - 3);
                    }
                    mob = forest_clearing[random_number];
                    chooce_area = false;
                    fighting = true;
                }

            // Abandoned Mine
            } else if (selectedOption == 2) {
                if (userlevel >= 4) {
                    if (userlevel > 5) {
                        random_number = rand() % abandoned_mine.size();
                    } else {
                        random_number = rand() % (abandoned_mine.size() - 3);
                    }
                    random_number = rand() % abandoned_mine.size();
                    mob = abandoned_mine[random_number];
                    chooce_area = false;
                    fighting = true;
                } else {
                    clear_screen();
                    slow_print("Silent voice:\nYour Level is too low for Abandoned Mine.\nThe Area is too Dangerous for you to enter!\nYou need to be Level 4 to go to the Abandoned Mine.\n");
                    pressEnterToContinue();
                    
                }

            // Mountain Pass
            } else if (selectedOption == 3) {
                if (userlevel >= 7) {
                    if (userlevel == 10) {
                        random_number = mountain_pass.size() - 1;
                    } else if (userlevel >= 8) {
                        random_number = rand() % mountain_pass.size();
                    } else {
                        random_number = rand() % (mountain_pass.size() - 4);
                    }
                    mob = mountain_pass[random_number];
                    chooce_area = false;
                    fighting = true;
                } else {
                    clear_screen();
                    slow_print("Silent voice:\nYour Level is too low for Mountain Pass.\nThe Area is too Dangerous for you to enter!\nYou need to be Level 7 to go to the Mountain Pass.\n");
                    pressEnterToContinue();
                    
                }

            // END OF WORLD
            } else if (selectedOption == 4) {
                if (userlevel >= 11) {
                    random_number = rand() % endofworld.size();
                    fighting = true;
                    chooce_area = false;
                } else {
                    clear_screen();
                    slow_print("Silent voice:\nYour Level is too low for END OF WORLD.\nThe Area is too Dangerous for you to enter!\nYou need to be Level 10 to go to the END OF WORLD.\n");
                    pressEnterToContinue();
                    
                }

            // back to town
            } else if (selectedOption == 5) {
                chooce_area = false;
                break;
                }
            }
            if (fighting) {
                clear_screen();
                slow_print(mob.return_name()); slow_print(" (Lv. "); std::cout << mob.return_lvl() << ")"; slow_print(" appears!\n");
                Sleep(1000);
                while (fighting) {
                    selectedOption = 1;
                    do {
                    displayFightScreen(selectedOption, mob, user, game_difficulty);

                    key = _getch();

                    switch (key) {
                    case 72:
                        selectedOption = (selectedOption > 1) ? selectedOption - 1 : 4;
                        break;
                    case 80:
                        selectedOption = (selectedOption < 4) ? selectedOption + 1 : 1;
                        break;
                    case 27:
                        return 0;
                    }
                    } while (key != 13);  

                    if (game_difficulty == 1) {
                        // easy
                        rand_damage = round((static_cast<double>(mob.return_damage()) / 1.5) / 2 + rand() % (static_cast<int>((mob.return_damage() / 1.5) - mob.return_damage() / 2 + 1))) + round(sqrt(user.return_defense()));
                    } else if (game_difficulty == 2) {
                        // normal
                        rand_damage = round((mob.return_damage() / 2) + rand() % (mob.return_damage() - (mob.return_damage() / 2) + 1)) + round(sqrt(user.return_defense()));
                    } else if (game_difficulty == 3 ) {
                        // hard
                        rand_damage = round((static_cast<double>(mob.return_damage()) * 1.5) / 2 + rand() % (static_cast<int>((mob.return_damage() * 1.5) - mob.return_damage() / 2 + 1))) + round(sqrt(user.return_defense()));
                    } if (selectedOption == 1) {
                        // ATTACK
                        clear_screen();
                        // crit hit
                        int crit = rand() % 100 + 1;
                        int miss = rand() / 100 + 1;
                        if (miss <= 5) {
                            std::cout << user.return_username() << " misses the Attck\n";
                        } else {
                            if (crit <= 10) {
                                if ((user.return_damage() * 2) <= mob.return_defense() && user.return_hp() > 0 && mob.return_hp() > 0) {
                                    user.reduce_weapon_durability();
                                    mob.take_damage(1, 0);
                                    slow_print("CRIT! | "); std::cout << "-1"; slow_print(" on "); slow_print(mob.return_name()); std::cout << std::endl;
                                } else if ((user.return_damage() * 2) > mob.return_defense() && user.return_hp() > 0 && mob.return_hp() > 0) {
                                    mob.take_damage((user.return_damage() * 2) + round(sqrt(mob.return_defense()) / 2), mob.return_defense());
                                    user.reduce_weapon_durability();
                                    slow_print("CRIT! | "); std::cout << (user.return_damage() * 2) + round(sqrt(mob.return_defense()) / 2) - mob.return_defense(); slow_print(" on "); slow_print(mob.return_name()); std::cout << std::endl;
                                }
                            // no crit hit
                            } else {
                                if (user.return_damage() <= mob.return_defense() && user.return_hp() > 0 && mob.return_hp() > 0) {
                                    user.reduce_weapon_durability();
                                    mob.take_damage(1, 0);
                                    std::cout << "-1"; slow_print(" on "); slow_print(mob.return_name()); std::cout << std::endl;
                                } else if (user.return_damage() > mob.return_defense() && user.return_hp() > 0 && mob.return_hp() > 0) {
                                    mob.take_damage(user.return_damage() + round(sqrt(mob.return_defense()) / 2), mob.return_defense());
                                    user.reduce_weapon_durability();
                                    slow_print("-"); std::cout << user.return_damage() + round(sqrt(mob.return_defense()) / 2) - mob.return_defense(); slow_print(" on "); slow_print(mob.return_name()); std::cout << std::endl;
                                }
                            }
                        }
                        std::cout << "+----" << std::endl;
                        miss = rand() % 100 + 1;
                        if (miss <= 10 && mob.return_hp() > 0) {
                            std::cout << mob.return_name() << " misses the Attck\n";
                            Sleep(1500);
                        } else {
                            if (!user.getMagicShieldActiv()) {
                                if (user.return_defense() >= rand_damage && mob.return_hp() > 0 && user.getMagicShieldDuration() <= 0) {
                                    user.take_damage(1, 0);
                                    slow_print("-1 DMG on "); slow_print(user.return_username()); std::cout << std::endl;
                                    user.reduce_armorn_durability();
                                    Sleep(1500);
                                } else if (user.return_defense() < rand_damage && mob.return_hp() > 0 && user.getMagicShieldDuration() <= 0) {
                                    slow_print("-"); std::cout << rand_damage - user.return_defense(); slow_print(" on "); slow_print(user.return_username()); std::cout << std::endl;
                                    user.take_damage(rand_damage, user.return_defense());
                                    user.reduce_armorn_durability();
                                    Sleep(1500);
                                } 
                            } else {
                                int damage = (rand_damage / 2);
                                if (user.return_defense() < damage && mob.return_hp() > 0) {
                                    user.take_damage(damage, user.return_defense());
                                    slow_print("(reduced by Magic Block) | "); std::cout << (damage - user.return_defense()); slow_print(" on "); slow_print(user.return_username()); std::cout << std::endl;
                                    user.reduce_armorn_durability();
                                    user.reduceMagicShieldDuration();
                                    Sleep(1500);
                                } else if (user.return_defense() >= damage && mob.return_hp() > 0) {
                                    slow_print("(reduced by Magic Block) | -1 DMG on "); slow_print(user.return_username()); std::cout << std::endl;
                                    user.take_damage(1, 0);
                                    user.reduce_armorn_durability();
                                    user.reduceMagicShieldDuration();
                                    Sleep(1500);
                                }
                            }
                        }
                        if (user.return_hp() <= 0) {
                            // User dead
                            clear_screen(); slow_print(". "); Sleep(500); slow_print(". "); Sleep(500); slow_print(". "); Sleep(500); clear_screen();
                            bool dead = user.check_lifes();
                            if (dead) {
                                user.resetMagicShieldUses();
                                fighting = false;
                                pressEnterToContinue();
                            } else {
                                return 0;
                            }

                        } if (mob.return_hp() <= 0) {

                            // Mob dead
                            if (game_difficulty == 1) {
                                // easy
                                if (mob.return_area_id() == 1 && user.return_lvl() >= 4) {
                                    exp_drop = round((mob.return_exp() / 1.5) / 2); 
                                    gold_drop = round((mob.return_gold() / 1.5) / 2); 
                                } else if (mob.return_area_id() == 2 && user.return_lvl() >= 7) {
                                    exp_drop = round((mob.return_exp() / 1.5) / 2); 
                                    gold_drop = round((mob.return_gold() / 1.5) / 2); 
                                } else if (mob.return_area_id() == 3 && user.return_lvl() >= 9) {
                                    exp_drop = round((mob.return_exp() / 1.5) / 2); 
                                    gold_drop = round((mob.return_gold() / 1.5) / 2); 
                                } else {
                                    exp_drop = round((mob.return_exp() / 1.5)); 
                                    gold_drop = round((mob.return_gold() / 1.5)); 
                                }
                            } if (game_difficulty == 2) {
                                // normal
                                if (mob.return_area_id() == 1 && user.return_lvl() >= 4) {
                                    exp_drop = round(mob.return_exp() / 2); 
                                    gold_drop = round(mob.return_gold() / 2); 
                                } else if (mob.return_area_id() == 2 && user.return_lvl() >= 7) {
                                    exp_drop = round(mob.return_exp() / 2); 
                                    gold_drop = round(mob.return_gold() / 2); 
                                } else if (mob.return_area_id() == 3 && user.return_lvl() >= 9) {
                                    exp_drop = round(mob.return_exp() / 2); 
                                    gold_drop = round(mob.return_gold() / 2); 
                                } else {
                                    exp_drop = mob.return_exp(); 
                                    gold_drop = mob.return_gold(); 
                                }

                            } if (game_difficulty == 3 ) {
                                // hard
                                if (mob.return_area_id() == 1 && user.return_lvl() >= 4) {
                                    exp_drop = round((mob.return_exp() * 2) / 2); 
                                    gold_drop = round((mob.return_gold() * 2) / 2);
                                } else if (mob.return_area_id() == 2 && user.return_lvl() >= 7) {
                                    exp_drop = round((mob.return_exp() * 2) / 2); 
                                    gold_drop = round((mob.return_gold() * 2) / 2);
                                } else if (mob.return_area_id() == 3 && user.return_lvl() >= 9) {
                                    exp_drop = round((mob.return_exp() * 2) / 2); 
                                    gold_drop = round((mob.return_gold() * 2) / 2);
                                } else {
                                    exp_drop = round((mob.return_exp() * 2)); 
                                    gold_drop = round((mob.return_gold() * 2));
                                }
                            }
                            clear_screen();
                            user.exp_drop(exp_drop, user.return_lvl());
                            user.gold_drop(gold_drop, user.return_lvl());
                            std::cout << user.return_username() << " killed " << mob.return_name() << " and receives +" << exp_drop << " EXP and +" << gold_drop << " Gold!\n\n";
                            if (inventory.getInventorySize() >= 15) {
                                slow_print("Your Inventory is full. Cant drop anything.");
                            } else {
                                // Mob item drop
                                for (Item& i : mob.return_itemDrops()) {
                                    Item itemDropped = mob.dropRandomItem(i.return_itemDropChance());
                                    if (itemDropped.return_itemDropChance()) {
                                        std::cout << "'"<< i.get_name() << "' is added to your Inventory!" << std::endl;
                                        if (i.get_categorie() == 'S') {
                                            std::cout << "ID: " <<i.get_id() << " | " << i.get_name() << " (DMG: " << i.getDamage() << " - Defense: " << i.getDefense() << " - DURA: " << i.get_durability() << ")" << std::endl;
                                            inventory.addItem(new Item(i));
                                        } else if (i.get_categorie() == 'A') {
                                            std::cout << "ID: " <<i.get_id() << " | " << i.get_name() << " (DEF: " << i.getDefense() << " - Damage: " << i.getDamage() << " - DURA: " << i.get_durability() << ")" << std::endl;
                                            inventory.addItem(new Item(i));
                                        }
                                    }
                                }
                            }
                            bool check_lvl = user.checkEXP();
                            user.check_lvlup(check_lvl);
                            std::cout << "\n+------------------------------------------+" << std::endl;
                            std::cout << user.return_username() << ":" << std::endl;
                            std::cout << user.return_hp() << " / " << user.return_max_hp() << std::endl;
                            std::cout << "lvl. " << user.return_lvl() << std::endl;
                            std::cout << "EXP: " << user.return_exp() << " / " << user.calculateExpForLevel() << std::endl;
                            std::cout << "+------------------------------------------+" << std::endl;
                            pressEnterToContinue();
                            user.resetMagicShieldUses();
                            fighting = false;
                        }
                    } else if (selectedOption == 2) {
                        // BLOCK
                        clear_screen();
                        user.useMagicBlock();
                        slow_print("Your Magic Block has been activated!\n");
                        if (user.return_defense() < rand_damage && mob.return_hp() > 0 && user.getMagicShieldDuration() > 0) {
                            int damage = (rand_damage / 2);
                            user.take_damage(damage, user.return_defense());
                            if (damage <= user.return_defense()) {
                                slow_print("(reduced by Magic Block) | -1 DMG on "); slow_print(user.return_username()); std::cout << std::endl;
                                user.take_damage(1, 0);
                                user.reduce_armorn_durability();
                            } else {
                                slow_print("(reduced by Magic Block) | "); std::cout << (damage - user.return_defense()); slow_print(" on "); slow_print(user.return_username()); std::cout << std::endl;
                                user.take_damage(damage, user.return_defense());
                                user.reduce_armorn_durability();
                            }
                            Sleep(1500);
                        }

                    } else if (selectedOption == 3) {
                        // Inventory
                        while (true) {
                        selectedOption = 1;
                            do {
                                displayInventoryScreen(selectedOption, user, inventory);

                                key = _getch();

                                switch (key) {
                                case 72:
                                    selectedOption = (selectedOption > 1) ? selectedOption - 1 : 4;
                                    break;
                                case 80:
                                    selectedOption = (selectedOption < 4) ? selectedOption + 1 : 1;
                                    break;
                                case 27:
                                    return 0;
                                }
                            } while (key != 13);  
                            if (selectedOption == 1) {
                                clear_screen();
                                user.show_equipment();
                                std::cout << "\033[4mEquip:\033[0m \n\n";
                                inventory.displayItems();
                                int eq;
                                std::cout << "What item do you want to Equip?\n(Input 'b' to go back)\nID > ";
                                std::cin >> eq;
                                if (std::cin.fail()) {
                                    clearIgnore();
                                } else {
                                    Item* item = inventory.getinventoryItem(eq);
                                    if (item) {
                                        if (item->get_categorie() == 'S' && user.return_weapon_slot() != "None") {
                                            Item* weapon = user.unequipWeapon();
                                            user.equip(inventory.getinventoryItem(eq));   
                                            inventory.remove_item(eq);
                                            inventory.addItem(weapon);
                                        } else if (item->get_categorie() == 'S' && user.return_weapon_slot() == "None") {
                                            user.equip(inventory.getinventoryItem(eq));   
                                            inventory.remove_item(eq);
                                        }
                                        if (item->get_categorie() == 'A' && user.return_armor_slot() != "None") {
                                            Item* armor = user.unequipArmor();
                                            user.equip(inventory.getinventoryItem(eq));   
                                            inventory.remove_item(eq);
                                            inventory.addItem(armor);
                                        } else if (item->get_categorie() == 'A' && user.return_armor_slot() == "None") {
                                            user.equip(inventory.getinventoryItem(eq));   
                                            inventory.remove_item(eq);
                                        }
                                    }
                                }
                            } else if (selectedOption == 2) {
                                // unequip
                                selectedOption = 1;
                                do {
                                    user.show_equipment();
                                    displayInventoryUnequipScreen(selectedOption, user);

                                    key = _getch();

                                    switch (key) {
                                    case 72:
                                        selectedOption = (selectedOption > 1) ? selectedOption - 1 : 3;
                                        break;
                                    case 80:
                                        selectedOption = (selectedOption < 3) ? selectedOption + 1 : 1;
                                        break;
                                    case 27:
                                        return 0;
                                }
                            } while (key != 13);  
                                if (selectedOption == 1) {
                                    if (user.return_weapon_slot() != "None") {
                                        Item* weapon = user.unequipWeapon();
                                        inventory.addItem(weapon);
                                    }
                                } else if (selectedOption == 2) {
                                    if (user.return_armor_slot() != "None") {
                                        Item* armor = user.unequipArmor();
                                        inventory.addItem(armor);
                                    }
                                } else if (selectedOption == 3) {
                                    continue;
                                }
                            } else if (selectedOption == 3) {
                                // remove
                                clear_screen();
                                user.show_equipment();
                                std::cout << "\033[4munEquip:\033[0m \n\n";
                                inventory.displayItems();
                                int rm;
                                std::cout << "What item do you want to remove?\n(Input 'b' to go back)\nID > ";
                                std::cin >> rm;
                                if (std::cin.fail()) {
                                    clearIgnore();
                                } else {
                                    inventory.remove_item(rm);
                                }
                            } else if (selectedOption == 4) {
                                break;
                            }
                        }
                    } else if (selectedOption == 4) {
                        // RUN
                        clear_screen();
                        int chance = rand() % 100 + 1;
                        if (chance <= mob.return_run_chance()) {
                            slow_print("you ran away...\n");
                            Sleep(1500);
                            user.resetMagicShieldUses();
                            fighting = false;
                        } else {
                            clear_screen();
                            slow_print(user.return_username()); slow_print(" failed to run.\n");
                            std::cout << "+------------------------------------------+" << std::endl;
                            if (user.return_defense() >= mob.return_damage() && mob.return_hp() > 0) {
                                slow_print(mob.return_name()); slow_print(" doesn't do enough DMG...\n"); slow_print("1 dmg on "); slow_print(user.return_username());
                                user.take_damage(1, 0);
                                user.reduce_armorn_durability();
                                pressEnterToContinue();
                            } else if (user.return_defense() < mob.return_damage() && mob.return_hp() > 0) {
                                    slow_print(user.return_username()); slow_print(" got hit by "); std::cout << mob.return_damage() - user.return_defense(); slow_print(" DMG\n");
                                    user.reduce_armorn_durability();
                                    user.take_damage(mob.return_damage(), user.return_defense());
                                    pressEnterToContinue();
                            }
                            if (user.return_hp() <= 0) {
                                // User dead
                                clear_screen(); slow_print(". "); Sleep(500); slow_print(". "); Sleep(500); slow_print(". "); Sleep(500); clear_screen();
                                bool dead = user.check_lifes();
                                if (dead) {
                                    user.resetMagicShieldUses();
                                    fighting = false;
                                    pressEnterToContinue();
                                } else {
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        } else if (selectedOption == 2) {
            // Healer
            selectedOption = 1;
            while (true) {
                if (first_time_healer) {
                    clear_screen();
                    slow_print("Nika:\nI am the healer Nika.\nI care for the injured adventurers and am popular for my healing skills. I've never seen you before...\nI can heal you for free for the first time, but the next few times it won't be cheap for you!\n");
                    slow_print("Nika healed you!\n");
                    user.heal_max();
                    first_time_healer = false;
                    pressEnterToContinue();
                    break;
                } else {
                    do {
                        displayHealerScreen(selectedOption, user);

                        key = _getch();

                        switch (key) {
                        case 72:
                            selectedOption = (selectedOption > 1) ? selectedOption - 1 : 2;
                            break;
                        case 80:
                            selectedOption = (selectedOption < 2) ? selectedOption + 1 : 1;
                            break;
                        case 27:
                            return 0;
                        }
                    } while (key != 13);

                    if (selectedOption == 1 && user.return_gold() >= user.healing_cost() && user.return_hp() < user.return_max_hp()) {
                        clear_screen();
                        user.heal_max();
                        user.remove_gold(user.healing_cost());
                        slow_print("Nika healed you!\n");
                        pressEnterToContinue();
                        break;
                    } else if (selectedOption == 1 && user.return_hp() >= user.return_max_hp()) {
                        clear_screen();
                        slow_print("Nika:\nYou already have full HP. Go away...\n");
                        pressEnterToContinue();
                        break;
                    } else if (selectedOption == 1 && user.return_gold() < user.healing_cost()) {
                        clear_screen();
                        slow_print("Nika:\nYou dont have enough money... Get lost!\n");
                        pressEnterToContinue();
                        break;
                    } else if (selectedOption == 2) {
                        clear_screen();
                        slow_print("Nika:\nGet lost.\n");
                        pressEnterToContinue();
                        break;
                    }
                }
            }
        } else if (selectedOption == 3) {
            // Smith
            selectedOption = 1;
            clear_screen();
            if (first_time_smith) {
                slow_print("Olli:\nWelcome, weary traveler, to the humble forge of Olli the Smith! I am Olli, keeper of the flames and forger of dreams. What brings you to my humble abode?\nFear not, for within these walls, your desires shall take shape in the dance of hammer and anvil.\nSo, step forth and let us forge a tale of valor and steel together!\n");
                pressEnterToContinue();
                first_time_smith = false;
            }
            while (true) {
                selectedOption = 1;
                do {
                    displaySmithScreen(selectedOption);

                    key = _getch();

                    switch (key) {
                    case 72:
                        selectedOption = (selectedOption > 1) ? selectedOption - 1 : 6;
                        break;
                    case 80:
                        selectedOption = (selectedOption < 6) ? selectedOption + 1 : 1;
                        break;
                    case 27:
                        return 0;
                    }
                } while (key != 13);
                if (selectedOption == 2) {
                    // repair
                    selectedOption = 1;
                    do {
                        displaySmithRepairScreen(selectedOption, user);

                        key = _getch();

                        switch (key) {
                        case 72:
                            selectedOption = (selectedOption > 1) ? selectedOption - 1 : 3;
                            break;
                        case 80:
                            selectedOption = (selectedOption < 3) ? selectedOption + 1 : 1;
                            break;
                        case 27:
                            return 0;
                        }
                    } while (key != 13);
                    if (selectedOption == 1) {
                        clear_screen();
                        if (user.return_weapon_slot() != "None" && user.return_gold() >= user.forge_cost(1) && user.return_Weapondurability() < user.return_MaxWeapondurability()) {
                            user.remove_gold(user.forge_cost(1));
                            user.reset_durability(1);
                            slow_print(user.return_weapon_slot()); slow_print(" repaired!\n");
                            pressEnterToContinue();
                        } else if (user.return_weapon_slot() == "None") {
                            slow_print("Olli:\nYou dont even got any weapon on you...?\n");
                            pressEnterToContinue();
                        } else if (user.return_Weapondurability() >= user.return_MaxWeapondurability()) {
                            slow_print("Olli:\nYour weapon looks fine for me! It dont need to get repaired.\n");
                            pressEnterToContinue();
                        } else if (user.return_gold() < user.forge_cost(1)) {
                            slow_print("Olli:\nSorry buddy, you dont have enough gold to pay me...\n");
                            pressEnterToContinue();
                        }
                        clear_screen();
                    } if (selectedOption == 2) {
                        clear_screen();
                        if (user.return_armor_slot() != "None" && user.return_gold() >= user.forge_cost(2) && user.return_Armordurability() < user.return_MaxArmordurability()) {
                            user.remove_gold(user.forge_cost(2));
                            user.reset_durability(2);
                            slow_print(user.return_armor_slot()); slow_print(" repaired!\n");
                            pressEnterToContinue();
                        } else if (user.return_armor_slot() == "None") {
                            slow_print("Olli:\nYou dont even got any weapon on you...?\n");
                            pressEnterToContinue();
                        } else if (user.return_Armordurability() >= user.return_MaxArmordurability()) {
                            slow_print("Olli:\nYour weapon looks fine for me! It dont need to get repaired.\n");
                            pressEnterToContinue();
                        } else if (user.return_gold() < user.forge_cost(2)) {
                            slow_print("Olli:\nSorry buddy, you dont have enough gold to pay me...\n");
                            pressEnterToContinue();
                        } 
                        clear_screen();
                    } if (selectedOption == 3) {
                        clear_screen();
                        continue;
                    }          

                } else if (selectedOption == 1) {
                    selectedOption = 1;
                    while (true) {
                        if (inventory.getInventorySize() >= 15) {
                            clear_screen();
                            slow_print("Olli:\nYour Inventory is full... Sell or Throw something away!\n");
                            pressEnterToContinue();
                            break;
                        } else {
                            do {
                                displaySmithForgeScreen(selectedOption);

                                key = _getch();

                                switch (key) {
                                case 72:
                                    selectedOption = (selectedOption > 1) ? selectedOption - 1 : 3;
                                    break;
                                case 80:
                                    selectedOption = (selectedOption < 3) ? selectedOption + 1 : 1;
                                    break;
                                case 27:
                                    return 0;
                                }
                            } while (key != 13);
                            smith.clearShop();
                            if (selectedOption == 1) {
                                clear_screen();
                                int beq;
                                smith.openWeaponShop(user.return_lvl());
                                std::cout << "What item do you want to buy?\n" << "(Gold: " << user.return_gold() << ")\n" << "(Input 'b' to go back)\nID > ";
                                std::cin >> beq;
                                if (std::cin.fail()) {
                                    clearIgnore();  
                                }
                                Item* item = smith.buyWeaponItem(beq);
                                if (item) {
                                    if (item && user.return_gold() >= item->return_price()) {
                                        clear_screen();
                                        user.remove_gold(smith.craftCost(item));
                                        inventory.addItem(item);
                                        std::cout << "You bought " << item->get_name() << " for " << item->return_price() << " Gold." << std::endl;
                                        Sleep(2000);
                                    } else if (user.return_gold() < item->return_price()) {
                                        clear_screen();
                                        slow_print("You dont have enough Gold... Come back if you have more Gold!\n");
                                        Sleep(2000);  
                                    }
                                }
                            } else if (selectedOption == 2) {
                                clear_screen();
                                smith.clearShop();
                                int beq;
                                smith.openArmorShop(user.return_lvl());
                                std::cout << "What item do you want to buy?\n" << "(Gold: " << user.return_gold() << ")\n" << "(Input 'b' to go back)\nID > ";
                                std::cin >> beq;
                                if (std::cin.fail()) {
                                    clearIgnore();
                                }
                                Item* item = smith.buyArmorItem(beq);
                                if (item) {
                                    if (item && user.return_gold() >= item->return_price()) {
                                        clear_screen();
                                        user.remove_gold(smith.craftCost(item));
                                        inventory.addItem(item);
                                        std::cout << "You bought " << item->get_name() << " for " << item->return_price() << " Gold." << std::endl;
                                        Sleep(2000);
                                    } else if (user.return_gold() < item->return_price()) {
                                        clear_screen();
                                        slow_print("You dont have enough Gold... Come back if you have more Gold!\n");
                                        Sleep(2000); 
                                    } 
                                }
                            } else if (selectedOption == 3) {
                                break;
                            } 
                        }
                    }
                
                } else if (selectedOption == 4) {
                        // sell
                        selectedOption = 1;
                        clear_screen();
                        std::cout << "What equipment do you want to sell?\n";
                        inventory.displaySellItems();
                        std::cout << "(Input 'b' to go back)\nID > ";
                        std::cin >> choice;
                        if (std::cin.fail()) {
                            clearIgnore();
                        } else {
                            Item* item = inventory.getinventoryItem(choice);
                            clear_screen();
                            if (item) {
                                slow_print("You got +"); std::cout << item->return_price(); slow_print(" Gold!\n");
                                user.gold_drop(item->return_price(), 0);
                                inventory.remove_item(choice);
                                Sleep(2000);
                            } else {
                                slow_print("You dont have this Item in your Inventory.");
                                pressEnterToContinue();
                            }
                        }
                        clear_screen();
                } else if (selectedOption == 6) {
                    //back to town
                    break;
                } else if (selectedOption == 3) {
                    // upgrade
                    selectedOption = 1;
                    clear_screen();
                    std::cout << "What equipment do you want to Upgrade?\n" << user.return_username() << "'s Gold: " << user.return_gold() << ".\n";
                    inventory.displayMergeItems();
                    std::cout << "(Input 'b' to go back)\nID > ";
                    std::cin >> choice;
                    if (std::cin.fail()) {
                        clearIgnore();
                    } else {
                        Item* item = inventory.getinventoryItem(choice);
                        if (item) {
                            if (user.return_gold() >= item->return_upgrade_price()) {
                                clear_screen();
                                std::cout << "You payed " << item->return_upgrade_price() << " Gold to Upgrade " << item->get_name() << "!" << std::endl;
                                std::cout << item->get_name() << "'s DMG +" <<  round(cbrt(item->getDamage() * 2)) << " and " << item->get_name() << "'s DEF +" << round(cbrt(item->getDefense() * 2)) << std::endl;
                                Item* mergedItem = smith.mergeItem(item);
                                inventory.remove_item(choice);
                                inventory.addItem(mergedItem);
                                user.remove_gold(item->return_upgrade_price());
                                Sleep(3000);

                            } else {
                                clear_screen();
                                slow_print("Olli:\nYou dont have enough Gold... Come back later!\n");
                                Sleep(1500);
                            }
                        } else {
                            slow_print("You dont have this Item in your Inventory.");
                            Sleep(1500);
                        }
                    }
                    clear_screen();
                } else if (selectedOption == 5) {
                    //Smith Open Inventory
                    while (true) {
                    selectedOption = 1;
                        do {
                            displayInventoryScreen(selectedOption, user, inventory);

                            key = _getch();

                            switch (key) {
                            case 72:
                                selectedOption = (selectedOption > 1) ? selectedOption - 1 : 4;
                                break;
                            case 80:
                                selectedOption = (selectedOption < 4) ? selectedOption + 1 : 1;
                                break;
                            case 27:
                                return 0;
                            }
                        } while (key != 13);  
                        if (selectedOption == 1) {
                            // equip
                            clear_screen();
                            user.show_equipment();
                            std::cout << "\033[4mEquip:\033[0m \n\n";
                            inventory.displayItems();
                            int eq;
                            std::cout << "What item do you want to Equip?\n(Input 'b' to go back)\nID > ";
                            std::cin >> eq;
                            if (std::cin.fail()) {
                                clearIgnore();
                            } else {
                                Item* item = inventory.getinventoryItem(eq);
                                if (item) {
                                    if (item->get_categorie() == 'S' && user.return_weapon_slot() != "None") {
                                        Item* weapon = user.unequipWeapon();
                                        user.equip(inventory.getinventoryItem(eq));   
                                        inventory.remove_item(eq);
                                        inventory.addItem(weapon);
                                    } else if (item->get_categorie() == 'S' && user.return_weapon_slot() == "None") {
                                        user.equip(inventory.getinventoryItem(eq));   
                                        inventory.remove_item(eq);
                                    }
                                    if (item->get_categorie() == 'A' && user.return_armor_slot() != "None") {
                                        Item* armor = user.unequipArmor();
                                        user.equip(inventory.getinventoryItem(eq));   
                                        inventory.remove_item(eq);
                                        inventory.addItem(armor);
                                    } else if (item->get_categorie() == 'A' && user.return_armor_slot() == "None") {
                                        user.equip(inventory.getinventoryItem(eq));   
                                        inventory.remove_item(eq);
                                    } else {
                                        clearIgnore();
                                    }
                                }
                            }
                        } else if (selectedOption == 2) {
                            // unequip
                            selectedOption = 1;
                            do {
                                user.show_equipment();
                                displayInventoryUnequipScreen(selectedOption, user);

                                key = _getch();

                                switch (key) {
                                case 72:
                                    selectedOption = (selectedOption > 1) ? selectedOption - 1 : 3;
                                    break;
                                case 80:
                                    selectedOption = (selectedOption < 3) ? selectedOption + 1 : 1;
                                    break;
                                case 27:
                                    return 0;
                            }
                        } while (key != 13);  
                            if (selectedOption == 1) {
                                if (user.return_weapon_slot() != "None") {
                                    Item* weapon = user.unequipWeapon();
                                    inventory.addItem(weapon);
                                }
                            } else if (selectedOption == 2) {
                                if (user.return_armor_slot() != "None") {
                                    Item* armor = user.unequipArmor();
                                    inventory.addItem(armor);
                                }
                            } else if (selectedOption == 3) {
                                continue;
                            }
                        } else if (selectedOption == 3) {
                            // unequip
                            clear_screen();
                            user.show_equipment();
                            std::cout << "\033[4mEquip:\033[0m \n\n";
                            inventory.displayItems();
                            int rm;
                            std::cout << "What item do you want to remove?\n(Input 'b' to go back)\nID > ";
                            std::cin >> rm;
                            if (std::cin.fail()) {
                                clearIgnore();
                            } else {
                                inventory.remove_item(rm);
                            }
                        } else if (selectedOption == 4) {
                            break;
                        }
                    }
                }
            }
        } else if (selectedOption == 4) {
            // Inventory
            while (true) {
            selectedOption = 1;
                do {
                    displayInventoryScreen(selectedOption, user, inventory);

                    key = _getch();

                    switch (key) {
                    case 72:
                        selectedOption = (selectedOption > 1) ? selectedOption - 1 : 4;
                        break;
                    case 80:
                        selectedOption = (selectedOption < 4) ? selectedOption + 1 : 1;
                        break;
                    case 27:
                        return 0;
                    }
                } while (key != 13);  
                if (selectedOption == 1) {
                    // equip
                    clear_screen();
                    user.show_equipment();
                    std::cout << "\033[4mEquip:\033[0m \n\n";
                    inventory.displayItems();
                    int eq;
                    std::cout << "What item do you want to Equip?\n(Input 'b' to go back)\nID > ";
                    std::cin >> eq;
                    if (std::cin.fail()) {
                        clearIgnore();
                    } else {
                        Item* item = inventory.getinventoryItem(eq);
                        if (item) {
                            if (item->get_categorie() == 'S' && user.return_weapon_slot() != "None") {
                                Item* weapon = user.unequipWeapon();
                                user.equip(inventory.getinventoryItem(eq));   
                                inventory.remove_item(eq);
                                inventory.addItem(weapon);
                            } else if (item->get_categorie() == 'S' && user.return_weapon_slot() == "None") {
                                user.equip(inventory.getinventoryItem(eq));   
                                inventory.remove_item(eq);
                            }
                            if (item->get_categorie() == 'A' && user.return_armor_slot() != "None") {
                                Item* armor = user.unequipArmor();
                                user.equip(inventory.getinventoryItem(eq));   
                                inventory.remove_item(eq);
                                inventory.addItem(armor);
                            } else if (item->get_categorie() == 'A' && user.return_armor_slot() == "None") {
                                user.equip(inventory.getinventoryItem(eq));   
                                inventory.remove_item(eq);
                            } else {
                                clearIgnore();
                            }
                        }
                    }
                } else if (selectedOption == 2) {
                    // unequip
                    selectedOption = 1;
                    do {
                        user.show_equipment();
                        displayInventoryUnequipScreen(selectedOption, user);

                        key = _getch();

                        switch (key) {
                        case 72:
                            selectedOption = (selectedOption > 1) ? selectedOption - 1 : 3;
                            break;
                        case 80:
                            selectedOption = (selectedOption < 3) ? selectedOption + 1 : 1;
                            break;
                        case 27:
                            return 0;
                    }
                } while (key != 13);  
                    if (selectedOption == 1) {
                        if (user.return_weapon_slot() != "None") {
                            Item* weapon = user.unequipWeapon();
                            inventory.addItem(weapon);
                        }
                    } else if (selectedOption == 2) {
                        if (user.return_armor_slot() != "None") {
                            Item* armor = user.unequipArmor();
                            inventory.addItem(armor);
                        }
                    } else if (selectedOption == 3) {
                        continue;
                    }
                } else if (selectedOption == 3) {
                    // unequip
                    clear_screen();
                    user.show_equipment();
                    std::cout << "\033[4mEquip:\033[0m \n\n";
                    inventory.displayItems();
                    int rm;
                    std::cout << "What item do you want to remove?\n(Input 'b' to go back)\nID > ";
                    std::cin >> rm;
                    if (std::cin.fail()) {
                        clearIgnore();
                    } else {
                        inventory.remove_item(rm);
                    }
                } else if (selectedOption == 4) {
                    break;
                }
            }
        } else if (selectedOption == 5) {
            // Stats
            clear_screen();
            user.show_all();
            pressEnterToContinue();
        } else if (selectedOption == 6) {
            // Settings
            while (true) {
            selectedOption = 1;
                do {
                    displaySettingsScreen(selectedOption);

                    key = _getch();

                    switch (key) {
                    case 72:
                        selectedOption = (selectedOption > 1) ? selectedOption - 1 : 4;
                        break;
                    case 80:
                        selectedOption = (selectedOption < 4) ? selectedOption + 1 : 1;
                        break;
                    case 27:
                        return 0;
                    }
                } while (key != 13);  
                if (selectedOption == 1) {
                    clear_screen();
                    user.set_username();
                } else if (selectedOption == 2) {
                    while (true) {
                        selectedOption = 2;
                        do {
                            displaySettingsDiffucultyScreen(selectedOption);

                            key = _getch();

                            switch (key) {
                            case 72:
                                selectedOption = (selectedOption > 1) ? selectedOption - 1 : 3;
                                break;
                            case 80:
                                selectedOption = (selectedOption < 3) ? selectedOption + 1 : 1;
                                break;
                            case 27:
                                return 0;
                            }
                        } while (key != 13);  
                        if (selectedOption == 1) {
                            game_difficulty = 1;
                            break;
                        } else if (selectedOption == 2) {
                            game_difficulty = 2;
                            break;
                        } else if (selectedOption == 3) {
                            game_difficulty = 3;
                            break;
                        } else {
                            continue;
                        }
                    }
                } else if (selectedOption == 3) {
                    user.clearFile();
                    // user.saveGame();
                    pressEnterToContinue(); 
                } else if (selectedOption == 4) {
                    break;
                }
            }
        }
    }
    return 0;
}

// 2286 Lines of code