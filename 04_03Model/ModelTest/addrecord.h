#ifndef ADDRECORD_H
#define ADDRECORD_H

#include <QDialog>
namespace Ui {
class AddRecord;
}

class AddRecord : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecord(QWidget *parent = nullptr);
    ~AddRecord();

    QString getName();
    QString getScore();
    QString getTip();
private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::AddRecord *ui;

    QString information;

protected:

};

#endif // ADDRECORD_H
