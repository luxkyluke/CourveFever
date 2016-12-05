#ifndef BIGGERBONUS_H
#define BIGGERBONUS_H

#include "bonus.h"

class BiggerBonus: public Bonus{
public:
    BiggerBonus(QPointF pos);
    void apply()const;
};

#endif // BIGGERBONUS_H
