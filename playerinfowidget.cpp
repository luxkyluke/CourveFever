#include "playerinfowidget.h"
#include <iostream>
#include <sstream>
#include <string>

const static int WIDTH_COLOR_BOX = 25;

QString intToQString(int a){
    ostringstream convert;
    convert<< a;
    std::string s = convert.str();
    return QString::fromStdString(s);
}

PlayerInfoWidget::PlayerInfoWidget(Player* p, int w, int h, QWidget *parent) : QWidget(parent){

    //init color
    color = new QLabel(this);
//    QPalette pal = color->palette();
//    pal.setColor(color->backgroundRole(), p->getColor());
//    color->setPalette(pal);
    QString c = p->getColor().name();
    color->setStyleSheet("QLabel { background-color :"+c+"}");
    color->setGeometry(QRect(10, h, WIDTH_COLOR_BOX, WIDTH_COLOR_BOX));

    //init pseudo
    pseudo = new QLabel(p->getPseudo(), this);
    pseudo->setGeometry(QRect(50, h, 100, 30));


    score= new QLabel(intToQString(p->getScore()), this);
    score->setGeometry(QRect(240, h, 15, 30));
    score->setStyleSheet("QLabel {font-size:20px;}");
}


void PlayerInfoWidget::setScore(int _score){
    score->setText(intToQString(_score));
}
