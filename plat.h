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
    //下面這個函數要override
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
    QPointF cor;

     void down();
protected:
    void checkheight();
    GameController &controller;
    QRectF target;
    //下面這個函數要override
    virtual void advance(int step);
};

#endif // PLAT_H
