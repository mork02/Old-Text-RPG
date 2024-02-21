#pragma once
#include "Experiencepoints.h"

class Level : public Experiencepoints {
public:
    Level(int _lvl, int _exp) : level(_lvl), Experiencepoints(_exp) {}
    int calculateExpForLevel();
    bool checkEXP();
    int return_lvl();


protected:
    int level;
};
