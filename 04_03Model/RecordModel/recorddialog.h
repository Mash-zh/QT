#ifndef RECORDDIALOG_H
#define RECORDDIALOG_H

#include <QDialog>

namespace Ui {
class RecordDialog;
}

class RecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RecordDialog(QWidget *parent = nullptr);
    ~RecordDialog();

    QString getName();
    QString getScore();
    QString getTip();
private slots:
    void on_comboBox_record_currentIndexChanged(int index);

private:
    Ui::RecordDialog *ui;

    QString information;
};

#endif // RECORDDIALOG_H
