#include "spaceship.h"
#include"constants.h"
 #include<QPainter>

Spaceship::Spaceship(GameController &controller):
     controller(controller)
{
    setData(GD_Type,GO_Spaceship);
}
Spaceship::~Spaceship(){};
QRectF Spaceship::boundingRect() const
{
    return target;
}
void Spaceship::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall(":/project3/spaceship.png");
    target.setHeight(100);
    target.setWidth(200);
    painter->drawImage(target, wall);
    painter->restore();
}
void Spaceship::advance(int step)
{
    setPos(cor);
}
