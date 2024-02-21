#include "Health.h"

void Health::heal(int amount) {
    hp += amount;
    if (hp > max_hp) {
        hp = max_hp;
    }
}

void Health::take_damage(int amount, int defense) {
    if (amount <= defense) {
        hp -= 1;
    } else {
        hp -= (amount - defense);} 
    if (hp <= 0) {
        hp = 0;
    }
}

void Health::heal_max() {
    hp = max_hp;
}

int Health::return_hp() {
    return hp;
}

int Health::return_max_hp() {
    return max_hp;
}

void Health::check_health() {
    if (hp <= 0) {
        hp = 0;
    }
    if (hp > max_hp) {
        hp = max_hp;
    }
}