#include "serial.h"
#include "ui_serial.h"
#include "QDebug"
#include "QList"
#include "QString"
#include "QMessageBox"
serial::serial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::serial)
{
    ui->setupUi(this);
    this->info=new QSerialPortInfo;
    this->serialPort=new QSerialPort;
    this->statusBar=new QStatusBar;
    /***************串口信息*************/
    QList<QSerialPortInfo> serialList = QSerialPortInfo::availablePorts();
    QList<qint32> baudRateList = QSerialPortInfo::standardBaudRates();

        for (int i=0;i<serialList.length();i++) {
            this->ui->comboBoxPortName->addItem(serialList.at(i).portName());
        //this->ui->comboBoxPortName->setItemText(i,serialList.at(i).portName());
    }
    //serialPort->setPort(serialList.at(1));
    //serialPort->setPortName(this->ui->comboBoxPortName->currentText());
    //qDebug()<<this->ui->comboBoxPortName->currentText();
    this->setWindowTitle("串口状态：串口关闭");
    this->ui->pushButtonClose->setEnabled(false);
}

serial::~serial()
{
    delete ui;
}

void serial::getDataBits(int i)
{
    switch (i) {
    case 0:serialPort->setDataBits(QSerialPort::Data5);
        break;
    case 1:serialPort->setDataBits(QSerialPort::Data6);
        break;
    case 2:serialPort->setDataBits(QSerialPort::Data7);
        break;
    case 3:serialPort->setDataBits(QSerialPort::Data8);
        break;
    default:
        break;
    }
}

void serial::getBaudRate(int i)
{
    switch (i) {
    case 0:serialPort->setBaudRate(QSerialPort::Baud1200);
        break;
    case 1:serialPort->setBaudRate(QSerialPort::Baud2400);
        break;
    case 2:serialPort->setBaudRate(QSerialPort::Baud4800);
        break;
    case 3:serialPort->setBaudRate(QSerialPort::Baud9600);
        break;
    case 4:serialPort->setBaudRate(QSerialPort::Baud19200);
        break;
    case 5:serialPort->setBaudRate(QSerialPort::Baud38400);
        break;
    case 6:serialPort->setBaudRate(QSerialPort::Baud57600);
        break;
    case 7:serialPort->setBaudRate(QSerialPort::Baud115200);
        break;
    default:
        break;
    }
}

void serial::getParity(int i)
{
    switch (i) {
    case 0:serialPort->setParity(QSerialPort::EvenParity);
        break;
    case 1:serialPort->setParity(QSerialPort::OddParity);
        break;
    case 2:serialPort->setParity(QSerialPort::MarkParity);
        break;
    case 3:serialPort->setParity(QSerialPort::SpaceParity);
        break;
    default:
        break;
    }
}

void serial::getStopBits(int i)
{
    switch (i) {
    case 0:serialPort->setStopBits(QSerialPort::OneStop);
        break;
    case 1:serialPort->setStopBits(QSerialPort::OneAndHalfStop);
        break;
    case 2:serialPort->setStopBits(QSerialPort::TwoStop);
        break;
    default:
        break;
    }
}

void serial::getFlowControl(int i)
{
    switch (i) {
    case 0:serialPort->setFlowControl(QSerialPort::HardwareControl);
        break;
    case 1:serialPort->setFlowControl(QSerialPort::SoftwareControl);
        break;
    default:
        break;
    }
}

void serial::on_pushButtonOpen_clicked()
    {
        serialPort->setPortName(this->ui->comboBoxPortName->currentText());
        if(serialPort->open(QIODevice::ReadWrite)){
                this->setWindowTitle("串口状态：已成功打开串口");
                getBaudRate(this->ui->comboBoxBaud->currentIndex());
                getDataBits(this->ui->comboBoxData->currentIndex());
                getParity(this->ui->comboBoxParity->currentIndex());
                getStopBits(this->ui->comboBoxStop->currentIndex());
                getFlowControl(this->ui->comboBoxFlow->currentIndex());
                this->ui->pushButtonOpen->setEnabled(false);
                this->ui->pushButtonClose->setEnabled(true);
                connect(serialPort,SIGNAL(readRead()),this,SLOT(onReadyRead()));
        }else{
            QMessageBox::warning(this,"警告","串口打开失败");
            this->setWindowTitle("串口状态：串口未打开");
        }
}

void serial::on_pushButtonClose_clicked()
{
    serialPort->close();
    this->ui->pushButtonOpen->setEnabled(true);
    this->ui->pushButtonClose->setEnabled(false);
    this->setWindowTitle("串口状态：已成功关闭串口");
}

void serial::onReadyRead()
{
    QByteArray byteArryMessage=serialPort->readAll();
    QString message=QByteArray(byteArryMessage);
    this->ui->textBrowser->append("接收："+message);
}

void serial::on_pushButtonSend_clicked()
{
    QString sendMessgae=this->ui->lineEdit->text();
    QByteArray byteArrySendMessage=sendMessgae.toUtf8();
    serialPort->write(byteArrySendMessage);
    this->ui->textBrowser->append("发送："+sendMessgae);
    this->ui->lineEdit->clear();
}

void serial::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Enter){
        QString sendMessgae=this->ui->lineEdit->text();
        QByteArray byteArrySendMessage=sendMessgae.toUtf8();
        serialPort->write(byteArrySendMessage);
        this->ui->textBrowser->append("发送："+sendMessgae);
        this->ui->lineEdit->clear();
    }
}

void serial::on_pushButtonClear_clicked()
{
    this->ui->textBrowser->clear();
}
