#include "logindialog.h"
#include "ui_logindialog.h"
#include "registerdialog.h"

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_loginButton_clicked()
{
    if(true)
        accept();
}

void loginDialog::on_registerButton_clicked()
{
    regdlg->raise();
    regdlg->exec();
}
