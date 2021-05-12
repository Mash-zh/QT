#ifndef ADDRECORDDIALOG_H
#define ADDRECORDDIALOG_H

#include <QDialog>

namespace Ui {
class AddRecordDialog;
}

class AddRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecordDialog(QWidget *parent = nullptr);
    ~AddRecordDialog();

private slots:
    void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::AddRecordDialog *ui;
    QString information;
};

#endif // ADDRECORDDIALOG_H
