#include "timer.h"
#include "ui_timer.h"
#include "QTimer"
#include "QDebug"
Timer::Timer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Timer)
{
    ui->setupUi(this);
//    QTimer *timer = new QTimer;
//    connect(timer,SIGNAL(timeout()),this,SLOT(output()));
//    timer->start(3000);
//    output();
    this->fileWatcher = new QFileSystemWatcher;
    qDebug()<<this->fileWatcher->addPath("E:/code/QT for Android/10_28Timer/FileWatcher");
    qDebug()<<this->fileWatcher->directories();
    connect(this->fileWatcher,SIGNAL(directoryChanged(const QString)),this,SLOT(output(QString)));
}

Timer::~Timer()
{
    delete ui;
}

void Timer::output(QString)
{
    qDebug()<<"ok";
}
