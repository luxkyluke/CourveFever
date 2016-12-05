#ifndef BONUS_H
#define BONUS_H

#include "circle.h"

class Bonus : public Circle {
private:
    static const float radius;

    //QPixmap logo;
    //int width, height;


public:
    Bonus();
    Bonus(QPointF pos);
    virtual void apply()const =0;

};

#endif // BONUS_H
