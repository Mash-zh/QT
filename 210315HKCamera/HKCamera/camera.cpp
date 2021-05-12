#include "camera.h"
#include "ui_camera.h"
#include "string"
#include "iostream"

using namespace std;

Camera::Camera(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Camera)
{
    ui->setupUi(this);
    struLoginInfo = {};
    struLpDeviceInfo = {};
    struPlayInfo = {};

    int usrID = 0;

    struLoginInfo.wPort = 8000;
    struLoginInfo.bUseAsynLogin = 0;
    struPlayInfo.lChannel = 1;
    struPlayInfo.dwStreamType = 0;
    struPlayInfo.dwLinkMode = 0;
    struPlayInfo.bBlocked = 1;
    struPlayInfo.hPlayWnd = (HWND)this->ui->label->winId();
    strcpy(struLoginInfo.sDeviceAddress, "192.168.1.160");
    strcpy(struLoginInfo.sUserName, "admin");
    strcpy(struLoginInfo.sPassword, "jzh662662");


    if(NET_DVR_Init() == false)
    {
        qDebug()<< "初始化失败！";
    }else {
        if(NET_DVR_SetConnectTime(3000) == false)//超时时间3000ms
        {
            if(NET_DVR_GetLastError() == NET_DVR_NOINIT)
            {
                qDebug()<< "SDK未初始化！";
            }
        }else {
            usrID = NET_DVR_Login_V40(&struLoginInfo, &struLpDeviceInfo);
            if(usrID == -1)
            {
                qDebug()<<"登陆失败！";
            }else {
                display(usrID, &struPlayInfo);
            }
        }
    }



}

Camera::~Camera()
{
    qDebug()<<"delete";
    delete ui;
}

long Camera::display(LONG lUserID, LPNET_DVR_PREVIEWINFO lpPreviewInfo)
{
    long lRealPlayHandle;
    lRealPlayHandle = NET_DVR_RealPlay_V40(lUserID, lpPreviewInfo, NULL, NULL);
    return lRealPlayHandle;
}


