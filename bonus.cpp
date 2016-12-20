#include "bonus.h"
#include "terrain.h"
#include <ctime>
#include <stdlib.h>

const float Bonus::radius=20.;
const QMap<bonusType, QColor> Bonus::bonusColorRelation = Bonus::createRelationMap();

Bonus::Bonus(){

}

Bonus::Bonus(int w, int h, bonusType type) : Circle(radius, Bonus::getRandPos(w, h), bonusColorRelation[type]){
//    srand(time(NULL));
}

QColor Bonus::getColor(){
    return Circle::getColor();
}

QPointF Bonus::getRandPos(int w, int h){
    int x = rand() %w;
    int y = rand() %h;
    QPoint p = QPoint(x, y);
    QPointF pos = Terrain::getCoordInLandmarkDim(p, w, h);
    return pos;
}

bool Bonus::isBonusColor(QColor c){
    return c == Bonus::bonusColorRelation[GOOD]
            || c == Bonus::bonusColorRelation[BAD]
            || c == Bonus::bonusColorRelation[COMMUN];
}

bonusType Bonus::getType(QColor c){
    return Bonus::bonusColorRelation.key(c);
}

