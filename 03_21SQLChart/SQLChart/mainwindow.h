#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QDateTime"
#include "QList"
#include "QtCharts/QChart"
#include "QtCharts/QLineSeries"
#include "QtCharts/QBarSet"
#include "QtCharts/QBarSeries"
#include "QtCharts/QCategoryAxis"
#include "QtCharts/QValueAxis"
#include "QtNetwork/QHostInfo"
#include "chart.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace QtCharts;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString query(QString dateTime);

    void showIP();
private slots:
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::MainWindow *ui;

    Chart *chart;

    QDateTime *time;

    QLineSeries *seriesMain;
    QChart *chartMain;
    QCategoryAxis *axisXMain;
    QValueAxis *axisYMain;

    QHostInfo *ip;
};
#endif // MAINWINDOW_H
