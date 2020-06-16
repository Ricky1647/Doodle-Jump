#ifndef BLACKHOLE_H
#define BLACKHOLE_H
#include <QGraphicsItem>
#include"gamecontroller.h"

class Blackhole:public QGraphicsItem
{
public:
    Blackhole(GameController &controller);
    ~Blackhole();
    QRectF boundingRect() const;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
     QPointF cor;
protected:
     GameController &controller;
     QRectF target;
     void advance(int step);
};

#endif // BLACKHOLE_H
