#ifndef ITEMDIALOG_H
#define ITEMDIALOG_H

#include <QDialog>

namespace Ui {
class ItemDialog;
}

class ItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ItemDialog(QWidget *parent = nullptr);
    ~ItemDialog();

    void addNewItem();
    QString getItem();
private slots:
    void on_pushButton_okItem_clicked();

    void on_pushButton_cancelItem_clicked();

private:
    Ui::ItemDialog *ui;
    QString item_name;
};

#endif // ITEMDIALOG_H
