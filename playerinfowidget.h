#ifndef PLAYERINFOWIDGET_H
#define PLAYERINFOWIDGET_H

#include <QWidget>
#include<QLabel>
#include <QLCDNumber>
#include "player.h"


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
