#include "piclabel.h"
#include "game.h"

PicLabel::PicLabel(QWidget * parent = 0) :
    QLabel(parent){}

PicLabel::PicLabel(Game *g, QString & text, QWidget * parent = 0) :
    QLabel(text, parent), game(g) {}

void PicLabel::paintEvent(QPaintEvent * event) Q_DECL_OVERRIDE {
  QLabel::paintEvent(event);
  QPainter p(this);
  QPainter painter;
  painter.begin(this);
  painter.translate(width()/2, height()/2);
  painter.scale(1, -1);
  game->draw(&painter, *this);
  painter.end();
  p.drawPicture(0, 0, m_picture);
}

