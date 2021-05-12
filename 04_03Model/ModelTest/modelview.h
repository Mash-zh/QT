#ifndef MODELVIEW_H
#define MODELVIEW_H

#include <QMainWindow>
#include "QStandardItem"
#include "QStandardItemModel"
#include "QTableView"
#include "QList"
#include "additem.h"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "addrecord.h"
#include "QSqlTableModel"
QT_BEGIN_NAMESPACE
namespace Ui { class ModelView; }
QT_END_NAMESPACE

class ModelView : public QMainWindow
{
    Q_OBJECT

public:
    ModelView(QWidget *parent = nullptr);
    ~ModelView();

private:
    Ui::ModelView *ui;

    AddItem *item;
    AddRecord *record;

    QSqlTableModel *model;

private slots:
    void on_action_addItem_triggered();
    void on_action_addRecord_triggered();
};
#endif // MODELVIEW_H
