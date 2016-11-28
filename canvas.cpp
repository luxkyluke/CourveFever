#include "canvas.h"
#include "game.h"

QPixmap Canvas::getPic()const{
    return pic;
}

Canvas::Canvas(const Game* g, QWidget *parent) :
    QWidget(parent),game (g),
    pic(g->getWidth(), g->getHeight()){

}

void Canvas::paintEvent(QPaintEvent *pe){
    //QWidget::paintEvent(pe);
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(Qt::NoPen);

    painter.translate(game->getWidth()/2, game->getHeight()/2);
    painter.scale(1, -1);
    game->draw(&painter);
    painter.end();

    //p.drawPicture(0,0,pic);
}
