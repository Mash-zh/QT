#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>

namespace Ui {
class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddItem(QWidget *parent = nullptr);
    ~AddItem();

    void addNewItem();
    QString getItem();

private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::AddItem *ui;
    QString item_name;
};

#endif // ADDITEM_H
