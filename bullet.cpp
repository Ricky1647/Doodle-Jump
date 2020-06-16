#include "bullet.h"
#include<QPainter>
#include"constants.h"

Bullet::Bullet(GameController &controller):
    controller(controller)
{
    setData(GD_Type,GO_Bullet);
}
QRectF Bullet::boundingRect() const
{
    return target;
}
void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall(":/project3/bullet.png");
    target.setHeight(50);
    target.setWidth(35);
    painter->drawImage(target, wall);
    painter->restore();
}
void Bullet::advance(int step)
{
    dy-=0.2;
    cor.ry()+=dy;
    setPos(cor);
    if(y() < 0) {
        this->scene()->removeItem(this);    //只要include Scene 就可以使用scene
        delete this;
        prepareGeometryChange();
    }


}
