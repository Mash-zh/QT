#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->itemDialog=new ItemDialog;
    this->recordDialog=new RecordDialog;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_addRecord_triggered()
{
    recordDialog->exec();
}

void MainWindow::on_action_addItem_triggered()
{
    itemDialog->exec();
}
