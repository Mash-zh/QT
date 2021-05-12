#ifndef TIMER_H
#define TIMER_H

#include <QMainWindow>
#include "QFileSystemWatcher"
QT_BEGIN_NAMESPACE
namespace Ui { class Timer; }
QT_END_NAMESPACE

class Timer : public QMainWindow
{
    Q_OBJECT

public:
    Timer(QWidget *parent = nullptr);
    ~Timer();

    QFileSystemWatcher *fileWatcher;

public slots:
    void output(QString);
private:
    Ui::Timer *ui;
};

#endif // TIMER_H
