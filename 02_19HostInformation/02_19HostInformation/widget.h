#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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
    void on_pushButton_show_clicked();

private:
    Ui::Widget *ui;
    QHostInfo *host;
};

#endif // WIDGET_H
