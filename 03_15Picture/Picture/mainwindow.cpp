#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include "QPixmap"
#include "QBitmap"
#include "QDebug"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPixmap pixmap(":/new/prefix1/down.png");
    QPixmap pixmap1(":/new/prefix1/up.png");

    QImage image = pixmap.toImage();
    QImage image_mask=image.createHeuristicMask(false);
    //pixmap.createHeuristicMask(true);
    pixmap.setMask(pixmap.createHeuristicMask(true));
    pixmap1.setMask(pixmap1.createHeuristicMask());
    QPainter painter(this);
    pixmap.save("down.png");
    pixmap1.save("up.png");
    painter.drawPixmap(0,0,pixmap);
    painter.drawPixmap(200,0,pixmap1);
    painter.drawImage(400,0,image_mask);
}

