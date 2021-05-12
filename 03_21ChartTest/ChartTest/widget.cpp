#include "widget.h"
#include "ui_widget.h"
#include "QtSql/QSqlDatabase"
#include "QFileDialog"
#include "QtSql/QSqlQuery"
#include "qdebug.h"
#include "QMessageBox"
#include "QDateTime"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    sum=0;

    this->series=new QLineSeries;
    this->barSeries=new QBarSeries;
    this->qchart=new QChart;
    this->barSet=new QBarSet("温度");
    this->axisX=new QCategoryAxis;
    this->axisY=new QValueAxis;

    series->setPointLabelsVisible(true);

    series->setPointLabelsFormat("  @yPoint℃");
    barSeries->append(barSet);
    barSeries->setBarWidth(5);
    qchart->addSeries(series);
    qchart->addSeries(barSeries);

    axisX->setRange(0,12);
    for (int i=0;i<13;i++) {
        axisX->append(QString::number(2*i)+":00",i);
    }
    axisY->setRange(0,100);
    axisX->setTitleText("时间");
    axisY->setTitleText("温度(℃)");
    //axisX->setTickCount(12);//设置显示的时间个数
    //axisX->setLabelFormat("%d");
    qchart->addAxis(axisX,Qt::AlignBottom);
    //chart->addAxis(axisX,Qt::AlignBottom);
    qchart->addAxis(axisY,Qt::AlignLeft);
    series->attachAxis(axisX);
    //series->attachAxis(axisX);
    series->attachAxis(axisY);
    this->ui->widget->setRenderHint(QPainter::HighQualityAntialiasing);
    this->ui->widget->setChart(qchart);

    QSqlDatabase datbase=QSqlDatabase::addDatabase("QSQLITE");
    QString fileName=QFileDialog::getOpenFileName(this,"选择连接的数据库文件","",tr("Database(*.db)"));
    datbase.setDatabaseName(fileName);
    if(datbase.open()){
        QMessageBox::information(this,"","数据库连接成功");
    }else {
        QMessageBox::information(this,"","数据库连接失败");
    }

    QDateTime time;
    QString currentTime = time.currentDateTime().toString("yyyyMMdd");
    currentTime="T"+currentTime;
    QString text_create="CREATE TABLE "+currentTime+"([Temperature] DOUBLE);";
    QSqlQuery query;
    query.prepare(text_create);
    query.exec();

    QString text_query="SELECT rowid, Temperature FROM "+currentTime;

    query.prepare(text_query);
    query.exec();
    if(query.isSelect()){
        while (query.next()) {
            series->append(query.value(0).toDouble()-1,query.value(1).toDouble());
        }
    }else {
         qDebug()<<"false";
}

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{   QDateTime time;
    QString currentTime = time.currentDateTime().toString("yyyyMMdd");
    currentTime="T"+currentTime;
    //qDebug()<<currentTime;
    sum=series->count();
    series->append(sum,this->ui->lineEdit->text().toDouble());

    QSqlQuery query;
    QString test_insert="INSERT INTO "+currentTime+"(Temperature)"
                                                 "VALUES (:Temperature)";
    query.prepare(test_insert);
    query.bindValue(":Temperature",this->ui->lineEdit->text().toDouble());
    query.exec();
    if(query.isActive()){
        this->ui->lineEdit->clear();
    }
}
