/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QLineEdit *fromlineEdit;
    QLineEdit *tolineEdit;
    QLabel *planemess;
    QPushButton *inquireButton;
    QPushButton *exitButton;
    QLabel *username;
    QLineEdit *plainIdInput;
    QLabel *label;
    QPushButton *bookButton;
    QPushButton *userButton;
    QPushButton *exchangeButton;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->resize(419, 456);
        fromlineEdit = new QLineEdit(mainWidget);
        fromlineEdit->setObjectName(QString::fromUtf8("fromlineEdit"));
        fromlineEdit->setGeometry(QRect(50, 80, 101, 51));
        tolineEdit = new QLineEdit(mainWidget);
        tolineEdit->setObjectName(QString::fromUtf8("tolineEdit"));
        tolineEdit->setGeometry(QRect(270, 80, 101, 51));
        planemess = new QLabel(mainWidget);
        planemess->setObjectName(QString::fromUtf8("planemess"));
        planemess->setGeometry(QRect(60, 190, 281, 181));
        inquireButton = new QPushButton(mainWidget);
        inquireButton->setObjectName(QString::fromUtf8("inquireButton"));
        inquireButton->setGeometry(QRect(150, 150, 111, 32));
        exitButton = new QPushButton(mainWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(280, 10, 111, 32));
        username = new QLabel(mainWidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(20, 20, 57, 16));
        plainIdInput = new QLineEdit(mainWidget);
        plainIdInput->setObjectName(QString::fromUtf8("plainIdInput"));
        plainIdInput->setGeometry(QRect(120, 420, 113, 21));
        label = new QLabel(mainWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 420, 71, 16));
        bookButton = new QPushButton(mainWidget);
        bookButton->setObjectName(QString::fromUtf8("bookButton"));
        bookButton->setGeometry(QRect(260, 410, 61, 31));
        userButton = new QPushButton(mainWidget);
        userButton->setObjectName(QString::fromUtf8("userButton"));
        userButton->setGeometry(QRect(160, 10, 111, 32));
        exchangeButton = new QPushButton(mainWidget);
        exchangeButton->setObjectName(QString::fromUtf8("exchangeButton"));
        exchangeButton->setGeometry(QRect(160, 90, 141, 41));

        retranslateUi(mainWidget);

        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QApplication::translate("mainWidget", "mainWidget", nullptr));
        planemess->setText(QApplication::translate("mainWidget", "TextLabel", nullptr));
        inquireButton->setText(QApplication::translate("mainWidget", "\346\237\245\350\257\242", nullptr));
        exitButton->setText(QApplication::translate("mainWidget", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        username->setText(QApplication::translate("mainWidget", "TextLabel", nullptr));
        label->setText(QApplication::translate("mainWidget", "\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267", nullptr));
        bookButton->setText(QApplication::translate("mainWidget", "\350\256\242\347\245\250", nullptr));
        userButton->setText(QApplication::translate("mainWidget", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        exchangeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
