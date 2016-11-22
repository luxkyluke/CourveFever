#include "gameitem.h"

QPointF GameItem::getPosition() const{
    return position;
}

void GameItem::setPosition(const QPointF &value){
    position = value;
}
