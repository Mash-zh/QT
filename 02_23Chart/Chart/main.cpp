#include "chartwidget.h"
#include "calendermainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //chartWidget w;
    //w.show();
    calenderMainWindow w;
    w.show();
    //QIcon icon = QIcon(":/image/app.ico");
    //w.setWindowIcon(icon);
    return a.exec();
}
