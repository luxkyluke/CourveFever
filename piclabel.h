#ifndef PICLABEL_H
#define PICLABEL_H

#include <QPicture>
#include <QLabel>
#include <iostream>


class Game;

class PicLabel : public QLabel {
  QPicture m_picture;
  Game * game;

public:
  PicLabel(Game *g, QString & text, QWidget * parent = 0);

  PicLabel(QWidget * parent = 0);

//  void addPoint(const QPointF & point) {
//    QPainter p(&m_picture);
//    p.drawPoint(point);
//    update();
//  }

  void addLine(const QPointF & start, const QPointF & end) {
    QPainter p(&m_picture);
    p.drawLine(start, end);
    update();
  }

  void clear() {
    //std::swap(m_picture, QPicture());
    update();
  }

protected:
  void paintEvent(QPaintEvent * event) Q_DECL_OVERRIDE ;
};

#endif // PICLABEL_H
