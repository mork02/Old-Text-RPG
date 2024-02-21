#pragma once

class Gold {
public:
    Gold(int _gold) : gold_amount(_gold) {}

    void gold_drop(int, int);
    void remove_gold(int);
    int return_gold() {return gold_amount;}
protected:
    int gold_amount;
};