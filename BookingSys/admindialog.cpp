#include "admindialog.h"
#include "ui_admindialog.h"
#include "header.h"
#include "logindialog.h"
#include "planedialog.h"
#include <QInputDialog>
#include <QMessageBox>

#include <QDebug>

AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员");
    string allplane = db.selectAll("*","plane",7);
    ui->planemess->setText(init.planeFormat(allplane).data());
}

AdminDialog::~AdminDialog()
{
    delete ui;
}

void AdminDialog::on_exitButton_clicked() //管理员退出
{
    init.AdminQuit();
    accept();//关闭管理员界面
}

void AdminDialog::on_addButton_clicked() //增添机票信息
{
    //用输入对话框进行获取
    bool Ok = false;
    int planeid = QInputDialog::getInt(this,tr("新航班"),
                                       tr("请输入航班号"),0,0,100000,0,&Ok);
    if(Ok){
        string idJudge = "pid = ";
        idJudge += std::to_string(planeid);
        if(db.selectSql("company","plane",idJudge,1)=="NULL"){//id合法
            init.setPlaneid(planeid);
            planeDialog *planedlg = new planeDialog;
            if(planedlg->exec()==QDialog::Accepted) //打开航班信息录入对话框
            {
                delete planedlg;
                string allplane = db.selectAll("*","plane",7); //更新航班信息
                ui->planemess->setText(init.planeFormat(allplane).data());
            }
        }
        else {
            QMessageBox::information(this,tr("注意"),"该航班信息已经被录入",QMessageBox::Ok);
        }
    }
}

void AdminDialog::on_deleteButton_clicked() //删除航班信息
{
    bool Ok = false;
    int planeid = QInputDialog::getInt(this,tr("删除操作"),
                                       tr("请输入航班号"),0,0,100000,0,&Ok);
    if(Ok){
        string idJudge = "pid = ";
        idJudge += std::to_string(planeid);
        if(db.selectSql("company","plane",idJudge,1)=="NULL"){
            QMessageBox::information(this,tr("错误"),
                                     tr("不存在该航班"),QMessageBox::Ok);
        }
        else {
            int ret = QMessageBox::question(this,tr("是否删除"),
                                  tr("你确定删除该航班吗"),QMessageBox::Yes,QMessageBox::No);
            if(ret = QMessageBox::Yes){
                if(db.deletePlane(planeid)=="success")
                {
                    string allplane = db.selectAll("*","plane",7); //更新航班信息
                    ui->planemess->setText(init.planeFormat(allplane).data());
                    QMessageBox::information(this,tr("提示"),
                                             tr("删除成功"),QMessageBox::Ok);
                }
            }
        }
    }
}
