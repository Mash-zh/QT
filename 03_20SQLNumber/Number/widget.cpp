#include "widget.h"
#include "ui_widget.h"
#include "QtSql/QSqlDatabase"
#include "QFileDialog"
#include "QSqlQuery"
#include "QDebug"
#include "qstring.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->ui->label->setText("未连接数据库");


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonLink_clicked()
{
    QSqlDatabase datbase=QSqlDatabase::addDatabase("QSQLITE");
    QString fileName=QFileDialog::getOpenFileName(this,"选择连接的数据库文件","",tr("Database(*.db)"));
    datbase.setDatabaseName(fileName);
    if(datbase.open()){
        this->ui->label->setText("数据库连接成功");
    }else {
        this->ui->label->setText("数据库连接失败");
    }
    QSqlQuery query;
    QString strSqlText("UPDATE temperature SET Temperature = :Temperature \
                       WHERE rowid = :rowid");
    query.prepare(strSqlText);
    query.bindValue(":Temperature", 2);

    query.bindValue(":rowid", 3);
    query.exec();
    qDebug()<< query.isActive();
}

void Widget::on_pushButtonAdd_clicked()
{
    QSqlQuery query;
    QString time="temperature";
    QString text="INSERT INTO"+time+"(Time, Temperature) "
                                          "VALUES (:Time, :Temperature)";
    query.prepare(text);
    query.bindValue(":Time",this->ui->lineEditTime->text());
    //query.bindValue(this->ui->lineEditTime->text(),this->ui->lineEditTemperature->text().toDouble());
    query.bindValue(":Temperature",this->ui->lineEditTemperature->text().toDouble());

    query.exec();
    if(query.isActive()){
        this->ui->lineEditTime->clear();
        this->ui->lineEditTemperature->clear();
    }


}

void Widget::on_pushButtonGet_clicked()
{
    QSqlQuery query;
    QString t="temperature";
    QString text="SELECT Time,Temperature FROM "+t;
    query.prepare(text);
    query.exec();
    if(query.isSelect()){
        while(query.next()){

            sub_list=query.value(1).toString();
            this->ui->textBrowser->append(sub_list);
            qDebug()<<sub_list.split(' ');
        }
    }

}
