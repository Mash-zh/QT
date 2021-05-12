#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStandardItemModel *model=new QStandardItemModel;
    model->setHeaderData(0,Qt::Horizontal,"Name");
    model->setHeaderData(1,Qt::Horizontal,"Score");


    model->setItem(0, 0, new QStandardItem("张三"));
    model->setItem(0, 1, new QStandardItem("3"));

    this->ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

