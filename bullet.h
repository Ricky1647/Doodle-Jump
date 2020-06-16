#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include"gamecontroller.h"
#include <QGraphicsScene>
class GameController;
class Player;

class Bullet:public QGraphicsItem
{
public:
    Bullet(GameController &controller);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
     QPointF cor;
protected:
    GameController &controller;
    QRectF target;
    void advance(int step);
private:
    float dy=0;
};

#endif // BULLET_H
