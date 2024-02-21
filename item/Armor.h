#pragma once
#include <iostream>

class Armor {
public:
    Armor(int _defensiv) : defensiv(_defensiv) {}
    int getDefense() const { return defensiv; }
protected:
    int defensiv;
};