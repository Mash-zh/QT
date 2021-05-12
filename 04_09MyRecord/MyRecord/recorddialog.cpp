#include "recorddialog.h"
#include "ui_recorddialog.h"
#include "QComboBox"
#include "QStringList"
#include "QDebug"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QString"
RecordDialog::RecordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordDialog)
{
    ui->setupUi(this);
    ok=false;
    this->ui->pushButton_refresh->setIcon(QIcon(":/fresh.png"));
    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("item.db");
    database.open();
    QString text="SELECT name,score FROM item";
    QSqlQuery query;
    query.prepare(text);
    query.exec();
    current_score=0;
    if(query.isActive()){
        while(query.next()){
            this->ui->comboBox_record->addItem(query.value(0).toString());
            information += query.value(0).toString()+" "+query.value(1).toString()+",";
            current_score += query.value(1).toInt();
        }
        this->ui->label_score->setText("1");
//        this->ui->label_currentScore->setText(QString::number(current_score));
    }
    database.close();
}

RecordDialog::~RecordDialog()
{
    delete ui;
}

void RecordDialog::setOK(bool ok)
{
    this->ok=ok;
}

bool RecordDialog::getOK()
{
    return ok;
}

QString RecordDialog::getName()
{
    return this->ui->comboBox_record->currentText();
}

QString RecordDialog::getScore()
{
    return this->ui->label_score->text();
}

QString RecordDialog::getTip()
{
    return this->ui->plainTextEdit->toPlainText();
}

void RecordDialog::on_pushButton_okRecord_clicked()
{
    setOK(true);
    close();
}

void RecordDialog::on_pushButton_cancelRecord_clicked()
{
    setOK(false);
    close();
}

void RecordDialog::on_comboBox_record_currentIndexChanged(int index)
{
    if(information.isEmpty()){
        return;
    }else{
        QStringList information_list=information.trimmed().split(",").at(index).trimmed().split(" ");
        QString score_text=information_list.at(1);
        this->ui->label_score->setText(score_text);
        //qDebug()<<information_list;
    }

}

void RecordDialog::on_pushButton_refresh_clicked()
{
    information.clear();
    for (int i=this->ui->comboBox_record->count();i>0;i--) {
        this->ui->comboBox_record->removeItem(i);
    }
    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("item.db");
    database.open();
    QString text="SELECT name,score FROM item";
    QSqlQuery query;
    query.prepare(text);
    query.exec();
    current_score=0;
    if(query.isActive()){
        while(query.next()){
            this->ui->comboBox_record->addItem(query.value(0).toString());
            information += query.value(0).toString()+" "+query.value(1).toString()+",";
            current_score += query.value(1).toInt();
        }
        this->ui->comboBox_record->removeItem(1);
        this->ui->label_score->setText("1");
    }
//    database.close();
}
