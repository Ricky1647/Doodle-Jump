#ifndef MONSTER_H
#define MONSTER_H
#include <QGraphicsItem>
#include"gamecontroller.h"
#include<QGraphicsScene>
class GameController;
class Player;

class Monster:public QGraphicsItem
{
public:
    Monster(GameController &controller);
    ~Monster();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
    QPointF cor;
    void handleCollisions_Bullet();
    void handleCollisions_Doodle();
protected:
     GameController &controller;
     QRectF target;
     void advance(int step);
     void die();
private:
     float dy=0;
};

#endif // MONSTER_H
