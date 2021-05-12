#include "file.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    File w;
    w.show();
    return a.exec();
}
