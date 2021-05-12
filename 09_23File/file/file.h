#ifndef FILE_H
#define FILE_H

#include <QMainWindow>
#include "QDir"
#include "QPixmap"
#include "QTimer"
QT_BEGIN_NAMESPACE
namespace Ui { class File; }
QT_END_NAMESPACE

class File : public QMainWindow
{
    Q_OBJECT

public:
    File(QWidget *parent = nullptr);
    ~File();

    QDir *dir;
    QTimer *timer;
private:
    Ui::File *ui;
    QStringList nameFilters;

    int i;
public slots:
   void  onTimeOut();
};
#endif // FILE_H
