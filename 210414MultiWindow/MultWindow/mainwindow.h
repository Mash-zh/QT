#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQueryModel"
#include "QtSql/QSqlQuery"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QSqlQueryModel *model;
    QSqlDatabase database;

};
#endif // MAINWINDOW_H
