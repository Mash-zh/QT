#include "transform.h"
#include "ui_transform.h"
#include "QFileDialog"
#include "QPainter"
#include "QPixmap"
#include "QBitmap"
#include "QDebug"
Transform::Transform(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Transform)
{
    ui->setupUi(this);

}

Transform::~Transform()
{
    delete ui;
}


void Transform::on_pushButtonAddPicture_clicked()
{
    //QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "", tr("*.jpeg*.xbm*.xpm*.png *.jpg *.bmp"));
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/",tr("Images (*.png *.xpm *.jpg)"));
    //qDebug()<<fileName;

}

void Transform::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
     //QRectF target(50, 50.0,300,300);
     QRectF target1(50,50,this->ui->widget->width(),this->ui->widget->height());
     QRectF source(0.0, 0.0,1080,1400);
     //QImage image(fileName);
     QPixmap pixmap(fileName);
    //painter.drawImage(target,image);
    painter.drawPixmap(target1,fileName,source);
    //pixmap.createHeuristicMask(true);
    pixmap.setMask(pixmap.createHeuristicMask(true));
    //image.createHeuristicMask(true);
    //pixmap.save("new.png");
    pixmap.save(save_fileName);

}

void Transform::on_pushButtonSavePicture_clicked()
{
    save_fileName=QFileDialog::getSaveFileName(this,tr("Save Image"),"/", tr("Images (*.png *.xpm *.jpg)"));

}
