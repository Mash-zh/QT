#include "database.h"
#include "ui_database.h"
#include "QDebug"
#include "QFileDialog"
#include "QSqlQuery"
Database::Database(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Database)
{
    ui->setupUi(this);
    //this->SqlDatabase=new QSqlDatabase;
    //qDebug()<<QSqlDatabase::drivers();


}

Database::~Database()
{
    delete ui;

}


void Database::on_pushButton_open_clicked()
{
    QString aFile=QFileDialog::getOpenFileName(this,"打开数据库","","SQLite数据库(*.db *.db3)");
    if(aFile.isEmpty())
        return;
    DB=QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName(aFile);
    if(!DB.open()){
        qDebug()<<"OpenError";
        return;
    }
    QSqlQuery query;
    int i=1001;
    QString sqlText=QString("CREATE TABLE [first2]([name] VARCHAR(5, 0) NOT NULL, \
  [ID] INT(6, 0) NOT NULL);");
    query.prepare(sqlText);
    query.exec();



}
/************************************************* QString strSqlText = QString("CREATE TABLE [first_test]([name_] VARCHAR(5) NOT NULL,\
  [ID_] INT(6) NOT NULL)\
    )");
    QSqlQuery qsQuery = QSqlQuery(DB);
    QString strSqlText = QString("CREATE TABLE ConfigInfo ( [DicomFolderPath]       VARCHAR(256), \
[OpDicomFilePath]    VARCHAR(256) \
                                 );");
    qsQuery.prepare(strSqlText);
    qsQuery.exec();
    strSqlText = "INSERT INTO ConfigInfo (DicomFolderPath,  OpDicomFilePath) \
                 VALUES (:DicomFolderPath, :OpDicomFilePath)";
    qsQuery.prepare(strSqlText);
    qsQuery.bindValue(":DicomFolderPath", "");
    qsQuery.bindValue(":OpDicomFilePath", "");
    qsQuery.exec();
 *************************************************/
