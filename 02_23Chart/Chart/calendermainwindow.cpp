#include "calendermainwindow.h"
#include "ui_calendermainwindow.h"
#include "QDateTime"
#include "QDebug"
#include "QMessageBox"

calenderMainWindow::calenderMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::calenderMainWindow)
{
    ui->setupUi(this);

    this->widget=new chartWidget;
    this->time=new QDateTime;
    /***************网络**************/
    this->ip=new QHostInfo;
    showIp();
    /***************图表**************/
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
    axisYMain->setRange(0,40);
    axisXMain->setTitleText("时间");
    axisYMain->setTitleText("温度(℃)");
    chartMain->addAxis(axisXMain,Qt::AlignBottom);
    chartMain->addAxis(axisYMain,Qt::AlignLeft);
    seriesMain->attachAxis(axisXMain);
    seriesMain->attachAxis(axisYMain);
    this->ui->widgetMain->setRenderHint(QPainter::HighQualityAntialiasing);
    this->ui->widgetMain->setChart(chartMain);

}

calenderMainWindow::~calenderMainWindow()
{
    delete ui;
}
/****************打开文件获取信息*********************/
void calenderMainWindow::openFile()
{
    QFile file("温度记录.txt");
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

         QTextStream in(&file);
         while (!in.atEnd()) {
             QString line = in.readLine();
             //qDebug()<<line;
             list.append(line);
         }
         file.close();
}
/*******************第一次查询，处理有数据的日期******************/

/*****************查询点击的日期的数据**************************/
void calenderMainWindow::query(QString date)
{
    for (int i=0;i<list.length();i++) {
        QString line=list.at(i);
        line=line.trimmed();
        subList=line.split(" ");
        if(date==subList.at(0))
        {
            for(int j=1;j<subList.length()-1;j++){
                clickLine=line;

            //qDebug()<<subList.at(j).toInt();
            //series->append(subList.at(j).toInt(),j-1);
            //qDebug()<<subList.at(j).toInt()<<' '<<(j-1);
            }
        }


    }
}
/******************获得各个点的坐标********************/
void calenderMainWindow::getClickLine()
{
    subClickLine=clickLine.split(" ");


}
/****************显示本机IP地址**************/
void calenderMainWindow::showIp()
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

void calenderMainWindow::on_calendarWidget_clicked(const QDate &date)
{
    seriesMain->clear();
    openFile();
    int currentTime = time->currentDateTime().toString("yyyyMMdd").toInt();
    int clickDate = date.toString("yyyyMMdd").toInt();
    if(currentTime-clickDate>0){
        dateTime=date.toString("yyyyMMdd");
        query(dateTime);
        getClickLine();

        seriesMain->append(0,subClickLine.at(1).toInt());
        seriesMain->append(1,subClickLine.at(2).toInt());
        seriesMain->append(2,subClickLine.at(3).toInt());
        seriesMain->append(3,subClickLine.at(4).toInt());
        seriesMain->append(4,subClickLine.at(5).toInt());
        seriesMain->append(5,subClickLine.at(6).toInt());
        seriesMain->append(6,subClickLine.at(7).toInt());
        seriesMain->append(7,subClickLine.at(8).toInt());
        seriesMain->append(8,subClickLine.at(9).toInt());
        seriesMain->append(9,subClickLine.at(10).toInt());
        seriesMain->append(10,subClickLine.at(11).toInt());
        seriesMain->append(11,subClickLine.at(12).toInt());
    }else if(currentTime-clickDate==0){
        widget->show();
    }else{
        QMessageBox::warning(this,"警告","不允许提前添加数据！");
    }
}
/*************关闭事件**************/
void calenderMainWindow::closeEvent(QCloseEvent *event)
{
    int ret=QMessageBox::question(this,"","是否确定退出？","是","否");
    if(ret==0){
        event->accept();
    }else if (ret==1) {
        //hide();
        event->ignore();

}
}

















