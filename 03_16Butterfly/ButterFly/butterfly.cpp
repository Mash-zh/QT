#include "butterfly.h"
#include "QPainter"
#include "QDebug"
Butterfly::Butterfly(QObject *parent) : QObject(parent)
{
    pix_up.load(":/new/butterfly/up.png");
    pix_down.load(":/new/butterfly/down.png");
    fly_state=true;

}

QRectF Butterfly::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0- penWidth / 2,0- penWidth / 2,
                  pix_up.width() + penWidth, pix_up.height() + penWidth);
}

void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(fly_state){
       painter->drawPixmap(boundingRect().topLeft(),pix_up);
       fly_state=false;
    }else{
       painter->drawPixmap(boundingRect().topLeft(),pix_down);
       fly_state=true;
    }
}
/*******************************
void Butterfly::runUpdate()
{
    update();
    qDebug()<<"update";
    timer->start(100);
}
*******************************/
