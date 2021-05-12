#ifndef TCP_H
#define TCP_H

#include <QWidget>
#include "QtNetwork/QTcpServer"
#include "QtNetwork/QTcpSocket"

QT_BEGIN_NAMESPACE
namespace Ui { class tcp; }
QT_END_NAMESPACE

class tcp : public QWidget
{
    Q_OBJECT

public:
    tcp(QWidget *parent = nullptr);
    ~tcp();

private slots:
    void on_pushButton_startListen_clicked();
    void onNewConnection();
    void onReadyRead();
private:
    Ui::tcp *ui;
    QTcpServer *server;
    QTcpSocket *socket;
    int z;
};
#endif // TCP_H
