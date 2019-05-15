#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "registerdialog.h"

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = nullptr);
    ~loginDialog();

private slots:
    void on_loginButton_clicked();  //登录按钮

    void on_registerButton_clicked();  //注册按钮

private:
    Ui::loginDialog *ui;
    //registerDialog *regdlg = new registerDialog;
};

#endif // LOGINDIALOG_H
