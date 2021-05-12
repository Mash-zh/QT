#include "itemdialog.h"
#include "ui_itemdialog.h"
#include "QMessageBox"
#include "QSqlQuery"
#include "QDebug"
ItemDialog::ItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemDialog)
{
    ui->setupUi(this);
}

ItemDialog::~ItemDialog()
{
    delete ui;

//    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE");
//    database.setDatabaseName("information.db");
//    if(database.open()){
//        qDebug()<<"itemOpen";
//    }else {
//        qDebug()<<"false";
//    }
//    QSqlQuery query;
//    QString text_query="CREATE TABLE [record]([name] VARCHAR(1000) NOT NULL,[score] INT(10) NOT NULL,[tip] VARCHAR(10000));";
//    query.prepare(text_query);
//    query.exec();
}

void ItemDialog::addNewItem()
{
    QString name=this->ui->lineEdit_nameItem->text();
    QString score=this->ui->lineEdit_scoreItem->text();
    QString text="INSERT INTO item (name, score) "
                   "VALUES (:name, :score)";
    QSqlQuery query;
    query.prepare(text);
    query.bindValue(":name",name);
    query.bindValue(":score",score.toInt());
    query.exec();
    if(query.isActive()){
        this->ui->lineEdit_nameItem->clear();
        this->ui->lineEdit_scoreItem->clear();
    }
}

QString ItemDialog::getItem()
{
    QString text="SELECT name FROM item";
    QSqlQuery query;
    query.prepare(text);
    query.exec();
    if(query.isActive()){
        while(query.next()){
            item_name +=query.value(0).toString()+" ";
        }
    }
    return item_name;
}

void ItemDialog::on_pushButton_okItem_clicked()
{
    QString name=this->ui->lineEdit_nameItem->text();
    QString score=this->ui->lineEdit_scoreItem->text();
    QString information="项目："+name+'\n'+"分数："+score;
    if(name.isEmpty()||score.isEmpty()){
        return;
    }else {
        int ret=QMessageBox::information(this," ",information,"确定","取消");
        if(ret==0){
            /***********保存***********/
            addNewItem();
            getItem();
        }else {
            return;
        }
    }
}

void ItemDialog::on_pushButton_cancelItem_clicked()
{
    close();
}
