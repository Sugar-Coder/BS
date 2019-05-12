#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "header.h"
#include <QMessageBox>
#include <QDebug>

initer init; //全局类定义

registerDialog::registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerDialog)
{
    ui->setupUi(this);
}

registerDialog::~registerDialog()
{
    delete ui;
}
//83页


void registerDialog::on_regButton_clicked() //注册按钮
{
    QString Qname = ui->name->text();
    QString Qid = ui->id->text();
    int password = ui->password->text().toInt();
    int Rpassword = ui->Rpassword->text().toInt();
    if(Qname.isEmpty()||Qid.isEmpty()) //有输入为空
    {
        QMessageBox::information(this,tr("空输入！"),
                                 tr("请完善信息"),QMessageBox::Ok);
    }
    else if(password == 0||Rpassword ==0)
    {
        QMessageBox::information(this,tr("密码为空！"),
                                 tr("请完善信息"),QMessageBox::Ok);
        ui->password->clear();
        ui->Rpassword->clear();
    }
    else if(password<=100||password>=999999)
    {
        QMessageBox::information(this,tr("格式错误"),
                                 tr("输入3-6位数字密码！"),QMessageBox::Ok);
        ui->password->clear();
        ui->Rpassword->clear();
    }
    else{
    string name = Qname.toStdString();
    int id = Qid.toInt();
    string nm = "name='";
    nm+= name;
    nm += "'";
    string selNameResult = db.selectSql("id","user",nm,1);
    qDebug() << "selNameResult = " << selNameResult.data();
    if(selNameResult == "NULL") //若不存在该注册用户
    {
        string idstr = "id=";
        idstr += std::to_string(id);
        string selIdResult = db.selectSql("name","user",idstr,1);
        qDebug() << "selIdResult" << selIdResult.data();
        if(selIdResult=="NULL") //id号也没有重复
        {
            if(password == Rpassword) //两次输入密码相等
            {
                db.insertUser(id,name,password);
                string mes = "成功注册\n用户:";
                mes+=name;
                QMessageBox::information(this,tr("success"),
                                         tr(mes.data()),QMessageBox::Ok);
                accept(); //成功注册退出窗口
            }
            else
            {
                QMessageBox::information(this,tr("再次输入密码错误"),
                                                  tr("请重新输入密码"),QMessageBox::Ok);
                ui->password->clear();
                ui->Rpassword->clear();
            }
        }
        else
        {
            QMessageBox::information(this,tr("输入重复"),
                                     tr("重复的id"),QMessageBox::Ok);
            ui->id->clear();
        }
    }
    else{
        QMessageBox::information(this,tr("重复的输入"),
                                 tr("已存在的用户名"),QMessageBox::Ok);
        ui->name->clear();
    }
    }
}

void registerDialog::on_returnButton_clicked()
{
    close();
}
