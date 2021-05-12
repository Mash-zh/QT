#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

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
namespace Ui { class chartWidget; }
QT_END_NAMESPACE

class chartWidget : public QWidget
{
    Q_OBJECT

public:
    chartWidget(QWidget *parent = nullptr);
    ~chartWidget();
    int getX();
    double getY();
    void saveFile();
    void openFile();
    void addNewCoordinate();
    //void addContinueCoordinate();
protected:
   void closeEvent(QCloseEvent *event);

private slots:
    //void on_pushButton_add_clicked();

    void onNewConnection();

    void on_pushButton_listen_clicked();

    void onReadyRead();

private:
    Ui::chartWidget *ui;
    double x,y,z,c,b,message;
    int sum;
    QString dateInformation;
    QString information;
    QString historyLine;
    QLineSeries *series;
    QBarSeries *barSeries;
    QBarSet *barSet;
    QChart *chart;
    QCategoryAxis *axisX;
    QDateTime *time;
    QValueAxis *axisY;
    QList<QString> list;
    QStringList sublist;

    QTcpServer *server;
    QTcpSocket *socket;
};
#endif // CHARTWIDGET_H
