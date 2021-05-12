/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_link;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit_IP;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_send;
    QLineEdit *lineEdit_messgae;
    QPushButton *pushButton_clear;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(432, 347);
        verticalLayout = new QVBoxLayout(Client);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_link = new QPushButton(Client);
        pushButton_link->setObjectName(QString::fromUtf8("pushButton_link"));

        horizontalLayout->addWidget(pushButton_link);

        label_2 = new QLabel(Client);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        label = new QLabel(Client);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_IP = new QLineEdit(Client);
        lineEdit_IP->setObjectName(QString::fromUtf8("lineEdit_IP"));

        horizontalLayout->addWidget(lineEdit_IP);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 4);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_send = new QPushButton(Client);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        horizontalLayout_2->addWidget(pushButton_send);

        lineEdit_messgae = new QLineEdit(Client);
        lineEdit_messgae->setObjectName(QString::fromUtf8("lineEdit_messgae"));
        lineEdit_messgae->setCursor(QCursor(Qt::IBeamCursor));
        lineEdit_messgae->setInputMethodHints(Qt::ImhNone);
        lineEdit_messgae->setEchoMode(QLineEdit::Normal);
        lineEdit_messgae->setDragEnabled(false);
        lineEdit_messgae->setReadOnly(false);

        horizontalLayout_2->addWidget(lineEdit_messgae);

        pushButton_clear = new QPushButton(Client);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));

        horizontalLayout_2->addWidget(pushButton_clear);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 9);
        horizontalLayout_2->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        textBrowser = new QTextBrowser(Client);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "\345\256\242\346\210\267\347\253\257", nullptr));
        pushButton_link->setText(QCoreApplication::translate("Client", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("Client", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        pushButton_send->setText(QCoreApplication::translate("Client", "\345\217\221\351\200\201", nullptr));
        lineEdit_messgae->setInputMask(QString());
        lineEdit_messgae->setText(QString());
        lineEdit_messgae->setPlaceholderText(QCoreApplication::translate("Client", "\345\217\252\345\205\201\350\256\270\346\267\273\345\212\2400~40\344\271\213\345\206\205\347\232\204\346\225\260\345\255\227", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Client", "\346\270\205\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
