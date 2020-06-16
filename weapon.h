#ifndef WEAPON_H
#define WEAPON_H
#include <QGraphicsItem>
#include"gamecontroller.h"

class Weapon:public QGraphicsItem
{
public:
    Weapon(GameController &controller);
    ~Weapon();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
    QPointF cor;
protected:
     GameController &controller;
     QRectF target;
     void advance(int step);
};

#endif // WEAPON_H
