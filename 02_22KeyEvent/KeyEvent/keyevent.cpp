#include "keyevent.h"
#include "ui_keyevent.h"
#include "QDebug"
keyEvent::keyEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::keyEvent)
{
    ui->setupUi(this);
    this->palette=new QPalette;

    this->painter=new QPainter;
    QBrush brush(Qt::blue,Qt::RadialGradientPattern);



   /********************************************************
     brush->setColor(Qt::blue);
     QPalette pal = window()->palette();
     pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
     pal.setColor(QPalette::WindowText, QRgb(0x404044));
     window()->setPalette(pal);
    //painter->setBrush(brush);
    //palette->setColor(QPalette::Window,Qt::black);
    //palette->setColor(QPalette::WindowText, QRgb(0xd6d6d6));
    ****************************************************/
    this->series=new QLineSeries;
    this->chart=new QChart;
    this->axisX=new QValueAxis;
    this->axisY=new QValueAxis;

    *series<<QPointF(2,0)<<QPointF(3,2);
    chart->addSeries(series);

    axisX->setRange(0,10);
    axisY->setRange(0,10);
    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    chart->setBackgroundBrush(brush);
    //this->ui->widget->setBackgroundBrush(brush);
    this->ui->widget->setChart(chart);

    //this->calendar=new QCalendarWidget;
    //connect(this->ui->widget,SIGNAL(mousePressPoint(Qpoint)),this,SLOT(onMousePressPoint(QPoint)));
}

keyEvent::~keyEvent()
{
    delete ui;
}

void keyEvent::mousePressEvent(QMouseEvent *event)
{
    QPoint point=event->pos();
    //emit mousePressPoint(point);
    qDebug()<<point;
    //qDebug()<<chart->mapToValue(event->pos())+QPoint(-0.5,0.8);
}

/******************************************************
void keyEvent::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_A:
        qDebug()<<"Key_Left"; break;
    case Qt::Key_Right:
        qDebug()<<"Key_Right"; break;
    case Qt::Key_Up:
        qDebug()<<"Key_Up"; break;
    case Qt::Key_Down:
        qDebug()<<"Key_Down"; break;
    case Qt::Key_Plus:
        qDebug()<<"+";break;
    }
}


void keyEvent::on_calendarWidget_clicked(const QDate &date)
{
    qDebug()<<date;
    qDebug()<<date.toString("yyyy.MM.dd ddd");
}

void keyEvent::onMousePressPoint(QPoint point)
{
    QPointF pt=this->ui->widget->chart()->mapToValue(point);
    //this->ui->label->setText(QString::asprintf("x=%.1f,y=%.2f",pt.x(),pt.y()));
    qDebug()<<pt;
}
******************************************************/
