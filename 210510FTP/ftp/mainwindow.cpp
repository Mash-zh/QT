#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QFile"
#include "QTextCodec"
#include "QImage"
#include "QPixmap"
#include "QByteArray"
#include "QBuffer"
#include "QImageReader"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    dataSocket = new QTcpSocket;
//    static QTcpSocket dataSocket;
    server = new QTcpServer(this);
    connect(socket,&QTcpSocket::connected,this,&MainWindow::slotConnected);
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::dataReceived);
    socket->connectToHost("192.168.1.91", 21);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotConnected()
{
    this->ui->textEdit->append("已建立Socket连接");
}

void MainWindow::dataReceived()
{
    while (socket->bytesAvailable())
       {
           /* 读取Socket并存入datagram */
           QByteArray datagram = socket->readAll();

           /* 展示在textEdit */
           QString str = QString::fromLocal8Bit(datagram);
           this->ui->textEdit->append(str);

           QString command = this->ui->lineEdit->text().toLatin1();
           if(command == "pasv" || command == "PASV")
           {
               QStringList receiveMessage = str.split("(");
               receiveMessage = receiveMessage[1].split(")");
               receiveMessage = receiveMessage[0].split(",");
               int receivePort = QString(receiveMessage[4]).toInt() * 256 + QString(receiveMessage[5]).toInt();
               dataSocket->connectToHost("192.168.1.91", receivePort);

           }
           connect(dataSocket, &QTcpSocket::readyRead, this, &MainWindow::clientRecData);
       }
}



void MainWindow::on_pushButton_clicked()
{
    QByteArray command = this->ui->lineEdit->text().toLatin1();
    QByteArray CMD =command + '\n';
    this->socket->write(CMD);
}

void MainWindow::clientRecData()
{
    QByteArray array;
    QImage image;
    if (this->server->isListening())
       {
           this->server->close();
       }
       if (!this->dataSocket->bytesAvailable())
           return;

       QFile file("test.jpg");

       file.open(QIODevice::WriteOnly | QIODevice::Append);

//       QByteArray recvDatas = this->dataSocket->readAll();


       /* 写入文件 */
       file.write(this->dataSocket->readAll());
       file.close();

}
