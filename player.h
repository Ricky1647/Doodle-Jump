#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsItem>
#include"gamecontroller.h"



class GameController;



class Player: public   QGraphicsItem
{

public:
     QRectF boundingRect() const;
    Player(GameController & controller);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    //void paint2( );
    void moveLeft( );
    void moveRight();

    //碰撞檢測
    void handleCollisions_plat();
    void handleCollisions_weapon();
    void handleCollisions_spaceship();
     //void handleCollisions_monster();
    float dy=0;
    float y=0;
    QPointF cor; //座標
    void checkheight();
protected:
    GameController &controller;
    void advance(int step);
     QRectF target;

private:


};

#endif // PLAYER_H
