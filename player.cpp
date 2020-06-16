#include "player.h"
#include "gamecontroller.h"
#include<QPainter>
#include"constants.h"
QString duck=":/project3/doodle.png";
double step1;

Player::Player(GameController &controller):
    //cor(50,300), //2:57加這一行
    controller(controller)
{
    setData(GD_Type,GO_Doodle);
}
QRectF Player::boundingRect() const
{
    return QRectF(50,300,100, 80);
}
void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->drawImage(QRectF(50,300,100,80), QImage(duck));
    //painter->drawPixmap(100,80,QPixmap("C:/project3/rick.png"));
    painter->restore();
}
/*void Player::paint2( )
{
    QPainter *painter;
    painter->save();
    painter->drawImage(QRectF(cor.rx(),cor.ry(),100,80), QImage("C:/project3/rick.png"));
    painter->restore();
}*/
void Player::moveLeft( ){
    cor.rx() -=30;
    if(cor.rx()<-150)
        cor.rx()=350;
}
void Player::moveRight(){
    cor.rx() += 30;
    if(cor.rx()>350)
        cor.rx()=-150;
}
void Player::advance(int step)
{
    dy+=0.2;
    if(dy>6)dy-=6;
    cor.ry()+=dy;
    if(dy<0){}
    else
    {handleCollisions_plat();}
    handleCollisions_weapon();
    handleCollisions_spaceship();
    step1-=0.2;
     checkheight();
    setPos(cor);
    controller.showscore();
    controller.showcoin();
    controller.fight();
    if(step1<0)
    {
        duck=":/project3/doodle.png";
        setData(GD_Type,GO_Doodle);
        controller.pause();
        controller.resume();
    }
    if(cor.ry()>600)
    {
       controller.doodledie();
    }

}
void Player::handleCollisions_plat(){
    QList<QGraphicsItem *> collisions = collidingItems(Qt::IntersectsItemShape);
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Plat) {
            //controller.sansPushBox(this, (Box*)collidingItem);
            controller.doodlehitplat(this,(Plat*)collidingItem);

        }
    }
}
void Player::checkheight(){
    if(cor.ry()<-10)
    {
        controller.down();
    }
}
void Player::handleCollisions_weapon(){
    QList<QGraphicsItem *> collisions = collidingItems(Qt::IntersectsItemShape);
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Weapon) {
            //controller.sansPushBox(this, (Box*)collidingItem);
            //controller.doodlehitplat(this,(Plat*)collidingItem);
            duck=":/project3/rick.png";//成功變換路徑更換圖片
            setData(GD_Type,GO_Rick);
            step1=100;
            controller.doodlegetweapon();
                       }
    }
}
void Player::handleCollisions_spaceship(){
    QList<QGraphicsItem *> collisions = collidingItems(Qt::IntersectsItemShape);
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Spaceship) {
            duck=":/project3/spaceship.png";//成功變換路徑更換圖片
            setData(GD_Type,GO_Spaceship);
            step1=100;
                       }
    }
}


void Player::change()
{
    duck=":/project3/spaceship.png";//成功變換路徑更換圖片
    setData(GD_Type,GO_Spaceship);
    step1=100;
    //亂試試試看

}
/*void Player::handleCollisions_coin(){
    QList<QGraphicsItem *> collisions = collidingItems(Qt::IntersectsItemShape);
    foreach(QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Coin) {

                       }
    }
}*/



