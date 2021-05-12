#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QString"
#include "QPixmap"
#include "QDir"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->scene = new QGraphicsScene;
    //设置tab标签样式
    this->ui->tabWidget->setTabShape(QTabWidget::Triangular);

    //数据库
    database = QSqlDatabase::addDatabase("QSQLITE");
    this->model = new QSqlQueryModel;
    database.setDatabaseName("image.db");
    database.open();

    QSqlQuery query;

    query.prepare("CREATE TABLE image(\
                  ID INT(20),\
                  NAME CHAR(50)\
                  );");
    query.exec();



    model->setQuery("SELECT * FROM image WHERE name = 1 ");
    model->setHeaderData(0, Qt::Horizontal, tr("x_left"));
    model->setHeaderData(1, Qt::Horizontal, tr("y_top"));
    model->setHeaderData(2, Qt::Horizontal, tr("y_bottom"));
    this->ui->tableView->setModel(model);

    QDir dir("E:/picture/1");
    QStringList filters;
    filters << "*.jpg";
//    dir.setNameFilters(filters);
//    dir.setFilter(QDir::Files);
//    dir.setSorting(QDir::Time);
    qDebug()<< dir.entryList(filters, QDir::Files, QDir::Name |QDir::Reversed);




//    QString Path = "E:/picture/Output/P21040907330210.jpg";
    QString Path = ":/new/prefix1/OIP.jpg";
    QPixmap pixMap(Path);
    scene->addPixmap(pixMap);
    int width = this->ui->graphicsView->width();
    int height = this->ui->graphicsView->height();
    pixMap =  pixMap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    this->ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

