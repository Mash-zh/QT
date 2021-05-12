#ifndef CALENDERMAINWINDOW_H
#define CALENDERMAINWINDOW_H

#include <QMainWindow>
#include "chartwidget.h"
#include "QtCharts/QChart"
#include "QtCharts/QLineSeries"
#include "QtCharts/QBarSet"
#include "QtCharts/QBarSeries"
#include "QtCharts/QCategoryAxis"
#include "QtCharts/QValueAxis"
#include "QDateTime"
#include "QList"
#include "QStringList"
#include "QDate"
#include "QtNetwork/QHostInfo"

using namespace QtCharts;
namespace Ui {
class calenderMainWindow;
}

class calenderMainWindow : public QMainWindow
{
    Q_OBJECT
protected:
   void closeEvent(QCloseEvent *event);
public:
    explicit calenderMainWindow(QWidget *parent = nullptr);
    ~calenderMainWindow();

    void openFile();
    void query(QString date);
    //bool firstQuery(QString date);
    QString dateTime;
    void getClickLine();
    void showIp();
private slots:
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::calenderMainWindow *ui;
    chartWidget *widget;

    QLineSeries *seriesMain;
    QChart *chartMain;
    QCategoryAxis *axisXMain;
    QValueAxis *axisYMain;

    QDateTime *time;
    QList<QString> list;
    QStringList subList;
    QString clickLine;
    QStringList subClickLine;

    QHostInfo *ip;
};

#endif // CALENDERMAINWINDOW_H











