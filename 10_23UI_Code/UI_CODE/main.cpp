#include "uicode.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UiCode w;
    w.show();
    return a.exec();
}
