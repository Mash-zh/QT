#include "file.h"
#include "ui_file.h"
#include "QStringList"
#include "QDebug"
#include "QFileDialog"
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/core/core.hpp>
//#include <iostream>

//using namespace cv;
using namespace std;

File::File(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::File)
{
    ui->setupUi(this);
    this->dir = new QDir("/home/zhu/ftp");
    this->timer = new QTimer();
    nameFilters << "*.jpg" << "*.png";
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    timer->start(10000);
    QPixmap pix,pix_inform,pix_picture,pix_zhusu,pix_ICBR;
    pix.load("/home/zhu/Code/Qt/09_23File/file/校徽.png");
    pix_inform.load("/home/zhu/ftp/InitializePicture/1.jpg");
    pix_picture.load("/home/zhu/ftp/InitializePicture/1.jpg");
    pix_zhusu.load("/home/zhu/ftp/tmp/竹笋.png");
    pix_ICBR.load("/home/zhu/ftp/tmp/ICBR.png");
    this->ui->label_picture_an->setPixmap(pix);
    this->ui->label_picture->setPixmap(pix_picture);
    this->ui->label_information->setPixmap(pix_inform);
    this->ui->label->setPixmap(pix_zhusu);
    this->ui->label_ICBR->setPixmap(pix_ICBR);
    /**************显示图片大小的自适应**************/
    this->ui->label_picture_an->setScaledContents(true);
    this->ui->label_picture->setScaledContents(true);
    this->ui->label_information->setScaledContents(true);
    this->ui->label->setScaledContents(true);
    this->ui->label_ICBR->setScaledContents(true);
    /*************************label************************/
    /**************内容
    this->ui->label_1->setText("编号");
    this->ui->label_2->setText("直径(cm)");
    this->ui->label_3->setText("高(m)");
    this->ui->label_4->setText("①");
    this->ui->label_5->setText("1");
    this->ui->label_6->setText("1");
    this->ui->label_7->setText("②");
    this->ui->label_8->setText("1");
    this->ui->label_9->setText("1");
    this->ui->label_10->setText("③");
    this->ui->label_11->setText("1");
    this->ui->label_12->setText("1");
    this->ui->label_13->setText("④");
    this->ui->label_14->setText("1");
    this->ui->label_15->setText("1");
    **************/
    /**************居中
    this->ui->label_1->setAlignment(Qt::AlignHCenter);
    this->ui->label_2->setAlignment(Qt::AlignHCenter);
    this->ui->label_3->setAlignment(Qt::AlignHCenter);
    this->ui->label_4->setAlignment(Qt::AlignHCenter);
    this->ui->label_5->setAlignment(Qt::AlignHCenter);
    this->ui->label_6->setAlignment(Qt::AlignHCenter);
    this->ui->label_7->setAlignment(Qt::AlignHCenter);
    this->ui->label_8->setAlignment(Qt::AlignHCenter);
    this->ui->label_9->setAlignment(Qt::AlignHCenter);
    this->ui->label_10->setAlignment(Qt::AlignHCenter);
    this->ui->label_11->setAlignment(Qt::AlignHCenter);
    this->ui->label_12->setAlignment(Qt::AlignHCenter);
    this->ui->label_13->setAlignment(Qt::AlignHCenter);
    this->ui->label_14->setAlignment(Qt::AlignHCenter);
    this->ui->label_15->setAlignment(Qt::AlignHCenter);

    this->ui->label_1->setAlignment(Qt::AlignVCenter);
    this->ui->label_2->setAlignment(Qt::AlignVCenter);
    this->ui->label_3->setAlignment(Qt::AlignVCenter);
    this->ui->label_4->setAlignment(Qt::AlignVCenter);
    this->ui->label_5->setAlignment(Qt::AlignVCenter);
    this->ui->label_6->setAlignment(Qt::AlignVCenter);
    this->ui->label_7->setAlignment(Qt::AlignVCenter);
    this->ui->label_8->setAlignment(Qt::AlignVCenter);
    this->ui->label_9->setAlignment(Qt::AlignVCenter);
    this->ui->label_10->setAlignment(Qt::AlignVCenter);
    this->ui->label_11->setAlignment(Qt::AlignVCenter);
    this->ui->label_12->setAlignment(Qt::AlignVCenter);
    this->ui->label_13->setAlignment(Qt::AlignVCenter);
    this->ui->label_14->setAlignment(Qt::AlignVCenter);
    this->ui->label_15->setAlignment(Qt::AlignVCenter);
    **************/

}

File::~File()
{
    delete ui;
}

cv::Mat rotateImage(const cv::Mat& src, cv::Point2f anchor_pt, double angle)
{
    cv::Mat rot_mat = cv::getRotationMatrix2D(anchor_pt, angle, 1.0);
    cv::Mat dst;
    cv::warpAffine(src, dst, rot_mat, src.size());

    return dst;
}

//***************Otsu算法通过求类间方差极大值求自适应阈值******************
int OtsuAlgThreshold(const Mat image)
{
    if (image.channels() != 1)
    {
        cout << "Please input Gray-image!" << endl;
        return 0;
    }
    int T = 0; //Otsu算法阈值
    double varValue = 0; //类间方差中间值保存
    double w0 = 0; //前景像素点数所占比例
    double w1 = 0; //背景像素点数所占比例
    double u0 = 0; //前景平均灰度
    double u1 = 0; //背景平均灰度
    double Histogram[256] = { 0 }; //灰度直方图，下标是灰度值，保存内容是灰度值对应的像素点总数
    uchar* data = image.data;
    double totalNum = image.rows * image.cols; //像素总数
    //计算灰度直方图分布，Histogram数组下标是灰度值，保存内容是灰度值对应像素点数
    for (int i = 0; i < image.rows; i++)   //为表述清晰，并没有把rows和cols单独提出来
    {
        for (int j = 0; j < image.cols; j++)
        {
            Histogram[data[i * image.step + j]]++;
        }
    }
    for (int i = 0; i < 255; i++)
    {
        //每次遍历之前初始化各变量
        w1 = 0;		u1 = 0;		w0 = 0;		u0 = 0;
        //***********背景各分量值计算**************************
        for (int j = 0; j <= i; j++) //背景部分各值计算
        {
            w1 += Histogram[j];  //背景部分像素点总数
            u1 += j * Histogram[j]; //背景部分像素总灰度和
        }
        if (w1 == 0) //背景部分像素点数为0时退出
        {
            continue;
        }
        u1 = u1 / w1; //背景像素平均灰度
        w1 = w1 / totalNum; // 背景部分像素点数所占比例
        //***********背景各分量值计算**************************

        //***********前景各分量值计算**************************
        for (int k = i + 1; k < 255; k++)
        {
            w0 += Histogram[k];  //前景部分像素点总数
            u0 += k * Histogram[k]; //前景部分像素总灰度和
        }
        if (w0 == 0) //前景部分像素点数为0时退出
        {
            break;
        }
        u0 = u0 / w0; //前景像素平均灰度
        w0 = w0 / totalNum; // 前景部分像素点数所占比例
        //***********前景各分量值计算**************************

        //***********类间方差计算******************************
        double varValueI = w0 * w1 * (u1 - u0) * (u1 - u0); //当前类间方差计算
        if (varValue < varValueI)
        {
            varValue = varValueI;
            T = i;
        }
    }
    return T;
}

void improcess(cv::Mat& image) {
    cv::Point2f anchor_pt(image.cols / 3.0f, image.rows / 3.0f);
    double rot_angle = 270.0; //旋转270度
    Mat dst_rotate = rotateImage(image, anchor_pt, rot_angle);


    //图片裁剪
    Rect area(500, 300, 800, 700);
    Mat img_region = image(area);
    img_region.copyTo(image);
    cvtColor(image, image, COLOR_RGB2GRAY);
    //Mat imageOutput;
    Mat imageOtsu;
    //int thresholdValue = OtsuAlgThreshold(image);
    //cout << "类间方差为： " << thresholdValue << endl;
    //threshold(image, imageOutput, thresholdValue, 255, THRESH_BINARY);
    threshold(image, imageOtsu, 0, 255, THRESH_OTSU); //Opencv Otsu算法
    imwrite("/home/zhu/ftp/tmp/tmp.jpg", imageOtsu);
}

void File::onTimeOut()
{

        //imshow("SoureImage", image);
        //cv::Mat dst_rotate;


//****************************
    QStringList list_name = dir->entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
    QString file_name = list_name.last();
    QString full_name = "/home/zhu/ftp/"+file_name;
//    qDebug()<<list_name.first();
//    qDebug()<<QFileDialog::getOpenFileName(this,tr("选择图像"),"/images/2.png", tr("Images(*.jpg)"));
//    qDebug()<<full_name;
    string name = full_name.toStdString();
    Mat image = cv::imread(name);
    improcess(image);
    QPixmap pixmap, pixmap_information;
    QMatrix leftmatrix;
    leftmatrix.rotate(0);
    pixmap.load(full_name);
    this->ui->label_picture->setPixmap(pixmap.transformed(leftmatrix,Qt::SmoothTransformation));
//****************************/
//    i += 1;
//    qDebug()<< i;
    pixmap_information.load("/home/zhu/ftp/tmp/tmp.jpg");
    this->ui->label_information->setPixmap(pixmap_information);
    this->ui->label_picture->setScaledContents(true);
    this->ui->label_information->setScaledContents(true);

}

