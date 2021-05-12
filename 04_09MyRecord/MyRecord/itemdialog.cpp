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
}

void ItemDialog::addNewItem()
{
    QString name=this->ui->lineEdit_nameItem->text();
    QString score=this->ui->spinBox->text();
    QString text="INSERT INTO item (name, score) "
                   "VALUES (:name, :score)";
    QSqlQuery query;
    query.prepare(text);
    query.bindValue(":name",name);
    query.bindValue(":score",score.toInt());
    query.exec();
    if(query.isActive()){
        this->ui->lineEdit_nameItem->clear();
        this->ui->spinBox->setValue(0);
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
    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("item.db");
    database.open();
    QString name=this->ui->lineEdit_nameItem->text();
    QString score=this->ui->spinBox->text();
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
//    database.close();
}

void ItemDialog::on_pushButton_cancelItem_clicked()
{
    close();
}
