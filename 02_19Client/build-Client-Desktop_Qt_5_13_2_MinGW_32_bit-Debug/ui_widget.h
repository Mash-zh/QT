/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_connect;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_disconnect;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_clear;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_IP;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_port;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_send;
    QLineEdit *lineEdit_message;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(467, 475);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_connect = new QPushButton(Widget);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));

        horizontalLayout_2->addWidget(pushButton_connect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_disconnect = new QPushButton(Widget);
        pushButton_disconnect->setObjectName(QString::fromUtf8("pushButton_disconnect"));

        horizontalLayout_2->addWidget(pushButton_disconnect);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_clear = new QPushButton(Widget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));

        horizontalLayout_2->addWidget(pushButton_clear);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_IP = new QLineEdit(Widget);
        lineEdit_IP->setObjectName(QString::fromUtf8("lineEdit_IP"));

        horizontalLayout->addWidget(lineEdit_IP);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_port = new QLineEdit(Widget);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));

        horizontalLayout_3->addWidget(lineEdit_port);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_send = new QPushButton(Widget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        horizontalLayout_5->addWidget(pushButton_send);

        lineEdit_message = new QLineEdit(Widget);
        lineEdit_message->setObjectName(QString::fromUtf8("lineEdit_message"));

        horizontalLayout_5->addWidget(lineEdit_message);


        verticalLayout->addLayout(horizontalLayout_5);

        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245\345\210\260\346\234\215\345\212\241\345\231\250", nullptr));
        pushButton_disconnect->setText(QCoreApplication::translate("Widget", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243\357\274\232", nullptr));
        pushButton_send->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
