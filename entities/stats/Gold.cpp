#include "Gold.h"
#include <cmath>

void Gold::gold_drop(int amount, int level) {
    gold_amount += round(amount);
}

void Gold::remove_gold(int amount) {
    gold_amount -= amount;
}