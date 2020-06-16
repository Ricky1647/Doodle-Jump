#include "plat.h"
#include"constants.h"
#include<QPainter>
#include<time.h>
Plat::Plat(GameController &controller):
    controller(controller)
{
    srand(time(0));
    //setPos(x,y);
    setData(GD_Type, GO_Plat);
    //cor.rx()=x;
    //cor.ry()=y;
}
QRectF Plat::boundingRect() const
{
    return target;
}

void Plat::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall(":/project3/plat.png");
    target.setHeight(25);
    target.setWidth(75);
    painter->drawImage(target, wall);
    painter->restore();
}
void Plat::advance(int step)
{
    checkheight();
     setPos(cor);
}
void Plat::down()
{
    cor.ry()-=0.2;
}
void Plat::checkheight(){
   // QPointF scene_cor=mapFromScene(cor);
    if(cor.y()>633)
    {
        //cor.ry()=0;
        //cor.ry()+=20;
        //cor.ry()+=3;確認程式碼沒再進行
       // setPos(cor);
       /*
        controller.platchange();
        */
        cor.ry()=0;
        cor.rx()=rand()%500;
        //setPos(cor);
    }
}
