#ifndef SQL_H
#define SQL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SQL; }
QT_END_NAMESPACE

class SQL : public QMainWindow
{
    Q_OBJECT

public:
    SQL(QWidget *parent = nullptr);
    ~SQL();

private:
    Ui::SQL *ui;
};
#endif // SQL_H
