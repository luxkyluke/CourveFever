#ifndef BONUS_H
#define BONUS_H

#include <QObject>
#include "circle.h"

class Bonus : public Circle/*, QObject*/ {
private:
    //Q_OBJECT
    static const float radius;

    //QPixmap logo;
    //int width, height;
protected:
    QTimer* timer;

public:
    Bonus();
    Bonus(QPointF pos);
    virtual void apply()const =0;

};

#endif // BONUS_H
