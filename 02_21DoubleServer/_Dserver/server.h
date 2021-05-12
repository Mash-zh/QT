#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include "QtNetwork/QTcpServer"
#include "QtNetwork/QTcpSocket"
#include "QtNetwork/QHostInfo"

namespace Ui {
class server;
}

class server : public QWidget
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = nullptr);
    ~server();

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
    Ui::server *ui;
    QHostInfo *host;
    QTcpServer *TcpServer;
    QTcpSocket *socket;
    void getLocalIP();
};

#endif // SERVER_H
