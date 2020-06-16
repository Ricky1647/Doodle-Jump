#include "coin.h"
#include"constants.h"
 #include<QPainter>
Coin::Coin(GameController &controller):
     controller(controller)
{
    setData(GD_Type,GO_Coin);
}
Coin::~Coin(){};
QRectF Coin::boundingRect() const
{
    return target;
}
void Coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    QImage wall(":/project3/coin.png");
    target.setHeight(50);
    target.setWidth(75);
    painter->drawImage(target, wall);
    painter->restore();

}
void Coin::advance(int step)
{
    setPos(cor);
    handleCollisions_Doodle();
}
void Coin::handleCollisions_Doodle(){
    QList<QGraphicsItem *> collisions = collidingItems(Qt::IntersectsItemShape);
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Doodle) {
                get();
                controller.doodlegetcoin();
        }
        else if(collidingItem->data(GD_Type) == GO_Rick)
        {
            get();
            controller.doodlegetcoin();
        }
        else if(collidingItem->data(GD_Type) == GO_Spaceship)
        {
            get();
            controller.doodlegetcoin();
        }
    }
}
void Coin::get(){
    cor.rx()=-250;
    setPos(cor);
}
