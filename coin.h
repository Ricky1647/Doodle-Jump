#ifndef COIN_H
#define COIN_H
#include <QGraphicsItem>
#include"gamecontroller.h"

class Coin:public QGraphicsItem
{
public:
    Coin(GameController &controller);
    ~Coin();
     QRectF boundingRect() const;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
     QPointF cor;
     void handleCollisions_Doodle();
     void get();
protected:
     GameController &controller;
     QRectF target;
     void advance(int step);
};

#endif // COIN_H
