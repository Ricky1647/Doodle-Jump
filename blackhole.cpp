#include "blackhole.h"
#include"constants.h"
 #include<QPainter>

Blackhole::Blackhole(GameController &controller):
        controller(controller)
{
    setData(GD_Type,GO_BlackHole);
}
Blackhole::~Blackhole(){};
QRectF Blackhole::boundingRect() const
{
    return target;
}
void Blackhole::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall(":/project3/hole.png");
    target.setHeight(50);
    target.setWidth(75);
    painter->drawImage(target, wall);
    painter->restore();
}
void Blackhole::advance(int step)
{
    setPos(cor);
}
