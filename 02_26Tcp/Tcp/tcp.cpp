#include "tcp.h"
#include "ui_tcp.h"

tcp::tcp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tcp)
{
    ui->setupUi(this);
    this->server=new QTcpServer;
    this->socket=new QTcpSocket;
z=0;
    connect(server,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
}

tcp::~tcp()
{
    delete ui;
}


void tcp::on_pushButton_startListen_clicked()
{
    if(this->ui->pushButton_startListen->text()=="开始监听"){
        bool state=this->server->listen(QHostAddress::Any,60000);
        if(state){
            this->ui->label_listen->setText("正在监听");
        }else{
            this->ui->label_listen->setText("监听失败");
        }
        this->ui->pushButton_startListen->setText("停止监听");
    }else{
        this->server->close();
        this->ui->label_listen->setText("停止监听");
        this->ui->pushButton_startListen->setText("开始监听");
    }

}

void tcp::onNewConnection()
{
    if(server->hasPendingConnections()){
        socket=server->nextPendingConnection();
        connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    }
}

void tcp::onReadyRead()
{

    QByteArray arry=socket->readAll();
    this->ui->textBrowser->append("IN:"+arry);
    z=z+1;
    qDebug()<<z;
}














