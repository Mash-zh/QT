#include "addrecorddialog.h"
#include "ui_addrecorddialog.h"
#include "QComboBox"
#include "QStringList"
#include "QDebug"
#include "QSqlDatabase"
#include "QSqlQuery"
AddRecordDialog::AddRecordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecordDialog)
{
    ui->setupUi(this);
    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("information.db");
    if(database.open()){
        qDebug()<<"open";
    }else {
        qDebug()<<"false";
    }

    QString text="SELECT name,score FROM item";
    QSqlQuery query;
    query.prepare(text);
    query.exec();
    if(query.isActive()){
        while(query.next()){
            this->ui->comboBox_2->addItem(query.value(0).toString());
            information += query.value(0).toString()+" "+query.value(1).toString()+",";
        }
        this->ui->label_scoreD->setText("1");
    }
}

AddRecordDialog::~AddRecordDialog()
{
    delete ui;
}

void AddRecordDialog::on_comboBox_2_currentIndexChanged(int index)
{
    QStringList first_information=information.trimmed().split(",");
    QStringList final_information=first_information.at(index).trimmed().split(" ");
    QString text_score=final_information.at(1);
    this->ui->label_scoreD->setText(text_score);
}
