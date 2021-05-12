#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QGraphicsScene"
#include "QGraphicsView"
#include "butterfly.h"
#include "QTimer"
#include "QMouseEvent"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void runUpdate();

protected:
    void mousePressEvent(QMouseEvent *e);
private:
    Ui::MainWindow *ui;

    Butterfly *item;
    QGraphicsScene *scence;
    QTimer *timer;
    //QGraphicsView *view;
    int x,y;

};
#endif // MAINWINDOW_H
