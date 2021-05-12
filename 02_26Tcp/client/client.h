#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include "QDateTime"
#include "QtNetwork/QTcpSocket"

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QWidget
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void onConnected();
    void onDisconnected();
    void on_pushButton_link_clicked();

    void on_pushButton_send_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::Client *ui;
    QTcpSocket *socket;
    QDateTime *dateTime;
};
#endif // CLIENT_H
