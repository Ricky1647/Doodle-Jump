#include "plat_poly.h"
#include<QPainter>

Plat_poly::Plat_poly(GameController &controller):
    Plat(controller)
{

}
void Plat_poly::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)//使用畫畫
{
    painter->save();
    QImage wall(":/project3/plat_2.png");
    target.setHeight(25);
    target.setWidth(75);
    painter->drawImage(target, wall);
    painter->restore();
}
void Plat_poly::advance(int step){
    dx+=0.1;
    if(dx>6)dx-=12;
    cor.rx()+=dx;
    setPos(cor);
}
