#pragma once

class Defense {
public:
    int return_defense() { return normal_defense + armor_defensiv + weapon_defense; }

    Defense(int _normal_defense, int _armor_defesiv, int _weapon_defense) : normal_defense(_normal_defense), armor_defensiv(_armor_defesiv), weapon_defense(_weapon_defense) {}
protected:
    int normal_defense, armor_defensiv, weapon_defense;
};