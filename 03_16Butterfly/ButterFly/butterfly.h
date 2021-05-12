#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include "QGraphicsItem"

class Butterfly : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QObject *parent = nullptr);
    QRectF boundingRect() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
signals:

public slots:
    //void runUpdate();
private:
    QPixmap pix_up;
    QPixmap pix_down;

    bool fly_state;

};

#endif // BUTTERFLY_H
