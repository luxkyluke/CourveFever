#ifndef BONUS_H
#define BONUS_H

#include <QObject>
#include <QMap>
#include <time.h>
#include "circle.h"
#include "player.h"


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
    bool inAction, erased;

    //QPixmap logo;
    //int width, height;
protected:
    clock_t timer;
    static const int duration;
    Player *player;
    void setPlayer(Player* p);
    void setTimer(int t);
    void action();
    void stop();

public:
    Bonus();
    Bonus(int w, int h, bonusType type);
    QColor getColor();
    virtual void apply(Player*p) =0;
    virtual void cancel() =0;
    void checkTimeout();
    static bool isBonusColor(QColor c);
    static bonusType getType(QColor c);
    static QPointF getRandPos(int w, int h);
    bool isInAction() const;
    void erase();
    bool isErased() const;
    virtual ~Bonus();
};

#endif // BONUS_H
