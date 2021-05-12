#ifndef KEYEVENT_H
#define KEYEVENT_H

#include <QWidget>
#include "QAbstractScrollArea"
#include "QKeyEvent"
#include "QtCharts/QLineSeries"
#include "QtCharts/QChart"
#include "QtCharts/QValueAxis"
#include "QCalendarWidget"
#include "QPalette"
#include "QBrush"
#include "QPainter"
using namespace QtCharts;
QT_BEGIN_NAMESPACE
namespace Ui { class keyEvent; }
QT_END_NAMESPACE

class keyEvent : public QWidget
{
    Q_OBJECT

public:
    keyEvent(QWidget *parent = nullptr);
    ~keyEvent();
protected:
    //void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    //void on_calendarWidget_clicked(const QDate &date);
    //void onMousePressPoint(QPoint point);
signals:
    //void mousePressPoint(QPoint point);
private:
    Ui::keyEvent *ui;
    /****************************************************/
    QLineSeries *series;
    QChart *chart;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QPalette *palette;

    QPainter *painter;

    //QCalendarWidget *calendar;
};
#endif // KEYEVENT_H
