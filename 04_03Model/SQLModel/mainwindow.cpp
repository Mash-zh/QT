#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QSqlRecord"
#include "QSqlError"
#include "QFileDialog"
#include "QStandardItem"
#include "QHeaderView"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("SQLModel.db");
    qDebug()<<db.open();

    QSqlQuery query;
    QString text="CREATE TABLE [record]([name] VARCHAR(1000) NOT NULL, [scord] INT NOT NULL, [tip] VARCHAR(1000));";
    query.prepare(text);
    query.exec();

    this->model = new QSqlTableModel(this, db);
    model->setTable("record");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
//    int width=

    this->ui->tableView->setModel(model);
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    //this->ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);
    for (int i=0;i<3;i++) {
        qDebug()<<this->ui->tableView->columnWidth(i);
    }qDebug()<<this->ui->tableView->geometry();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionad_triggered()
{

    int row=model->rowCount();
    model->insertRow(row);
    qDebug()<<row;
    model->setData(model->index(row,0),10);
    model->setData(model->index(row,1),10);
    if(!model->submitAll()){
        qDebug()<<model->lastError().text();
    }

}













