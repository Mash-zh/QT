#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QtNetwork/QTcpServer"
#include "QtNetwork/QTcpSocket"
#include "QtNetwork/QHostInfo"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_start_listen_clicked();

    void on_pushButton_stop_listen_clicked();

    void onNewconnected();
    void onClicentConnected();
    void onClicentDisconnected();
    void onSocketError();
    void onstateChanged(QAbstractSocket::SocketState socketState);
    void onreadyRead();
    void on_pushButton_send_clicked();

    void on_pushButton_connect_clicked();

    void on_pushButton_disconnect_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::Widget *ui;
    QHostInfo *host;
    QTcpServer *server;
    QTcpSocket *socket;
    void getLocalIP();

};

#endif // WIDGET_H
