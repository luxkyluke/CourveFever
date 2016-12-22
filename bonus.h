#ifndef BONUS_H
#define BONUS_H

#include <QObject>
#include <QMap>
#include <time.h>
#include "circle.h"
#include "player.h"

/**
 * @brief The bonusType enum
 * GOOD : It's bonus you take to improve your skils
 * BAD : It's bonus you take to destabilize your opponents
 * COMMUN : It's bonus which be applied for everyone
 */
enum bonusType{GOOD, BAD, COMMUN};

class Bonus : public Circle {
private:
    static const float radius;
    //which type has his pricise color
    static const QMap<bonusType, QColor> createRelationMap(){
        QMap<bonusType, QColor> map;
        map[GOOD] = QColor("#34C924");
        map[BAD] = QColor("#850606");
        map[COMMUN] = QColor("#318CE7");
        return map;
    }
    static const QMap<bonusType, QColor> bonusColorRelation;
    bool inAction, erased;
    bonusType type;

protected:
    clock_t timer;
    static const int duration;
    Player *player;             //to apply and cancel bonus effects
    void setPlayer(Player* p);
    void setTimer(int t);
    void action();
    void stop();

public:
    Bonus();
    Bonus(int w, int h, bonusType type);
    QColor getColor();
    virtual bonusType getType();
    bool isInAction() const;
    void erase();
    bool isErased() const;
    virtual ~Bonus();

    /**
     * @brief apply bonus effect on player p
     * @param p
     */
    virtual void apply(Player*p=0) =0;

    /**
     * @brief cancel bonus effect
     */
    virtual void cancel() =0;

    /**
     * @brief checkTimeout : check if bonus duration is over
     */
    void checkTimeout();

    /**
     * @brief isBonusColor : check if the color is the same as the one of
     *  the bonus
     * @param c
     * @return
     */
    static bool isBonusColor(QColor c);

    /**
     * @brief getType : return the bonusType corresponding to the color c
     * @param c
     * @return
     */
    static bonusType getType(QColor c);



    /**
     * @brief getRandPos : give a random position on the range defined by
     * a width and height
     * @param w
     * @param h
     * @return
     */
    static QPointF getRandPos(int w, int h);
};

#endif // BONUS_H
