#include "plalterdialog.h"
#include "ui_plalterdialog.h"
#include "header.h"
#include <QMessageBox>

#include <QDebug>

plAlterDialog::plAlterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::plAlterDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("更改航班信息");
    string pid = "pid = ";
    pid += std::to_string(init.currentPlaneid());
    string planemess = db.selectSql("*","plane",pid,7);
    string info[7];
    int j=0;
    for(int i=0;i<7;i++)
    {
        while(planemess[j]!=cg)
        {
            info[i]+=planemess[j++];
        }
        j++;
    }
    string fromTime,toTime;
    int i=0;
    while(info[6][i]!='-')
    {
        fromTime+=info[6][i];
        i++;
    }
    i++;
    while(i<info[6].length())
    {
        toTime += info[6][i];
        i++;
    }
    this->pri = std::atoi(info[2].data());
    this->comp = QString::fromStdString(info[5]);
    this->fE = QString::fromStdString(info[3]);
    this->tE = QString::fromStdString(info[4]);
    this->fTE = QString::fromStdString(fromTime);
    this->tTE = QString::fromStdString(toTime);
    string mess = "航班";
    mess += info[0];
    mess += "的信息如下";
    ui->planeid->setText(mess.data());
    ui->seatsnum->setText(info[1].data());
    ui->price->setValue(std::atoi(info[2].data()));
    ui->company->setText(info[5].data());
    ui->fromEdit->setText(info[3].data());
    ui->toEdit->setText(info[4].data());
    ui->fromtimeEdit->setText(fromTime.data());
    ui->toTimeEdit->setText(toTime.data());
}

plAlterDialog::~plAlterDialog()
{
    delete ui;
}

void plAlterDialog::on_AlterButton_clicked()
{
    QString newM;
    int id = init.currentPlaneid();
    int price = ui->price->value();
    QString company = ui->company->text();
    QString fromEdit = ui->fromEdit->text();
    QString toEdit = ui->toEdit->text();
    QString fromTimeEdit = ui->fromtimeEdit->text();
    QString toTimeEdit = ui->toTimeEdit->text();
    if(price != pri) //有改变
    {
        newM = "price = ";
        newM += QString::number(price);
        if(db.updatePlaneMess(newM,id)=="success")
            QMessageBox::information(this,tr("成功"),
                                     tr("更改票价成功"),QMessageBox::Ok);
        newM.clear();
    }
    if(company != comp)
    {
        newM = "company = '";
        newM += company;
        newM += "'";
        if(db.updatePlaneMess(newM,id)=="success")
            QMessageBox::information(this,tr("成功"),
                                     tr("更改航空公司成功"),QMessageBox::Ok);
        newM.clear();
    }
    if(fromEdit != fE)
    {
        newM = "from = '";
        newM += fromEdit;
        newM += "'";
        if(db.updatePlaneMess(newM,id)=="success")
            QMessageBox::information(this,tr("成功"),
                                     tr("更改出发地成功"),QMessageBox::Ok);
        newM.clear();
    }
    if(toEdit != tE)
    {
        newM = "to = '";
        newM += toEdit;
        newM += "'";
        if(db.updatePlaneMess(newM,id)=="success")
            QMessageBox::information(this,tr("成功"),
                                     tr("更改目的地成功"),QMessageBox::Ok);
        newM.clear();
    }
    if((toTimeEdit != tTE)||(fromTimeEdit != fTE))
    {
        newM = "time = '";
        newM += fromTimeEdit;
        newM += "-";
        newM += toTimeEdit;
        newM += "'";
        if(db.updatePlaneMess(newM,id)=="success")
            QMessageBox::information(this,tr("成功"),
                                     tr("更改起降时间成功"),QMessageBox::Ok);
        newM.clear();
    }
}
