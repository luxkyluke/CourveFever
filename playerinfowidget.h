#ifndef PLAYERINFOWIDGET_H
#define PLAYERINFOWIDGET_H

#include <QWidget>
#include<QLabel>


class playerInfoWidget : QWidget{
private :
    QLabel *playerColor;
    QLabel *playerPseudo;
    QLabel *playerScore;

public:
    explicit playerInfoWidget(int w, int h, QWidget* parent=0);
};

#endif // PLAYERINFOWIDGET_H
