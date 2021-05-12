#include "recorddialog.h"
#include "ui_recorddialog.h"
#include "QComboBox"
#include "QStringList"
#include "QDebug"
#include "QSqlDatabase"
#include "QSqlQuery"
RecordDialog::RecordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordDialog)
{
    ui->setupUi(this);

    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("information.db");
    if(database.open()){
        qDebug()<<"open";
    }else {
        qDebug()<<"false";
    }
    QSqlQuery query;
    //    QString text_query="CREATE TABLE [item]([name] VARCHAR(1000) NOT NULL,[score] INT(10) NOT NULL);";
    //    query.prepare(text_query);
    //    query.exec();

    QString text="SELECT name,score FROM item";
    query.prepare(text);
    query.exec();
    if(query.isActive()){
        while(query.next()){
            this->ui->comboBox_record->addItem(query.value(0).toString());
            information += query.value(0).toString()+" "+query.value(1).toString()+",";
        }

    }
    this->ui->label_scoreRecord->setText("1");
}

RecordDialog::~RecordDialog()
{
    delete ui;
}

QString RecordDialog::getName()
{
    return this->ui->comboBox_record->currentText();
}

QString RecordDialog::getScore()
{
    return this->ui->label_scoreRecord->text();
}

QString RecordDialog::getTip()
{
    return this->ui->plainTextEdit_record->toPlainText();
}

void RecordDialog::on_comboBox_record_currentIndexChanged(int index)
{
    QStringList first_information=information.trimmed().split(",");
    QStringList final_information=first_information.at(index).trimmed().split(" ");
    QString text_score=final_information.at(1);
    this->ui->label_scoreRecord->setText(text_score);
}
