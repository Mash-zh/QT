#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>

class ButterFly : public QObject
{
    Q_OBJECT
public:
    explicit ButterFly(QObject *parent = nullptr);

signals:

};

#endif // BUTTERFLY_H
