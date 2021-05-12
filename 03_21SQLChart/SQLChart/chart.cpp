#include "chart.h"
#include "ui_chart.h"
#include "QPainter"
#include "QtSql/QSqlDatabase"
#include "QFileDialog"
#include "QtSql/QSqlQuery"
#include "qdebug.h"
#include "QMessageBox"
#include "QDateTime"
#include "QPointF"
Chart::Chart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chart)
{
    ui->setupUi(this);
    sum=0;
    /************网络***********/
    this->server=new QTcpServer;
    this->socket=new QTcpSocket;
    connect(server,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
    /************图表***********/
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
    /**************数据库**************/
    QSqlDatabase datbase=QSqlDatabase::addDatabase("QSQLITE");
    //QString fileName=QFileDialog::getOpenFileName(this,"选择连接的数据库文件","",tr("Database(*.db)"));
    datbase.setDatabaseName("F:/Code/QT for Android/03_21SQLChart/build-SQLChart-Desktop_Qt_5_14_1_MinGW_32_bit-Release/SQLTemperature.db");
    datbase.open();
//    if(datbase.open()){
//        QMessageBox::information(this,"","数据库连接成功");
//    }else {
//        QMessageBox::information(this,"","数据库连接失败");
//    }

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

Chart::~Chart()
{
    delete ui;
}

/**************网络**************/
void Chart::on_pushButton_listen_clicked()
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
void Chart::onReadyRead()
{
    QByteArray arry=socket->readAll();
    double message=arry.toDouble();
    QDateTime time;
    QString currentTime = time.currentDateTime().toString("yyyyMMdd");
    currentTime="T"+currentTime;
    //qDebug()<<currentTime;
    sum=series->count();
    if(sum<=11){
        series->append(sum,message);

        QSqlQuery query;
        QString test_insert="INSERT INTO "+currentTime+"(Temperature)"
                                                             "VALUES (:Temperature)";
        query.prepare(test_insert);
        query.bindValue(":Temperature",message);
        query.exec();
    }else{
        QMessageBox::warning(this,"警告","禁止再次添加数据");
    }

}

void Chart::onNewConnection()
{
    if(server->hasPendingConnections()){
        socket=server->nextPendingConnection();
        connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    }
}

void Chart::on_pushButton_insert_clicked()
{
    double temperature=this->ui->lineEdit->text().toDouble();
    int time_insert=this->ui->comboBox_time->currentIndex();
    time_insert=time_insert+1;
    //qDebug()<<time_insert;
    QDateTime time;
    QString currentTime = time.currentDateTime().toString("yyyyMMdd");
    currentTime="T"+currentTime;
    if(this->ui->lineEdit->text().isEmpty()){
        return;
    }else {
        QSqlQuery query;
        QString test_update="UPDATE "+currentTime+" SET Temperature = :Temperature \
                       WHERE rowid = :rowid";
        query.prepare(test_update);
        query.bindValue(":rowid",time_insert);
        query.bindValue(":Temperature",temperature);
        query.exec();
        if(query.isActive()){
            this->ui->lineEdit->clear();
        }
        /***插入***/
        series->replace(time_insert-1,time_insert-1,temperature);
    }
}
