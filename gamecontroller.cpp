#include <QGraphicsScene>
#include<QKeyEvent>
#include <QEvent>
#include "gamecontroller.h"
#include "player.h"
#include "plat.h"
#include "monster.h"
#include<time.h>
#include"constants.h"
#include"bullet.h"
#include"pause.h"
#include"weapon.h"
#include"blackhole.h"
#include"spaceship.h"
#include"coin.h"
#include"goods.h"
#include"plat_poly.h"
int speed=0;

struct point
{ int x,y;};

point plat_cor[11];

GameController::GameController(QGraphicsScene &scene, QWidget*parent):
    QWidget(parent),
    scene(scene)
{
    srand(time(0));
    timer.start(1000/44);
    player1=new Player(*this);
    scene.addItem(player1);
    //this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus(); //設置焦點就能動作了，我很感動QQQQQQQQQQ

    for(int i=0;i<11;i++)
    {
        plat_cor[i].x=rand()%500;
        plat_cor[i].y=rand()%633;
    }

    /*
    for(int i=0;i<8;i++)
    {
        Plat*b=new Plat(*this);
        b->cor.rx()=plat_cor[i].x;
        b->cor.ry()=plat_cor[i].y;
        //duck.append(b);
        b->setPos(b->cor);
        scene.addItem(b);
    }
    */

    //以下測試多型
    plat_poly1=new Plat_poly(*this);
    ptr=plat_poly1;
    ptr->cor.rx()=10;
    ptr->cor.ry()=400;
    ptr->setPos(ptr->cor);
    scene.addItem(ptr);
    //以上測試多型

    //以下建造既有的平台
    plat1=new Plat(*this);
    plat1->cor.rx()=plat_cor[0].x;
    plat1->cor.ry()=50;
    plat1->setPos(plat1->cor);
    scene.addItem(plat1);

    plat2=new Plat(*this);
    plat2->cor.rx()=plat_cor[1].x;
    plat2->cor.ry()=100;
    plat2->setPos(plat2->cor);
    scene.addItem(plat2);

    plat3=new Plat(*this);
    plat3->cor.rx()=plat_cor[2].x;
    plat3->cor.ry()=150;
    plat3->setPos(plat3->cor);
    scene.addItem(plat3);

    plat4=new Plat(*this);
    plat4->cor.rx()=plat_cor[3].x;
    plat4->cor.ry()=200;
    plat4->setPos(plat4->cor);
    scene.addItem(plat4);

    plat5=new Plat(*this);
    plat5->cor.rx()=plat_cor[4].x;
    plat5->cor.ry()=300;
    plat5->setPos(plat5->cor);
    scene.addItem(plat5);

    plat6=new Plat(*this);
    plat6->cor.rx()=plat_cor[5].x;
    plat6->cor.ry()=350;
    plat6->setPos(plat6->cor);
    scene.addItem(plat6);

    plat7=new Plat(*this);
    plat7->cor.rx()=plat_cor[6].x;
    plat7->cor.ry()=400;
    plat7->setPos(plat7->cor);
    scene.addItem(plat7);

    plat8=new Plat(*this);
    plat8->cor.rx()=plat_cor[7].x;
    plat8->cor.ry()=450;
    plat8->setPos(plat8->cor);
    scene.addItem(plat8);

    plat9=new Plat(*this);
    plat9->cor.rx()=plat_cor[8].x;
    plat9->cor.ry()=500;
    plat9->setPos(plat9->cor);
    scene.addItem(plat9);

    plat10=new Plat(*this);
    plat10->cor.rx()=plat_cor[9].x;
    plat10->cor.ry()=550;
    plat10->setPos(plat10->cor);
    scene.addItem(plat10);

    plat11=new Plat(*this);
    plat11->cor.rx()=plat_cor[10].x;
    plat11->cor.ry()=600;
    plat11->setPos(plat11->cor);
    scene.addItem(plat11);

    plat12=new Plat(*this);
    plat12->cor.rx()=plat_cor[10].x;
    plat12->cor.ry()=0;
    plat12->setPos(plat11->cor);
    scene.addItem(plat11);
    //以上建造所有的平台

    //以下建怪物
     monster1=new Monster(*this);
     monster1->cor.rx()=300;
     monster1->cor.ry()=-50;
     monster1->setPos(monster1->cor);
     scene.addItem(monster1);
    //以上建怪物

    //以下測試武器
     weapon1=new Weapon(*this);
     weapon1->cor.rx()=200;
     weapon1->cor.ry()=300;
     weapon1->setPos(weapon1->cor);
     scene.addItem(weapon1);
    //以上測試武器

     //以下測試錢幣
      coin1=new Coin(*this);
      coin1->cor.rx()=100;
      coin1->cor.ry()=500;
      coin1->setPos(coin1->cor);
      scene.addItem(coin1);
      coin2=new Coin(*this);
      coin2->cor.rx()=400;
      coin2->cor.ry()=700;
      coin2->setPos(coin2->cor);
      scene.addItem(coin2);
      coin3=new Coin(*this);
      coin3->cor.rx()=-200;
      coin3->cor.ry()=400;
      coin3->setPos(coin3->cor);
      scene.addItem(coin3);
      coin4=new Coin(*this);
      coin4->cor.rx()=-200;
      coin4->cor.ry()=100;
      coin4->setPos(coin4->cor);
      scene.addItem(coin4);
     //以上測試錢幣

    //以下測試飛碟
     spaceship1=new Spaceship(*this);
     spaceship1->cor.rx()=100;
     spaceship1->cor.ry()=-50;
     spaceship1->setPos(spaceship1->cor);
     scene.addItem(spaceship1);
    //以上測試飛碟

    //以下測試黑洞
     hole1=new Blackhole(*this);
     hole1->cor.rx()=600;
     hole1->cor.ry()=0;
     hole1->setPos(hole1->cor);
     scene.addItem(hole1);
    //以上測試黑洞

    //以下測試分數
     game_score = new QGraphicsTextItem;
     game_score->setFont(QFont("Times", 10, QFont::Bold));
     game_score->setPos(0, 0);
     game_score->setZValue(50);
     game_score->setHtml(tr("<font color = black >0</font>"));
     scene.addItem(game_score);
    //以上測試分數

     //以下建最後分數
      last_score = new QGraphicsTextItem;
      last_score->setFont(QFont("Times", 40, QFont::Bold));
      last_score->setPos(100, 400);
      last_score->setZValue(50);
      last_score->setHtml(tr("<font color = red >0</font>"));
      scene.addItem(last_score);
      last_score->hide();
     //以上見最後分數

     //以下建遊戲結束
     game_over=new QGraphicsTextItem(QString("Game Over"));
     QFont titleFont("comic sans", 40);
     game_over->setFont(titleFont);
     game_over->setPos(100,200);
     game_over->setZValue(50);
     game_over->setDefaultTextColor(Qt::red);
     scene.addItem(game_over);
     game_over->hide();
     //以上建遊戲結束

     //以下建最後分數文本
     final_score=new QGraphicsTextItem(QString("Final Score"));
     QFont titleFont_1("comic sans", 40);
     final_score->setFont(titleFont_1);
     final_score->setPos(100,300);
     final_score->setDefaultTextColor(Qt::red);
     final_score->setZValue(50);
     scene.addItem(final_score);
     final_score->hide();
     //以上建最後分數文本

     //以下建錢幣文本
     coin_number=new QGraphicsTextItem(QString("coin"));
     QFont titleFont_2("comic sans", 15);
     coin_number->setFont(titleFont_2);
     coin_number->setPos(75,-5);
     coin_number->setDefaultTextColor(Qt::darkYellow);
     scene.addItem(coin_number);
     //以上建錢幣文本

     //以下測試錢幣多少
     coin_count = new QGraphicsTextItem;
     coin_count->setFont(QFont("Times", 15, QFont::Bold));
     coin_count->setPos(120, -5);
     coin_count->setZValue(50);
     coin_count->setHtml(tr("<font color = black >0</font>"));
     scene.addItem(coin_count);
    //以上測試錢幣多少

     //以下測試暫停
     pause1=new Pause();
     pause1->setPixmap(QPixmap(":/project3/pause.png").scaled(50,50));
     pause1->setPos(400,-5);
     scene.addItem(pause1);
     connect(pause1, SIGNAL(clicked()), this, SLOT(pause()));
     //以上測試暫停

     //以下測試商品
     goods1=new Goods();
      goods1->setPixmap(QPixmap(":/project3/goods.png").scaled(50,50));
      goods1->setPos(175,-5);
     scene.addItem(goods1);
     connect(goods1, SIGNAL(clicked()), this, SLOT(buy()));
     //以上測試商品

     //以下測試商品
     sun=new Goods();
     sun->setPixmap(QPixmap(":/project3/sun.png").scaled(250,250));
     sun->setPos(350,450);
     sun->setZValue(-10);
     scene.addItem(sun);
     //以上測試商品

     //以下測試開始
     start=new Pause();
     start->setPixmap(QPixmap(":/project3/resume.png").scaled(50,50));
     start->setPos(300,-8);
     scene.addItem(start);
     connect(start, SIGNAL(clicked()), this, SLOT(resume()));
     //以上測試開始
    player1->setZValue(10);
    findplat(); //尋找平台

    scene.update();
    resume();
}
GameController::~GameController()
{
}
void GameController::pause()
{
    disconnect(&timer, SIGNAL(timeout()),
        &scene, SLOT(advance()));
}
void GameController::resume()
{
    connect(&timer, SIGNAL(timeout()),
        &scene, SLOT(advance()));
     this->setFocus();
}

void GameController::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()) {
    case Qt::Key_Left:
        player1->moveLeft();
        player1->setPos(player1->cor);
        scene.update();
        //fight();
        break;
    case Qt::Key_Right:
        player1->moveRight();
        player1->setPos(player1->cor);
        scene.update();
        //showscore();
        break;
    /*case Qt::Key_Up:
        if(player1->data(GD_Type) == GO_Spaceship)
        {
            player1->cor.ry()-=50;
            player1->setPos(player1->cor);
        }
        break;*/
    case Qt::Key_Space:
        {
        Bullet *b = new Bullet(*this);
         //b->setPos(player1->x() + player1->pixmap().width() / 2 - b->pixmap().width() / 2, player1->y() - b->pixmap().height());
        b->cor.rx()=player1->cor.rx()+125-25;
        b->cor.ry()=player1->cor.ry()+200;
        b->setPos(b->cor);
         scene.addItem(b);
         scene.update();
        break;
         }

    }
}
void GameController::doodlehitplat(Player *player1,Plat *plat)
{

    player1->cor.ry()-=80;
    player1->setPos(player1->cor);

    scene.update();
}
void GameController::doodlegetweapon( )
{
    this->setFocus();
}
void GameController::doodlegetcoin( )
{
   coco+=10;
}
void GameController::doodlehitmonster(Monster *monster,Player *player1 )
{
    game_over->show();
    final_score->show();
    last_score->show();
    this->clearFocus();
    start->disconnect();
    goods1->disconnect();
     pause();
}
void GameController::doodlehithole(Blackhole *blackhole, Player *player1)
{
    game_over->show();
    final_score->show();
    last_score->show();
    this->clearFocus();
    start->disconnect();
    goods1->disconnect();
    pause();
}
void GameController::doodledie()
{
    game_over->show();
    final_score->show();
    last_score->show();
    this->clearFocus();
    start->disconnect();
    goods1->disconnect();
    pause();

}

void GameController::findplat(){
    QList<QGraphicsItem*>listing=scene.items();
    for(int i=0;i<listing.size();i++){
        if(listing[i]->data(GD_Type)==GO_Plat){
            li_plat.append(listing[i]);
        }
    }
}
void GameController::down(){

    if(player1->data(GD_Type) == GO_Spaceship)speed=20;
    else speed=3;//player1->dy;

    score+=abs(speed);
    plat1->cor.ry()+=abs(speed);
    plat1->setPos(plat1->cor);
    plat2->cor.ry()+=abs(speed);
    plat2->setPos(plat2->cor);
    plat3->cor.ry()+=abs(speed);
    plat3->setPos(plat3->cor);
    plat4->cor.ry()+=abs(speed);
    plat4->setPos(plat4->cor);
    plat5->cor.ry()+=abs(speed);
    plat5->setPos(plat5->cor);
    plat6->cor.ry()+=abs(speed);
    plat6->setPos(plat6->cor);
    plat7->cor.ry()+=abs(speed);
    plat7->setPos(plat7->cor);
    plat8->cor.ry()+=abs(speed);
    plat8->setPos(plat8->cor);
    plat9->cor.ry()+=abs(speed);
    plat9->setPos(plat9->cor);
    plat10->cor.ry()+=abs(speed);
    plat10->setPos(plat10->cor);
    plat11->cor.ry()+=abs(speed);
    plat11->setPos(plat11->cor);
    plat12->cor.ry()+=abs(speed);
    plat12->setPos(plat12->cor);
    monster1->cor.ry()+=abs(speed);
    monster1->setPos(monster1->cor);
    weapon1->cor.ry()+=abs(speed);
    weapon1->setPos(weapon1->cor);
    hole1->cor.ry()+=abs(speed);
    hole1->setPos(hole1->cor);
    spaceship1->cor.ry()+=abs(speed);
    spaceship1->setPos(spaceship1->cor);
    //錢幣下降
    coin1->cor.ry()+=abs(speed);
    coin1->setPos(coin1->cor);
    coin2->cor.ry()+=abs(speed);
    coin2->setPos(coin2->cor);
    coin3->cor.ry()+=abs(speed);
    coin3->setPos(coin3->cor);
    coin4->cor.ry()+=abs(speed);
    coin4->setPos(coin4->cor);
    //錢幣下降

    //移動平台下降
    ptr->cor.ry()+=abs(speed);
    ptr->setPos(coin1->cor);
    //移動平台下降
    scene.update();
}
void GameController::platchange(){
    /*for(int i=0;i<8;i++){
    plat_cor[i].y=0;
    duck[i]->cor.ry()=plat_cor[i].y;
    duck[i]->setPos(duck[i]->cor);
    }
    */
 plat1->cor.ry()=0;
 plat1->cor.rx()=300;
 plat1->setPos(plat1->cor);
 scene.update();

}
void GameController::advance(int step){
    showscore();
}
void GameController::bigheaddie()
{
    //scene.removeItem(monster1);
   // delete monster1;

   //deleteLater(monster1);
}
void GameController::showscore()
{
    int current_score = game_score->toPlainText().toInt();
    current_score = score;
   game_score->setHtml(tr("<font color = black>%1</font>").arg(current_score));
   last_score->setHtml(tr("<font color = red>%1</font>").arg(current_score));
}
void GameController::showcoin()
{
    int current_coin = coin_count->toPlainText().toInt();
    current_coin = coco;
   coin_count->setHtml(tr("<font color = black>%1</font>").arg(current_coin));

}
//此為設置怪物道具，以分數判斷什麼時候提供
void  GameController::fight(){
    if(score%5000==500){
        monster1->cor.ry()=-300;
        monster1->cor.rx()=rand()%500;
        monster1->setPos(monster1->cor);
        monster1->show();
        hole1->cor.ry()=-100;
        hole1->cor.rx()=rand()%500;
        hole1->setPos(hole1->cor);
        coin1->cor.ry()=-100;
        coin1->cor.rx()=rand()%500;
        coin1->setPos(coin1->cor);
    }
    if(score%2000==500){
        weapon1->cor.ry()=-100;
        weapon1->cor.rx()=rand()%500;
        weapon1->setPos(weapon1->cor);
        coin2->cor.ry()=-100;
        coin2->cor.rx()=rand()%500;
        coin2->setPos(coin2->cor);
        coin3->cor.ry()=-150;
        coin3->cor.rx()=rand()%500;
        coin3->setPos( coin3->cor);
    }
    if(score%7000==500){
        spaceship1->cor.ry()=-100;
        spaceship1->cor.rx()=rand()%500;
        spaceship1->setPos(spaceship1->cor);
    }
    if(score%1000==500){
        ptr->cor.ry()=-100;
        ptr->cor.rx()=rand()%500;
        ptr->setPos(ptr->cor);
    }
    scene.update();
}
void GameController::buy(){
    if(coco>=10)
    {
        coco-=10;
        player1->change();
        player1->cor.ry()=-100;
        player1->setPos(player1->cor);
        this->setFocus();
        scene.update();
    }
}
