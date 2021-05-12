#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QNetworkAccessManager"
#include "QUrl"
#include "QNetworkReply"
#include "QNetworkRequest"
#include "QTcpSocket"
#include "QTcpServer"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTcpSocket *socket;
//    static QTcpSocket *dateSocket;
    QTcpSocket *dataSocket;
    QTcpServer *server;
public slots:

    void slotConnected();
    void dataReceived();

private slots:
    void on_pushButton_clicked();
    void clientRecData();
};
#endif // MAINWINDOW_H
