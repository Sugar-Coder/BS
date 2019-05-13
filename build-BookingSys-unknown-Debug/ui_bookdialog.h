/********************************************************************************
** Form generated from reading UI file 'bookdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKDIALOG_H
#define UI_BOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_bookDialog
{
public:

    void setupUi(QDialog *bookDialog)
    {
        if (bookDialog->objectName().isEmpty())
            bookDialog->setObjectName(QString::fromUtf8("bookDialog"));
        bookDialog->resize(297, 233);

        retranslateUi(bookDialog);

        QMetaObject::connectSlotsByName(bookDialog);
    } // setupUi

    void retranslateUi(QDialog *bookDialog)
    {
        bookDialog->setWindowTitle(QApplication::translate("bookDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookDialog: public Ui_bookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKDIALOG_H
