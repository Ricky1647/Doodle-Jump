#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QGraphicsItem>
#include"gamecontroller.h"

class Spaceship:public  QGraphicsItem
{
public:
    Spaceship(GameController &controller);
    ~Spaceship();
    QRectF boundingRect() const;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
      QPointF cor;
protected:
     GameController &controller;
     QRectF target;
     void advance(int step);
};

#endif // SPACESHIP_H
