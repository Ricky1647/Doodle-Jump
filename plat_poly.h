#ifndef PLAT_POLY_H
#define PLAT_POLY_H
#include"plat.h"
#include"gamecontroller.h"

class Plat_poly:public Plat
{
public:
    Plat_poly(GameController &controller);
     virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);//使用畫畫
protected:
    float dx=0;
    virtual void advance(int step);
};

#endif // PLAT_POLY_H
