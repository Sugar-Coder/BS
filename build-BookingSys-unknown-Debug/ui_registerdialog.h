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
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

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
        lineEdit = new QLineEdit(registerDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 70, 113, 21));
        lineEdit_2 = new QLineEdit(registerDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 120, 113, 21));
        lineEdit_3 = new QLineEdit(registerDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 170, 113, 21));
        lineEdit_4 = new QLineEdit(registerDialog);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(110, 220, 113, 21));
        pushButton = new QPushButton(registerDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 290, 111, 32));
        pushButton_2 = new QPushButton(registerDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 290, 111, 32));

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
        lineEdit->setText(QApplication::translate("registerDialog", "\346\261\211\345\255\227\343\200\201\345\255\227\346\257\215\343\200\201\346\225\260\345\255\227", nullptr));
        lineEdit_3->setText(QApplication::translate("registerDialog", "5-10\344\275\215\346\225\260\345\255\227", nullptr));
        lineEdit_4->setText(QApplication::translate("registerDialog", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        pushButton->setText(QApplication::translate("registerDialog", "\346\263\250\345\206\214", nullptr));
        pushButton_2->setText(QApplication::translate("registerDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerDialog: public Ui_registerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
