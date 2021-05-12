/********************************************************************************
** Form generated from reading UI file 'tcp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCP_H
#define UI_TCP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tcp
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_startListen;
    QLabel *label_listen;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *tcp)
    {
        if (tcp->objectName().isEmpty())
            tcp->setObjectName(QString::fromUtf8("tcp"));
        tcp->resize(450, 464);
        verticalLayout = new QVBoxLayout(tcp);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_startListen = new QPushButton(tcp);
        pushButton_startListen->setObjectName(QString::fromUtf8("pushButton_startListen"));

        horizontalLayout->addWidget(pushButton_startListen);

        label_listen = new QLabel(tcp);
        label_listen->setObjectName(QString::fromUtf8("label_listen"));
        label_listen->setFrameShape(QFrame::NoFrame);

        horizontalLayout->addWidget(label_listen);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(tcp);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(tcp);

        QMetaObject::connectSlotsByName(tcp);
    } // setupUi

    void retranslateUi(QWidget *tcp)
    {
        tcp->setWindowTitle(QCoreApplication::translate("tcp", "tcp", nullptr));
        pushButton_startListen->setText(QCoreApplication::translate("tcp", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
        label_listen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tcp: public Ui_tcp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCP_H
