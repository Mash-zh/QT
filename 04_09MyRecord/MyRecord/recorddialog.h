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

    void setOK(bool ok);
    bool getOK();
    QString getName();
    QString getScore();
    QString getTip();
private slots:
    void on_pushButton_okRecord_clicked();

    void on_pushButton_cancelRecord_clicked();

    void on_comboBox_record_currentIndexChanged(int index);

    void on_pushButton_refresh_clicked();

private:
    Ui::RecordDialog *ui;

    QString information;
    int current_score;
    bool ok;
};

#endif // RECORDDIALOG_H
