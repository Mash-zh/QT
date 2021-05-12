#ifndef THREAD_H
#define THREAD_H

#include <QDialog>
#include "dicethread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Thread; }
QT_END_NAMESPACE

class Thread : public QDialog
{
    Q_OBJECT

public:
    Thread(QWidget *parent = nullptr);
    ~Thread();

private:
    Ui::Thread *ui;
    DiceThread *thread1;

protected:
    void closeEvent(QCloseEvent *e);

public slots:
    void thread1Start();
    void thread1Finish();
    void thread1NewValue(int seq,int diceValue);

private slots:
    void on_pushButton_startThread_clicked();
    void on_pushButton_start_clicked();
    void on_pushButton_pause_clicked();
    void on_pushButton_finshThread_clicked();
    void on_pushButton_clear_clicked();
};
#endif // THREAD_H
