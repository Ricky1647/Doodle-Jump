#include "weapon.h"
#include"constants.h"
 #include<QPainter>

Weapon::Weapon(GameController &controller):
    controller(controller)
{
     setData(GD_Type,GO_Weapon);
}
Weapon::~Weapon(){};
QRectF Weapon::boundingRect() const
{
    return target;
}
void Weapon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall(":/project3/weapon.png");
    target.setHeight(50);
    target.setWidth(75);
    painter->drawImage(target, wall);
    painter->restore();
}
void Weapon::advance(int step)
{
    setPos(cor);
}

