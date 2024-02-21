#pragma once

class Health {
public: 
    Health(int _hp, int _max_hp) : hp(_hp), max_hp(_max_hp) {}

    
    void heal(int);
    void take_damage(int amount, int defense);
    void heal_max();
    int return_hp();
    int return_max_hp();
    void check_health();

protected:
    int hp, max_hp;
};