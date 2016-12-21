#ifndef BIGGERBONUS_H
#define BIGGERBONUS_H

#include "bonus.h"

class BiggerBonus: public Bonus{
public:
    BiggerBonus(int w, int h);
    void apply(Player *p);
    void cancel();
};

#endif // BIGGERBONUS_H
