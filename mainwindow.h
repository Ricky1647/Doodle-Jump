#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QGraphicsScene;
class QGraphicsView;
class GameController;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
   // void startgame();
    void adjustViewSize();
private:
    Ui::MainWindow *ui;
    void initScene();
    QGraphicsScene *scene;
    QGraphicsView *view;
    GameController *game;
};
#endif // MAINWINDOW_H
