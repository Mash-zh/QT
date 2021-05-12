/********************************************************************************
** Form generated from reading UI file 'transform.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORM_H
#define UI_TRANSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Transform
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAddPicture;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonSavePicture;
    QWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Transform)
    {
        if (Transform->objectName().isEmpty())
            Transform->setObjectName(QString::fromUtf8("Transform"));
        Transform->resize(704, 476);
        centralwidget = new QWidget(Transform);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonAddPicture = new QPushButton(centralwidget);
        pushButtonAddPicture->setObjectName(QString::fromUtf8("pushButtonAddPicture"));

        horizontalLayout->addWidget(pushButtonAddPicture);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonSavePicture = new QPushButton(centralwidget);
        pushButtonSavePicture->setObjectName(QString::fromUtf8("pushButtonSavePicture"));

        horizontalLayout->addWidget(pushButtonSavePicture);


        verticalLayout->addLayout(horizontalLayout);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 20);
        Transform->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Transform);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 704, 22));
        Transform->setMenuBar(menubar);
        statusbar = new QStatusBar(Transform);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Transform->setStatusBar(statusbar);

        retranslateUi(Transform);

        QMetaObject::connectSlotsByName(Transform);
    } // setupUi

    void retranslateUi(QMainWindow *Transform)
    {
        Transform->setWindowTitle(QCoreApplication::translate("Transform", "Transform", nullptr));
        pushButtonAddPicture->setText(QCoreApplication::translate("Transform", "\346\267\273\345\212\240\345\233\276\347\211\207", nullptr));
        pushButtonSavePicture->setText(QCoreApplication::translate("Transform", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transform: public Ui_Transform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORM_H
