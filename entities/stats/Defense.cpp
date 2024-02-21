#include "Defense.h"

int Defense::return_defense() {
    return normal_defense + armor_defensiv + (weapon_defense);
}