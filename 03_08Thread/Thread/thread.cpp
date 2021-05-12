#include "thread.h"
#include "ui_thread.h"
#include "QDebug"
#include "QTime"
#include "QString"
Thread::Thread(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Thread)
{
    ui->setupUi(this);
    //qDebug()<<QTime::currentTime().msec();
    this->thread1=new DiceThread;
    connect(thread1,SIGNAL(started()),this,SLOT(thread1Start()));
    connect(thread1,SIGNAL(finished()),this,SLOT(thread1Finish()));
    connect(thread1,SIGNAL(newValue(int,int)),this,SLOT(thread1NewValue(int,int)));
}

Thread::~Thread()
{
    delete ui;
}

void  Thread::closeEvent(QCloseEvent *e)
{
    if(thread1->isRunning()){
        thread1->stopThread();
        thread1->wait();
    }
}

void Thread::thread1Start()
{
    this->ui->label_state->setText("thread started");
}

void Thread::thread1Finish()
{
    this->ui->label_state->setText("thread finish");
}

void Thread::thread1NewValue(int seq, int diceValue)
{
    QString text=QString::asprintf("第%d次掷骰子,点数为：%d",seq,diceValue);
    this->ui->textBrowser->append(text);
}

void Thread::on_pushButton_startThread_clicked()
{
    thread1->start();

}

void Thread::on_pushButton_start_clicked()
{
    thread1->diceBegin();
}

void Thread::on_pushButton_pause_clicked()
{
    thread1->dicePause();
}

void Thread::on_pushButton_finshThread_clicked()
{
    thread1->stopThread();
}

void Thread::on_pushButton_clear_clicked()
{
    this->ui->textBrowser->clear();
}
