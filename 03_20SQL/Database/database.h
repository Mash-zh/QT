#ifndef DATABASE_H
#define DATABASE_H

#include <QWidget>
#include "QSqlDatabase"
#include "QSqlDriver"

QT_BEGIN_NAMESPACE
namespace Ui { class Database; }
QT_END_NAMESPACE

class Database : public QWidget
{
    Q_OBJECT

public:
    Database(QWidget *parent = nullptr);
    ~Database();

private slots:
    void on_pushButton_open_clicked();

private:
    Ui::Database *ui;
    QSqlDatabase DB;
};
#endif // DATABASE_H
