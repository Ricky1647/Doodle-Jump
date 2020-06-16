#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QGraphicsView>
#include "gamecontroller.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene,this))
    //, ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
     setCentralWidget(view);
     resize(500 ,644);
     initScene();
     QTimer::singleShot(0, this, SLOT(adjustViewSize()));
      QTimer time(0);
      game = new GameController(*scene, this);
}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::initScene()
{
     scene->setSceneRect(0, 0, 500,644);
}
void MainWindow::adjustViewSize()
{
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}
