#include "client.h"
#include "ui_client.h"
#include "QMessageBox"
Client::Client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    this->dateTime=new QDateTime;
    this->socket=new QTcpSocket;
    connect(socket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
}

Client::~Client()
{
    delete ui;
}

void Client::onConnected()
{
    this->ui->label_2->setText("已成功连接");
}

void Client::onDisconnected()
{
    this->ui->label_2->setText("已断开连接");
}

void Client::on_pushButton_link_clicked()
{
    if(this->ui->lineEdit_IP->text().isEmpty()){
        QMessageBox::information(this,"提醒","请检查IP地址是否已填写");
    }else{
        if(this->ui->pushButton_link->text()=="连接服务器"){
            QString ip=this->ui->lineEdit_IP->text();
            socket->connectToHost(ip,60000);
            this->ui->pushButton_link->setText("断开连接");
        }else{
            socket->disconnectFromHost();
            this->ui->pushButton_link->setText("连接服务器");
        }
    }
}

void Client::on_pushButton_send_clicked()
{
    if(this->ui->label_2->text()=="已成功连接"){
        QString time=dateTime->currentDateTime().toString("yyyy年MM月dd日ddd hh::mm::ss");
        QString message=this->ui->lineEdit_messgae->text();
        QByteArray sendMessage=message.toUtf8();
        socket->write(sendMessage);
        this->ui->textBrowser->append(time+" "+"OUT:"+message);
        this->ui->lineEdit_messgae->setText("");
    }else {
            QMessageBox::information(this,"提醒","服务器连接失败，请重新连接");
        }
}

void Client::on_pushButton_clear_clicked()
{
    this->ui->textBrowser->clear();
}
