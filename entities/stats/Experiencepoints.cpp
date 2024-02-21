#include <iostream>
#include <cmath>
#include "Experiencepoints.h"

int Experiencepoints::return_exp() {
    return exp;
}

void Experiencepoints::exp_drop(int amount, int level) {
    exp += round(amount);
}