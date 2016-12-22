#ifndef CLEANBONUS_H
#define CLEANBONUS_H

#include "bonus.h"

class CleanBonus : public Bonus{
public:
    CleanBonus(int w, int h);
    void apply(Player *p=0);
    void cancel();
};

#endif // CLEANBONUS_H
