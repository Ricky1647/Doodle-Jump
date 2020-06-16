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
class Coin;
class Goods;
class Plat_poly;


class GameController:public QWidget
{
    Q_OBJECT
public:
     GameController(QGraphicsScene &scene, QWidget *parent = 0);
     ~GameController();

     void doodlehitplat(Player *player1,Plat *plat);
     void doodlegetweapon( );
     void doodlegetcoin( );
     void doodlehitmonster(Monster *monster,Player *player1);
     void doodlehithole(Blackhole *blackhole,Player *player1);
     void doodledie();//特別為掉下去設計的
     void findplat();
     void down();
     void platchange();
     void bigheaddie();
     //呈現分數以及錢幣
     void showscore();
     void showcoin();
     //
     void fight();
public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    void pause();
    void resume();
    void advance(int step);
    void buy();

protected:
    //bool eventFilter(QObject *object, QEvent *event);

private:
    //void handleKeyPressed(QKeyEvent *event);
    QGraphicsTextItem *game_score; //遊戲分數
    QGraphicsTextItem *game_over;  //結束文字
    QGraphicsTextItem *final_score;//遊戲結束分數文字
    QGraphicsTextItem *last_score;  //結束分數
    QGraphicsTextItem *coin_number; //錢幣文字
    QGraphicsTextItem *coin_count;//錢幣數值

    QGraphicsScene &scene;
    //以下為分數錢幣
    int  score=0;
    int  coco=0;
    //
    QTimer timer;
    Player *player1;
    //QList<Plat*>duck;
    Plat *plat1,*plat2,*plat3,*plat4,*plat5,*plat6,*plat7,*plat8,*plat9,*plat10,*plat11,*plat12;

    //以下實施多型
    Plat *ptr=NULL;
    Plat_poly *plat_poly1;
    //以上實施多型

    Monster *monster1;
    Bullet *bullet1;
    //以下為道具
    Weapon *weapon1;
    Spaceship *spaceship1;
    Coin *coin1,*coin2,*coin3,*coin4;
    //以上為道具

    Blackhole *hole1;
    //以下為暫停鍵開始建買武器
    Pause *pause1,*start;
    Goods *goods1,*sun;
    //以上為暫停鍵開始建買武器

    QList<QGraphicsItem *> li_plat ;
};

#endif // GAMECONTROLLER_H
