#include "additem.h"
#include "ui_additem.h"
#include "QMessageBox"
#include "QSqlQuery"
#include "QDebug"
AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::addNewItem()
{
    QString name=this->ui->lineEdit_name->text();
    QString score=this->ui->lineEdit_score->text();
    QString text="INSERT INTO item (name, score) "
                   "VALUES (:name, :score)";
    QSqlQuery query;
    query.prepare(text);
    query.bindValue(":name",name);
    query.bindValue(":score",score.toInt());
    query.exec();
    if(query.isActive()){
        this->ui->lineEdit_name->clear();
        this->ui->lineEdit_score->clear();
    }
}

QString AddItem::getItem()
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

void AddItem::on_pushButton_ok_clicked()
{
    QString name=this->ui->lineEdit_name->text();
    QString score=this->ui->lineEdit_score->text();
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

void AddItem::on_pushButton_cancel_clicked()
{
    close();
}
