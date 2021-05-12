#ifndef UICODE_H
#define UICODE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class UiCode; }
QT_END_NAMESPACE

class UiCode : public QMainWindow
{
    Q_OBJECT

public:
    UiCode(QWidget *parent = nullptr);
    ~UiCode();

private:
    Ui::UiCode *ui;
};
#endif // UICODE_H
