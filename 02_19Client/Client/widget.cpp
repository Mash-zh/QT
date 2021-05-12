#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->socket=new QTcpSocket;
}

Widget::~Widget()
{
    delete ui;

}

void Widget::on_pushButton_connect_clicked()
{
    QString address =this->ui->lineEdit_IP->text();
    quint16 port=this->ui->lineEdit_port->text().toInt();
    socket->connectToHost(address,port);
}

void Widget::on_pushButton_disconnect_clicked()
{
    if(socket->state()==QAbstractSocket::ConnectedState){
        socket->disconnectFromHost();
    }
}

void Widget::on_pushButton_send_clicked()
{
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    if(socket->state()==QAbstractSocket::ConnectedState){
        QString message=this->ui->lineEdit_message->text();
        this->ui->textBrowser->setText("本机："+message);
        this->ui->lineEdit_message->clear();
        this->ui->lineEdit_message->setFocus();
        QByteArray send_message=message.toUtf8();
        send_message.append('\n');
        socket->write(send_message);
    }else {
    this->ui->textBrowser->setText("服务器已断开，请重新连接!");
    }
}

void Widget::onReadyRead()
{

    while (socket->canReadLine()) {
        this->ui->textBrowser->append("服务器："+socket->readAll());
    }
}





















