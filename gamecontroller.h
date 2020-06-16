#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include<QGraphicsItem>
#include <QTimer>
#include<QObject>
#include<QWidget>

class QGraphicsScene;
class Player;
class Plat;
class Monster;
class Bullet;
class Pause;
class Weapon;
class Blackhole;
class Spaceship;

class GameController:public QWidget
{
    Q_OBJECT
public:
     GameController(QGraphicsScene &scene, QWidget *parent = 0);
     ~GameController();

     void doodlehitplat(Player *player1,Plat *plat);
     void doodlegetweapon(Player *player1,Weapon *weapon);
     void doodlehitmonster(Monster *monster,Player *player1);
     void findplat();
     void down();
     void platchange();
     void bigheaddie();
     void showscore();
     void fight();
public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    void pause();
    void resume();
    void advance(int step);

protected:
    //bool eventFilter(QObject *object, QEvent *event);

private:
    //void handleKeyPressed(QKeyEvent *event);
    QGraphicsTextItem *game_score;
    QGraphicsTextItem *game_over;

    QGraphicsScene &scene;
    int  score=0;
    QTimer timer;
    Player *player1;
    //QList<Plat*>duck;
    Plat *plat1,*plat2,*plat3,*plat4,*plat5,*plat6,*plat7,*plat8,*plat9,*plat10,*plat11,*plat12;
    Monster *monster1;
    Bullet *bullet1;
    //以下為道具
    Weapon *weapon1;
    Spaceship *spaceship1;
    //以上為道具

    Blackhole *hole1;
    Pause *pause1,*start;
    QList<QGraphicsItem *> li_plat ;
};

#endif // GAMECONTROLLER_H
