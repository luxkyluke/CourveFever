#include "playerinfowidget.h"

const static int WIDTH_COLOR_BOX = 25;

playerInfoWidget::playerInfoWidget(int w, int h, QWidget *parent) : QWidget(parent){
    this->resize(w, h);
    playerColor = new QLabel("color");
    playerColor->resize(WIDTH_COLOR_BOX, WIDTH_COLOR_BOX);

}
