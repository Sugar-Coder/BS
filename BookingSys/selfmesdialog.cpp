#include "selfmesdialog.h"
#include "ui_selfmesdialog.h"
#include <QDebug>
#include <QMessageBox>
#include "header.h"

selfmesDialog::selfmesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selfmesDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("个人信息");
    //窗口初始化时显示用户名和密码
    ui->nameEdit->setText(init.currentUser().data());
    string nm = "name = '";
    nm += init.currentUser();
    nm += "'";
    ui->passwordEdit->setText(db.selectSql("password","user",nm,1).data());
    ui->myorderList->hide();
}

selfmesDialog::~selfmesDialog()
{
    delete ui;
}

void selfmesDialog::on_myorderButton_clicked() //查询订单按钮
{
    ui->myorderList->setVisible(1);
    string id = "BookingSystem.order.userid = ";
    id += std::to_string(init.currentUserid());
    id += " AND BookingSystem.order.planeid = plane.pid";
    string myorder = db.selectSql("BookingSystem.order.planeid,BookingSystem.order.num,plane.from,plane.to","BookingSystem.order,plane",id,4);
    if(myorder != "NULL")
        ui->myorderList->setText(init.orderFormat(myorder).data());
    else {
        ui->myorderList->setText("您还为订票呢！就来查询啊");
    }
}

void selfmesDialog::on_nameButton_3_clicked() //修改用户名按钮
{
    QString nameInput = ui->nameEdit->text();
    if(!(init.currentUser()==nameInput.toStdString()))//用户重新填写了用户名
    {
        string newname = "name = '";
        newname += nameInput.toStdString();
        newname += "'";
        if(db.selectSql("id","user",newname,1)=="NULL") //用户名合法
        {
            db.updateUser(init.currentUserid(),nameInput.toStdString(),-1); //不改密码
            QMessageBox::information(this,tr("success"),
                                     tr("修改用户名成功！"),QMessageBox::Ok);
            init.setCurrentUser(nameInput.toStdString());
        }
        else{
            QMessageBox::information(this,tr("failed"),
                                     tr("已注册的用户名"),QMessageBox::Ok);
            ui->nameEdit->setText(init.currentUser().data());
        }
    }
}

void selfmesDialog::on_passwButton_clicked() //修改密码
{
    QString newpass = ui->passwordEdit->text();
    string nm = "name = '";
    nm += init.currentUser();
    nm += "'";
    int oldpass = std::atoi(db.selectSql("password","user",nm,1).data());
    if(oldpass != newpass.toInt())
    {
        db.updateUser(init.currentUserid(),"unchange",newpass.toInt());
        QMessageBox::information(this,tr("success"),
                                 tr("修改密码成功！"),QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("failed"),
                                 tr("输入新密码以更改"),QMessageBox::Ok);
    }
}

void selfmesDialog::on_unsubButton_clicked() //退订机票
{
    QString pidInput = ui->planeidEdit->text();
    string where = "BookingSystem.order.userid = ";
    where += std::to_string(init.currentUserid());
    where += " AND BookingSystem.order.planeid = ";
    where += pidInput.toStdString();
    //用户订购了此航班
    string bookNum; //记录订票数量
    if((bookNum=db.selectSql("BookingSystem.order.num","BookingSystem.order",where,1))!="NULL")
    {
        int ret1 = QMessageBox::question(this,tr("确认"),
                                         tr("你确定退订该航班吗"),QMessageBox::Yes,QMessageBox::No);
        if(ret1 == QMessageBox::Yes)
        {
            string pid = "pid = ";
            pid += pidInput.toStdString();
            int oldNum = std::atoi(db.selectSql("seatsnum","plane",pid,1).data());
            //删除订单信息
            db.deleteOrder(init.currentUserid(),pidInput.toInt());
            //恢复机票数
            int newNum = oldNum + std::atoi(bookNum.data());
            db.updatePlaneSeats(newNum,pidInput.toInt());
            QMessageBox::information(this,tr("success"),
                                     tr("退票成功"),QMessageBox::Ok);
        }
    }
    else {
        QMessageBox::information(this,tr("注意"),
                                 tr("您还为订购该航班或者错误的航班号"),QMessageBox::Ok);
    }
}
