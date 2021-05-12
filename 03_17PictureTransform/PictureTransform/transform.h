#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Transform; }
QT_END_NAMESPACE

class Transform : public QMainWindow
{
    Q_OBJECT

public:
    Transform(QWidget *parent = nullptr);
    ~Transform();

private slots:
    void on_pushButtonAddPicture_clicked();

    void on_pushButtonSavePicture_clicked();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::Transform *ui;
    QString fileName;
    QPixmap pixmap;
    QString save_fileName;
};
#endif // TRANSFORM_H
