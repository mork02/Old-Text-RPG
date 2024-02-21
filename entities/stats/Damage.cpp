#include "Damage.h"

int Damage::return_damage() {
    return normal_damage + weapon_damage + armor_damage;
}