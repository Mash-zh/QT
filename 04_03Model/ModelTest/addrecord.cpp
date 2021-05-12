#include "addrecord.h"
#include "ui_addrecord.h"
#include "QComboBox"
#include "QStringList"
#include "QDebug"
#include "QSqlDatabase"
#include "QSqlQuery"
AddRecord::AddRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecord)
{
    ui->setupUi(this);

    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("information.db");
    database.open();

    QString text="SELECT name,score FROM item";
    QSqlQuery query;
    query.prepare(text);
    query.exec();
    if(query.isActive()){
        while(query.next()){
            this->ui->comboBox->addItem(query.value(0).toString());
            information += query.value(0).toString()+" "+query.value(1).toString()+",";
        }
        this->ui->label_score->setText("1");
    }

}

AddRecord::~AddRecord()
{
    delete ui;
}

void AddRecord::on_comboBox_currentIndexChanged(int index)
{
    QStringList first_information=information.trimmed().split(",");
    QStringList final_information=first_information.at(index).trimmed().split(" ");
    QString text_score=final_information.at(1);
    this->ui->label_score->setText(text_score);
}
QString AddRecord::getName()
{
    return this->ui->comboBox->currentText();
}

QString AddRecord::getScore()
{
    return this->ui->label_score->text();
}

QString AddRecord::getTip()
{
    return this->ui->plainTextEdit->toPlainText();

}

