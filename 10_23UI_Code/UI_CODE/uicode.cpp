#include "uicode.h"
#include "ui_uicode.h"
#include "QLineEdit"

UiCode::UiCode(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UiCode)
{
    ui->setupUi(this);

    QLineEdit *lineEdit = new QLineEdit(this->ui->widget);
    lineEdit->setText("显示");
}

UiCode::~UiCode()
{
    delete ui;
}

