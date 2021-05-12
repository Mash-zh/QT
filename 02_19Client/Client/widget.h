#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QtNetwork/QTcpSocket"

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
    void on_pushButton_connect_clicked();

    void on_pushButton_disconnect_clicked();

    void on_pushButton_send_clicked();

    void onReadyRead();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;

};

#endif // WIDGET_H
