#include "sql.h"
#include "ui_sql.h"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QDebug"
#include "QTextBrowser"
SQL::SQL(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SQL)
{
    ui->setupUi(this);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("sql.db");
    database.open();
    QSqlQuery sql_query;
    sql_query.prepare("INSERT INTO number (name, age)\
                      VALUES (:name, :age);");
    sql_query.bindValue(":name","zhu");
    sql_query.bindValue(":age",21);
    sql_query.exec();
    database.close();

    qDebug()<<this->ui->textBrowser->document()->toPlainText();

}

SQL::~SQL()
{
    delete ui;
}

