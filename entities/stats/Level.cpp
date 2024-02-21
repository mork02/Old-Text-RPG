#include <iostream> 
#include "Level.h"

int Level::calculateExpForLevel() {
    if (level == 1) {
        return level * 50;
    } else {
        return level * 60;
    }
}

bool Level::checkEXP() {
    int calc_lvl = calculateExpForLevel();
    while (exp >= calc_lvl) {
        exp -= calc_lvl;
        ++level;
        calc_lvl = calculateExpForLevel();
        if (exp < calc_lvl) {
            return true; 
        }
    }
    return false;
}

int Level::return_lvl() {
    return level;
}