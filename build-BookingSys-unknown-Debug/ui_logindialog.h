/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QLabel *label_3;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QString::fromUtf8("loginDialog"));
        loginDialog->resize(336, 262);
        label = new QLabel(loginDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 70, 57, 16));
        label_2 = new QLabel(loginDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 130, 57, 16));
        nameEdit = new QLineEdit(loginDialog);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(130, 70, 113, 21));
        passwordEdit = new QLineEdit(loginDialog);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(130, 130, 113, 21));
        loginButton = new QPushButton(loginDialog);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(50, 190, 111, 32));
        registerButton = new QPushButton(loginDialog);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(200, 190, 111, 32));
        label_3 = new QLabel(loginDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 10, 121, 41));

        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("loginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("loginDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        loginButton->setText(QApplication::translate("loginDialog", "\347\231\273\351\231\206", nullptr));
        registerButton->setText(QApplication::translate("loginDialog", "\346\263\250\345\206\214", nullptr));
        label_3->setText(QApplication::translate("loginDialog", "\346\254\242\350\277\216\346\235\245\345\210\260\350\256\242\347\245\250\347\263\273\347\273\237\n"
"\350\257\267\345\205\210\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
