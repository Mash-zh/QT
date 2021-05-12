#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    x=0; y=0;
    this->item=new Butterfly;
    this->scence=new QGraphicsScene;
    item->setPos(0,0);
    scence->setSceneRect(100,0,this->ui->view->width(),this->ui->view->height());
    scence->addItem(item);
    this->ui->view->setScene(scence);
    this->timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(runUpdate()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    x=this->ui->view->mapToScene(e->pos()).x();
    y=this->ui->view->mapToScene(e->pos()).y();
}
void MainWindow::runUpdate()
{
    item->update();
    /**************随机路线****************
    srand((int)time(NULL));

    if(x>500){
        x=490;
    }else if(x<-500){
        x=-490;
    }
    if(y>200){
        y=190;
    }else if(y<-200){
        y=-190;
    }
    int t_x=rand()%16-7;
    int t_y=rand()%16-7;
    x+=t_x;
    y+=t_y;

    item->setPos(x,y);
    ******************************/
    /**************点击路线****************/
    srand((int)time(NULL));
    int srand_x=rand()%5+2;
    int srand_y=rand()%5+2;
    int x_now=item->pos().x();
    int y_now=item->pos().y();
        int x_Dvalue=x-x_now;
        int y_Dvalue=y-y_now;
        if(x_Dvalue>0){
            x_now +=srand_x;
        }else if (x_Dvalue<0) {
            x_now -=srand_x;
        }else {
            x_now +=0;
        }
        if(y_Dvalue>0){
            y_now +=srand_y;
        }else if (y_Dvalue<0) {
            y_now -=srand_y;
        }else {
            y_now +=0;
        }
    //qDebug()<<x_now;
    //qDebug()<<y_now;
    item->setPos(x_now,y_now);
}



