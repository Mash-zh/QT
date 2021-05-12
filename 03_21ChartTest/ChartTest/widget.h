#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QtCharts/QChart"
#include "QtCharts/QLineSeries"
#include "QtCharts/QBarSet"
#include "QtCharts/QBarSeries"
#include "QtCharts/QCategoryAxis"
#include "QtCharts/QValueAxis"
#include "QDateTime"
#include "QList"
#include "QStringList"
#include "QtNetwork/QTcpServer"
#include "QtNetwork/QTcpSocket"
using namespace QtCharts;

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
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    int sum;

    QLineSeries *series;
    QBarSeries *barSeries;
    QBarSet *barSet;
    QChart *qchart;
    QCategoryAxis *axisX;
    QValueAxis *axisY;


};
#endif // WIDGET_H
