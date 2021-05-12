#include "modelview.h"
#include "additem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModelView w;
    w.show();
    return a.exec();
}
