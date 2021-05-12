#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QToolBar"
#include "QWidgetAction"
#include "QVBoxLayout"
#include "QTableView"
#include "QStandardItem"
#include "QStandardItemModel"
#include "QList"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlTableModel"
#include "itemdialog.h"
#include "recorddialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QVBoxLayout *VLayout;
private:
    Ui::Widget *ui;
    QToolBar *toolBar;
    QWidgetAction *action_record;
    QWidgetAction *action_item;
    QWidgetAction *action_delete;
    QWidgetAction *action_modify;
    QWidgetAction *action_return;
    QWidgetAction *sum;

    ItemDialog *item;
    RecordDialog *record;

    int sum_score;

    QSqlTableModel *model;
protected:

public slots:
    void showItem();
    void showRecord();
    void doDelete();
    void doModify();
    void doReturn();
    void doSum();
};
#endif // WIDGET_H
