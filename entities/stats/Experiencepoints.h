#pragma once

class Experiencepoints {
public:
    int return_exp();
    void exp_drop(int, int);
    Experiencepoints(int _exp) : exp(_exp) {}
protected:
    int exp;
};