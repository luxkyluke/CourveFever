#ifndef BONUS_H
#define BONUS_H

#include <QObject>
#include <QMap>
#include "circle.h"


enum bonusType{GOOD, BAD, COMMUN};

class Bonus : public Circle {
private:
    static const float radius;
    static const QMap<bonusType, QColor> createRelationMap(){
        QMap<bonusType, QColor> map;
        map[GOOD] = QColor("#34C924");
        map[BAD] = QColor("#850606");
        map[COMMUN] = QColor("#318CE7");
        return map;
    }
    static const QMap<bonusType, QColor> bonusColorRelation;

    //QPixmap logo;
    //int width, height;
protected:
    QTimer* timer;

public:
    Bonus();
    Bonus(int w, int h, QColor color);
    virtual void apply()const =0;
    static bool isBonusColor(QColor c);
    static bonusType getType(QColor c);

};

#endif // BONUS_H
