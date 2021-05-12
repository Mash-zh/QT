#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QList"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonLink_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonGet_clicked();

private:
    Ui::Widget *ui;
    QList<QString> list;
    QString sub_list;
};
#endif // WIDGET_H
