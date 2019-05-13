/********************************************************************************
** Form generated from reading UI file 'selfmesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELFMESDIALOG_H
#define UI_SELFMESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selfmesDialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QPushButton *nameButton_3;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *passwordEdit;
    QPushButton *passwButton;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *planeidEdit;
    QPushButton *unsubButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QPushButton *myorderButton;
    QLabel *myorderList;

    void setupUi(QDialog *selfmesDialog)
    {
        if (selfmesDialog->objectName().isEmpty())
            selfmesDialog->setObjectName(QString::fromUtf8("selfmesDialog"));
        selfmesDialog->resize(302, 381);
        horizontalLayoutWidget = new QWidget(selfmesDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 10, 261, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(horizontalLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        horizontalLayout->addWidget(nameEdit);

        nameButton_3 = new QPushButton(horizontalLayoutWidget);
        nameButton_3->setObjectName(QString::fromUtf8("nameButton_3"));

        horizontalLayout->addWidget(nameButton_3);

        horizontalLayoutWidget_2 = new QWidget(selfmesDialog);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 50, 261, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        passwordEdit = new QLineEdit(horizontalLayoutWidget_2);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));

        horizontalLayout_2->addWidget(passwordEdit);

        passwButton = new QPushButton(horizontalLayoutWidget_2);
        passwButton->setObjectName(QString::fromUtf8("passwButton"));

        horizontalLayout_2->addWidget(passwButton);

        horizontalLayoutWidget_3 = new QWidget(selfmesDialog);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(30, 260, 251, 81));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        planeidEdit = new QLineEdit(horizontalLayoutWidget_3);
        planeidEdit->setObjectName(QString::fromUtf8("planeidEdit"));

        horizontalLayout_3->addWidget(planeidEdit);

        unsubButton = new QPushButton(horizontalLayoutWidget_3);
        unsubButton->setObjectName(QString::fromUtf8("unsubButton"));

        horizontalLayout_3->addWidget(unsubButton);

        verticalLayoutWidget = new QWidget(selfmesDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 100, 251, 121));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        myorderButton = new QPushButton(verticalLayoutWidget);
        myorderButton->setObjectName(QString::fromUtf8("myorderButton"));

        verticalLayout_5->addWidget(myorderButton);

        myorderList = new QLabel(verticalLayoutWidget);
        myorderList->setObjectName(QString::fromUtf8("myorderList"));

        verticalLayout_5->addWidget(myorderList);


        retranslateUi(selfmesDialog);

        QMetaObject::connectSlotsByName(selfmesDialog);
    } // setupUi

    void retranslateUi(QDialog *selfmesDialog)
    {
        selfmesDialog->setWindowTitle(QApplication::translate("selfmesDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("selfmesDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        nameButton_3->setText(QApplication::translate("selfmesDialog", "\344\277\256\346\224\271", nullptr));
        label_3->setText(QApplication::translate("selfmesDialog", "\345\257\206\347\240\201", nullptr));
        passwButton->setText(QApplication::translate("selfmesDialog", "\344\277\256\346\224\271", nullptr));
        label_4->setText(QApplication::translate("selfmesDialog", "\350\276\223\345\205\245\350\210\252\347\217\255\345\217\267", nullptr));
        unsubButton->setText(QApplication::translate("selfmesDialog", "\351\200\200\350\256\242", nullptr));
        myorderButton->setText(QApplication::translate("selfmesDialog", "\346\210\221\347\232\204\350\256\242\345\215\225", nullptr));
        myorderList->setText(QApplication::translate("selfmesDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selfmesDialog: public Ui_selfmesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELFMESDIALOG_H
