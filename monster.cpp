#include "monster.h"
#include<QPainter>
#include"constants.h"
#include<time.h>
Monster::Monster(GameController &controller):
     controller(controller)
{
    time(0);
    setData(GD_Type,GO_Monster);
}
Monster::~Monster(){}
QRectF Monster::boundingRect() const
{
    return target;
}

void Monster::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall(":/project3/monster.png");
    target.setHeight(120);
    target.setWidth(80);
    painter->drawImage(target, wall);
    painter->restore();
}
void Monster::advance(int step)
{
    if(cor.ry()>633){
    cor.ry()=-300;
    cor.rx()=rand()%500;}
    dy+=0.5;
     if(dy>6)dy-=12;
     cor.ry()+=dy;
    setPos(cor);
    handleCollisions_Bullet();
     prepareGeometryChange();

     handleCollisions_Doodle();
}
void Monster::handleCollisions_Bullet(){
    QList<QGraphicsItem *> collisions = collidingItems(Qt::IntersectsItemShape);
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Bullet) {
            //controller.sansPushBox(this, (Box*)collidingItem);
            //controller.doodlehitplat(this,(Plat*)collidingItem);
                die();
                prepareGeometryChange();
                controller.bigheaddie();
        }
    }
}
void Monster::die()
{
    /*prepareGeometryChange();
    this->scene()->removeItem(this);
    prepareGeometryChange();
    //delete this;
    prepareGeometryChange();*/
    cor.rx()=-350;
    setPos(cor);
    //this->hide();
}
void Monster::handleCollisions_Doodle(){
    QList<QGraphicsItem *> collisions = collidingItems(Qt::IntersectsItemShape);
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Doodle) {
            controller.doodlehitmonster(this,(Player *)collidingItem);
        }
    }
}







