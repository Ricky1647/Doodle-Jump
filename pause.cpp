#include "pause.h"

Pause::Pause( )
{

}
void Pause::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit clicked();
}
