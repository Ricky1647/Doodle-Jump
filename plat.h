#ifndef PLAT_H
#define PLAT_H
#include <QGraphicsItem>
#include"gamecontroller.h"
class GameController;
class Player;

class Plat:public QGraphicsItem
{
public:
    Plat(GameController &controller);
    QRectF boundingRect() const;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
    QPointF cor;

     void down();
protected:
    void checkheight();
    GameController &controller;
    QRectF target;
    void advance(int step);
};

#endif // PLAT_H
