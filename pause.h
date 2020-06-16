#ifndef PAUSE_H
#define PAUSE_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Pause:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Pause( );
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void clicked();
};

#endif // PAUSE_H
