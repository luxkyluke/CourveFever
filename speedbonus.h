#ifndef SPEEDBONUS_H
#define SPEEDBONUS_H

#include "bonus.h"

class SpeedBonus : public Bonus{
public:
    SpeedBonus(int w, int h);
    void apply(Player *p);
    void cancel();
};

#endif // SPEEDBONUS_H
