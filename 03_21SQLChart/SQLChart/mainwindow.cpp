#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QMessageBox"
#include "QString"
#include "QSqlQuery"
#include "QFileDialog"
#include "QPainter"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->chart=new Chart;
    /***************网络**************/
    this->ip=new QHostInfo;
    showIP();
    /************数据库连接************/
    //SQLTemperature
    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE");
    //QString fileName=QFileDialog::getOpenFileName(this,"选择连接的数据库文件","",tr("Database(*.db)"));
    database.setDatabaseName("F:/Code/QT for Android/03_21SQLChart/build-SQLChart-Desktop_Qt_5_14_1_MinGW_32_bit-Release/SQLTemperature.db");
    database.open();
//    if(database.open()){
//        QMessageBox::information(this,"","数据库连接成功");
//    }else {
//        QMessageBox::information(this,"","数据库连接失败");
//}
    /************图表显示************/
    this->seriesMain=new QLineSeries;
    this->chartMain=new QChart;
    this->axisXMain=new QCategoryAxis;
    this->axisYMain=new QValueAxis;
    seriesMain->setPointLabelsVisible(true);
    seriesMain->setPointLabelsFormat("  @yPoint℃");
    //seriesMain->
    chartMain->addSeries(seriesMain);

    axisXMain->setRange(0,12);
    for (int i=0;i<13;i++) {
        axisXMain->append(QString::number(2*i)+":00",i);
    }
    axisYMain->setRange(0,100);
    axisXMain->setTitleText("时间");
    axisYMain->setTitleText("温度(℃)");
    chartMain->addAxis(axisXMain,Qt::AlignBottom);
    chartMain->addAxis(axisYMain,Qt::AlignLeft);
    seriesMain->attachAxis(axisXMain);
    seriesMain->attachAxis(axisYMain);
    this->ui->widgetMain->setRenderHint(QPainter::HighQualityAntialiasing);
    this->ui->widgetMain->setChart(chartMain);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    Q_UNUSED(date);
    seriesMain->clear();
    QSqlQuery query;
    int currentTime = time->currentDateTime().toString("yyyyMMdd").toInt();
    int clickDate = date.toString("yyyyMMdd").toInt();
    /**************显示所选择的日期的数据**************/
    if(currentTime-clickDate>0){
        QString dateTime="T"+date.toString("yyyyMMdd");
        QString text="SELECT rowid,Temperature FROM "+dateTime;
        query.prepare(text);
        query.exec();
        if(query.isSelect()){
            while(query.next()){//创建series
                QString x=query.value(0).toString();
                QString temperature_date=query.value(1).toString();
                this->seriesMain->append(x.toDouble()-1,temperature_date.toDouble());
            }
        }else{
            QMessageBox::warning(this,"警告","此日没有录入温度数据");
        }
    }
    /****************添加当日的数据****************/
    else if (currentTime-clickDate==0) {
        chart->show();
    }else {
       QMessageBox::warning(this,"警告","不允许提前添加数据！");
}

}

/**************显示IP地址**************/
void MainWindow::showIP()
{
    QString host_name=ip->localHostName();
    this->ui->textBrowser->append("本机名称："+host_name);
    QHostInfo addinfo=ip->fromName(host_name);
    QList<QHostAddress> addlist=addinfo.addresses();
    if(!addlist.isEmpty()){
        this->ui->textBrowser->append("本机IP地址：");
        for (int i=0;i<addlist.count();i++) {
            QHostAddress aHost=addlist.at(i);
            this->ui->textBrowser->append(aHost.toString());
        }
    }
}
