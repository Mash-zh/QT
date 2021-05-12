#include "chartwidget.h"
#include "ui_chartwidget.h"
#include "QString"
#include "QDebug"
#include "QMessageBox"
#include "QFile"

chartWidget::chartWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chartWidget)
{
    ui->setupUi(this);
    x=-1; z=0; c=0; sum=0;
    information.isEmpty();
    dateInformation.isEmpty();

    /*********************
    if(sublist.length()>0)
    {
        this->ui->pushButton_show->setVisible(true);
    }else{
        this->ui->pushButton_show->setVisible(false);
    }
    *********************/
    this->time=new QDateTime;
    dateInformation= time->currentDateTime().toString("yyyyMMdd")+" ";

    /************网络***********/
    this->server=new QTcpServer;
    this->socket=new QTcpSocket;
    connect(server,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
    /************图表***********/
    this->series=new QLineSeries;
    this->barSeries=new QBarSeries;
    this->chart=new QChart;
    this->barSet=new QBarSet("温度");
    this->axisX=new QCategoryAxis;
    this->axisY=new QValueAxis;

    series->setPointLabelsVisible(true);

    series->setPointLabelsFormat("  @yPoint℃");
    barSeries->append(barSet);
    barSeries->setBarWidth(5);
openFile();
    chart->addSeries(series);
    chart->addSeries(barSeries);

    axisX->setRange(0,12);
    for (int i=0;i<13;i++) {
            axisX->append(QString::number(2*i)+":00",i);
    }
    axisY->setRange(0,40);
    axisX->setTitleText("时间");
    axisY->setTitleText("温度(℃)");
    //axisX->setTickCount(12);//设置显示的时间个数
    //axisX->setLabelFormat("%d");
    chart->addAxis(axisX,Qt::AlignBottom);
    //chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);
    series->attachAxis(axisX);
    //series->attachAxis(axisX);
    series->attachAxis(axisY);
    this->ui->widget->setRenderHint(QPainter::HighQualityAntialiasing);
    this->ui->widget->setChart(chart);

}

chartWidget::~chartWidget()
{
    delete ui;
}

int chartWidget::getX()
{
    x+=1;
    return x;
}

double chartWidget::getY()
{
    y=message;
    return y;
}
/*************************文件保存********************************/
void chartWidget::saveFile()
{
    //qDebug()<<sum;
    if(sum>=11){
        QFile file("温度记录.txt");
             if (!file.open(QIODevice::Append | QIODevice::Text))
                 return;

             QTextStream out(&file);
             out << historyLine+information<< "\n";
    }else{
        QFile file("温度记录草稿.txt");
             if (!file.open(QIODevice::Append |QIODevice::QIODevice::ReadWrite | QIODevice::Text))
                 return;

             QTextStream out(&file);
             if(sum==0){
                 out <<dateInformation+""+information<< "\n";
             }else {
                out <<historyLine+""+information<< "\n";
                }
    }

}

/*********************先询问是否关闭界面，然后保存文件*******************/
void chartWidget::closeEvent(QCloseEvent *event)
{

    //qDebug()<<information;
    //qDebug()<<dateInformation;
    int ret=QMessageBox::question(this," ","数据已保存，是否退出此界面？","是","否");
    if(ret==0){


        event->accept();
    }else if (ret==1) {
        event->ignore();
}
}

/********************添加坐标
void chartWidget::on_pushButton_add_clicked()
{
    addNewCoordinate();//添加新坐标
}
*********************/


/****************打开文件获取信息*********************/
void chartWidget::openFile()
{
    QFile file("温度记录草稿.txt");
         if (!file.open(QIODevice::QIODevice::ReadWrite | QIODevice::Text))
             return;

         QTextStream in(&file);
         while (!in.atEnd()) {
             QString line = in.readLine();
             list.append(line);
         }
         file.close();
        if(list.length()==0){
            return ;
        }else{
            QString line= list.at(list.length()-1);

            historyLine=line;
            line=line.trimmed();
            sublist=line.split(" ");
           //qDebug()<<sublist;
            if(sublist.at(0)==time->currentDateTime().toString("yyyyMMdd")){
                for (int i=1;i<sublist.length();i++) {
                     series->append(i-1,sublist.at(i).toDouble());
                 }
            }else{
                return;
            }
        }


}
/***************添加新坐标
void chartWidget::addNewCoordinate()
{   sum=series->count();
    if(sum<=11){
        //int getx=getX();
        series->append(sum,getY());
        barSet->append(sum);
    }else{
		QMessageBox::warning(this,"警告","禁止再次添加数据");
	}
        z+=1;
        //qDebug()<<z;

}****************/
/***************继续添加坐标
void chartWidget::addContinueCoordinate()
{
    int cY=this->ui->lineEdit->text().toInt();
    series->append(sublist.length(),cY);
    //qDebug()<<sublist.length();
}****************/
/***************显示历史数据
void chartWidget::on_pushButton_show_clicked()
{
    c=c+1;
    if(c==1){
        for (int i=0;i<sublist.length();i++) {
            series->append(i,sublist.at(i).toInt());
        }
    }else{
        QMessageBox::warning(this,"警告","以显示今日全部历史数据");
    }
    this->ui->pushButton_show->setVisible(false);
}
**************/

void chartWidget::on_pushButton_listen_clicked()
{
    if(this->ui->pushButton_listen->text()=="开始监听"){
        bool state=this->server->listen(QHostAddress::Any,60000);
        if(state){
            this->ui->label_listen->setText("正在监听");
        }else{
            this->ui->label_listen->setText("监听失败");
        }
        this->ui->pushButton_listen->setText("停止监听");
    }else{
        this->server->close();
        this->ui->label_listen->setText("停止监听");
        this->ui->pushButton_listen->setText("开始监听");
    }
}

void chartWidget::onReadyRead()
{
    sum=series->count();
    QByteArray arry=socket->readAll();
    message=arry.toDouble();
    if(sum<=11){
        //int getx=getX();
        series->append(sum,getY());
        //barSet->append(getx);
        information+=QString::number(message)+" ";
        saveFile();
        //qDebug()<<information;
    }else{
        QMessageBox::warning(this,"警告","禁止再次添加数据");
    }
        z+=1;
}

void chartWidget::onNewConnection()
{
    if(server->hasPendingConnections()){
        socket=server->nextPendingConnection();
        connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    }
}













