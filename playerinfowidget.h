#ifndef PLAYERINFOWIDGET_H
#define PLAYERINFOWIDGET_H

#include <QWidget>
#include<QLabel>
#include <QLCDNumber>
#include "player.h"

/**
 * @brief The PlayerInfoWidget class Widget use in a gamewindow
 * to show and update players'informations
 */
class PlayerInfoWidget : QWidget{
private :
    QLabel *color;
    QLabel *pseudo;
    QLabel *score;

public:
    explicit PlayerInfoWidget(Player *p, int w, int h, QWidget* parent=0);
    void setScore(int score);
    void win();
};

#endif // PLAYERINFOWIDGET_H
