#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QStandardItem"
#include "QStandardItemModel"
#include "QTableView"
#include "QList"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "itemdialog.h"
#include "recorddialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_addRecord_triggered();

    void on_action_addItem_triggered();

private:
    Ui::MainWindow *ui;

    ItemDialog *itemDialog;
    RecordDialog *recordDialog;
};
#endif // MAINWINDOW_H
