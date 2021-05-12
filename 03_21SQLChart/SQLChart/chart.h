#ifndef CHART_H
#define CHART_H

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
namespace Ui {
class Chart;
}

class Chart : public QWidget
{
    Q_OBJECT

public:
    explicit Chart(QWidget *parent = nullptr);
    ~Chart();

private slots:
    void on_pushButton_listen_clicked();

    void onReadyRead();

    void onNewConnection();
    void on_pushButton_insert_clicked();

private:
    Ui::Chart *ui;
    int sum;

    QTcpServer *server;
    QTcpSocket *socket;

    QLineSeries *series;
    QBarSeries *barSeries;
    QBarSet *barSet;
    QChart *qchart;
    QCategoryAxis *axisX;
    QValueAxis *axisY;
};

#endif // CHART_H
