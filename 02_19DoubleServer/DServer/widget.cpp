#include "widget.h"
#include "ui_widget.h"
#include "QString"
#include "QDebug"
#include "QMessageBox"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QMessageBox *messageBox=new QMessageBox;
    this->ui->pushButton_stop_listen->setEnabled(false);

    this->host=new QHostInfo;
    getLocalIP();

    this->server=new QTcpServer;
    this->socket=new QTcpSocket;
    connect(server,SIGNAL(newConnection()),this,SLOT(onNewconnected()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::getLocalIP()
{
    QString host_name= host->localHostName();
    this->ui->textBrowser_IP->append("主机："+host_name);
    QHostInfo addinfo=host->fromName(host_name);
    QList<QHostAddress> addlist=addinfo.addresses();
    if(!addlist.isEmpty()){
        for (int i=0;i<addlist.count();i++) {
            QHostAddress aHost=addlist.at(i);
            this->ui->textBrowser_IP->append("IP："+aHost.toString());
        }
    }
}

void Widget::onNewconnected()
{
    while(server->hasPendingConnections())
    {
        socket=server->nextPendingConnection();
        connect(socket,SIGNAL(connected()),this,SLOT(onClicentConnected()));
        connect(socket,SIGNAL(disconnected()),this,SLOT(onClicentDisconnected()));
        connect(socket,SIGNAL(error(QAbstractSocket::SocketError socketError)),this,SLOT(onSocketError()));
        connect(socket,SIGNAL(stateChanged(QAbstractSocket::SocketState socketState)),this,SLOT(onstateChanged(QAbstractSocket::SocketState socketState)));
        connect(socket,SIGNAL(readyRead()),this,SLOT(onreadyRead()));
    }
}

void Widget::onClicentConnected()
{
    this->ui->textBrowser_message->append("Socket连接建立");
    this->ui->textBrowser_message->append("客户端地址："+ socket->peerAddress().toString());
    this->ui->textBrowser_message->append("客户端端口："+ QString::number(socket->peerPort()));
}

void Widget::onClicentDisconnected()
{
    this->ui->textBrowser_message->append("Socket连接断开");
    socket->deleteLater();//删除socket
}

void Widget::onSocketError()
{
    this->ui->textBrowser_message->append(socket->errorString());
}

void Widget::onstateChanged(QAbstractSocket::SocketState socketState)
{
    switch (socketState) {
    case QAbstractSocket::UnconnectedState:
        this->ui->textBrowser_message->append("The socket is not connected."); break;
    case QAbstractSocket::HostLookupState:
        this->ui->textBrowser_message->append("The socket is performing a host name lookup.");break;
    case QAbstractSocket::ConnectingState:
        this->ui->textBrowser_message->append("The socket has started establishing a connection.");break;
    case QAbstractSocket::ConnectedState:
        this->ui->textBrowser_message->append("A connection is established.");break;
    case QAbstractSocket::BoundState:
        this->ui->textBrowser_message->append("The socket is bound to an address and port.");break;
    case QAbstractSocket::ClosingState:
        this->ui->textBrowser_message->append("The socket is about to close (data may still be waiting to be written.");break;
    case QAbstractSocket::ListeningState:
        this->ui->textBrowser_message->append("For internal use only.");break;
    }
}

void Widget::onreadyRead()
{
    while (socket->canReadLine()) {
        this->ui->textBrowser_message->append("客户："+socket->readAll());
    }
}


/********************按键函数******************************/
void Widget::on_pushButton_start_listen_clicked()
{
    quint16 port=this->ui->lineEdit_port->text().toInt();
    if (this->ui->lineEdit_port->text().isEmpty()){
        QMessageBox::warning(this,"警告","请重新填写端口号");
    }else {
        this->ui->textBrowser_message->append("开始监听......");
        server->listen(QHostAddress::Any,port);
        this->ui->pushButton_start_listen->setText("正在监听");
        this->ui->textBrowser_message->append("正在监听......");
        this->ui->pushButton_stop_listen->setEnabled(true);
        this->ui->pushButton_start_listen->setEnabled(false);
        this->ui->pushButton_connect->setEnabled(false);
}

}

void Widget::on_pushButton_stop_listen_clicked()
{
    if(server->isListening()){
        server->close();
        this->ui->textBrowser_message->append("停止监听......");
        this->ui->pushButton_start_listen->setEnabled(true);
        this->ui->pushButton_stop_listen->setEnabled(false);
        this->ui->pushButton_start_listen->setText("开始监听");
    }
    if(socket->state()==QAbstractSocket::ConnectedState){
        this->ui->pushButton_connect->setEnabled(false);
    }else if(socket->state()==QAbstractSocket::UnconnectedState){
    this->ui->pushButton_connect->setEnabled(true);
}

}

void Widget::on_pushButton_send_clicked()
{
    QString message=this->ui->lineEdit_message->text();
    this->ui->textBrowser_message->append("本机："+message);
    this->ui->lineEdit_message->clear();
    this->ui->lineEdit_message->setFocus();

    QByteArray sendMessage=message.toUtf8();
    sendMessage.append('\n');
    socket->write(sendMessage);
}

void Widget::on_pushButton_connect_clicked()
{
    if (this->ui->lineEdit_ip->text().isEmpty()||this->ui->lineEdit_port->text().isEmpty()) {
         QMessageBox::warning(this,"警告","请重新填写IP地址或端口号");
    }else {
        this->ui->pushButton_start_listen->setEnabled(false);
        QString address =this->ui->lineEdit_ip->text();
        quint16 port=this->ui->lineEdit_port->text().toInt();
        socket->connectToHost(address,port);
    }

}

void Widget::on_pushButton_disconnect_clicked()
{
    this->ui->pushButton_start_listen->setEnabled(true);
    if(socket->state()==QAbstractSocket::ConnectedState){
        socket->disconnectFromHost();
    }
}

void Widget::on_pushButton_clear_clicked()
{
    this->ui->textBrowser_message->clear();
}
