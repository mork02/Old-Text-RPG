#pragma once

class Damage{
public:
    int return_damage() { return normal_damage + weapon_damage + armor_damage; }

    Damage(int _normal_damage, int _weapon_damage, int _armor_daamge) : normal_damage(_normal_damage), weapon_damage(_weapon_damage), armor_damage(_armor_daamge) {}
protected:
    int normal_damage, weapon_damage, (armor_damage);
};