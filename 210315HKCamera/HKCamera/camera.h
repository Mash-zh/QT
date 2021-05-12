#ifndef CAMERA_H
#define CAMERA_H

#include <QMainWindow>
#include "windows.h"
#include "HCNetSDK.h"
#include "QDebug"

QT_BEGIN_NAMESPACE
namespace Ui { class Camera; }
QT_END_NAMESPACE

class Camera : public QMainWindow
{
    Q_OBJECT

public:
    Camera(QWidget *parent = nullptr);
    ~Camera();

    long display(LONG lUserID, LPNET_DVR_PREVIEWINFO lpPreviewInfo);
private:
    Ui::Camera *ui;

    NET_DVR_USER_LOGIN_INFO struLoginInfo;
    NET_DVR_DEVICEINFO_V40  struLpDeviceInfo;
    NET_DVR_PREVIEWINFO struPlayInfo;
};
#endif // CAMERA_H
