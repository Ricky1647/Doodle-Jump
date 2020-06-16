#include "goods.h"

Goods::Goods()
{

}
void Goods::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit clicked();
}
