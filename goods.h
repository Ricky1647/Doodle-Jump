#ifndef GOODS_H
#define GOODS_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Goods:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Goods();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void clicked();
};

#endif // GOODS_H
