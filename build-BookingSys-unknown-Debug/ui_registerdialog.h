/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registerDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *name;
    QLineEdit *id;
    QLineEdit *password;
    QLineEdit *Rpassword;
    QPushButton *regButton;
    QPushButton *returnButton;

    void setupUi(QDialog *registerDialog)
    {
        if (registerDialog->objectName().isEmpty())
            registerDialog->setObjectName(QString::fromUtf8("registerDialog"));
        registerDialog->resize(314, 359);
        label = new QLabel(registerDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 20, 121, 21));
        label_2 = new QLabel(registerDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 57, 16));
        label_3 = new QLabel(registerDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 120, 57, 16));
        label_4 = new QLabel(registerDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 170, 57, 16));
        label_5 = new QLabel(registerDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 220, 57, 16));
        name = new QLineEdit(registerDialog);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(110, 70, 113, 21));
        id = new QLineEdit(registerDialog);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(110, 120, 113, 21));
        password = new QLineEdit(registerDialog);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(110, 170, 113, 21));
        password->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        Rpassword = new QLineEdit(registerDialog);
        Rpassword->setObjectName(QString::fromUtf8("Rpassword"));
        Rpassword->setGeometry(QRect(110, 220, 113, 21));
        Rpassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        regButton = new QPushButton(registerDialog);
        regButton->setObjectName(QString::fromUtf8("regButton"));
        regButton->setGeometry(QRect(40, 290, 111, 32));
        returnButton = new QPushButton(registerDialog);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(170, 290, 111, 32));

        retranslateUi(registerDialog);

        QMetaObject::connectSlotsByName(registerDialog);
    } // setupUi

    void retranslateUi(QDialog *registerDialog)
    {
        registerDialog->setWindowTitle(QApplication::translate("registerDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("registerDialog", "\350\257\267\350\276\223\345\205\245\346\263\250\345\206\214\344\277\241\346\201\257", nullptr));
        label_2->setText(QApplication::translate("registerDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QApplication::translate("registerDialog", "\350\257\201\344\273\266\345\217\267", nullptr));
        label_4->setText(QApplication::translate("registerDialog", "\345\257\206\347\240\201", nullptr));
        label_5->setText(QApplication::translate("registerDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        name->setText(QString());
        password->setText(QString());
        Rpassword->setText(QString());
        regButton->setText(QApplication::translate("registerDialog", "\346\263\250\345\206\214", nullptr));
        returnButton->setText(QApplication::translate("registerDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerDialog: public Ui_registerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
