#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include "QtNetwork/QHostAddress"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->host=new QHostInfo;

    //qDebug()<<address;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_show_clicked()
{
    QString host_name= host->localHostName();
    this->ui->textBrowser->append(host_name+'\n');
    QHostInfo addinfo=host->fromName(host_name);
    QList<QHostAddress> addlist=addinfo.addresses();
    if(!addlist.isEmpty()){
        for (int i=0;i<addlist.count();i++) {
            QHostAddress aHost=addlist.at(i);
            this->ui->textBrowser->append(aHost.toString());
        }
    }

}
