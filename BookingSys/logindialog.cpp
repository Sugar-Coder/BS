#include "logindialog.h"
#include "ui_logindialog.h"
#include "registerdialog.h"
#include "initer.h"
#include <QMessageBox> //消息对话框

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
    initer init;
    std::string name=ui->nameEdit->text().toStdString();
    int password = ui->passwordEdit->text().toInt();

    if(init.setlogin(name,password))
    {
        if(init.isAdmin())
        {
            //open the plane insert dialog
            accept();
        }
        else if(init.islogin())
            accept();
    }
    else {
        ui->nameEdit->clear();
        ui->passwordEdit->clear();
        int ret1=QMessageBox::information(this,tr("请重新登录！"),
                                          tr("错误的用户名或密码"),QMessageBox::Ok);
    }
}
//84
void loginDialog::on_registerButton_clicked()
{
    regdlg->raise();
    regdlg->exec();
}
