#ifndef SERIAL_H
#define SERIAL_H

#include <QMainWindow>
#include "QtSerialPort/QSerialPortInfo"
#include "QtSerialPort/QSerialPort"
#include "QStatusBar"
QT_BEGIN_NAMESPACE
namespace Ui { class serial; }
QT_END_NAMESPACE

class serial : public QMainWindow
{
    Q_OBJECT

public:
    serial(QWidget *parent = nullptr);
    ~serial();

    void getDataBits(int i);
    void getBaudRate(int i);
    void getParity(int i);
    void getStopBits(int i);
    void getFlowControl(int i);

protected:
    void keyPressEvent(QKeyEvent *e);
private slots:
    void on_pushButtonOpen_clicked();

    void on_pushButtonClose_clicked();

    void onReadyRead();

    void on_pushButtonSend_clicked();

    void on_pushButtonClear_clicked();

private:
    Ui::serial *ui;
    QSerialPortInfo *info;
    QSerialPort *serialPort;
    QStatusBar *statusBar;
};
#endif // SERIAL_H
