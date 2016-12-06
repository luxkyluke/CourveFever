#include "biggerbonus.h"

static const QColor COLOR(255, 0, 0, 255);

BiggerBonus::BiggerBonus(int w, int h) : Bonus(w, h, COLOR){

//    timer = new QTimer(this);
//    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
//    timer->start(FRAME_DURATION);
}

void BiggerBonus::apply() const{

}
