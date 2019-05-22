#include "planedialog.h"
#include "ui_planedialog.h"
#include "header.h"
#include <QMessageBox>

planeDialog::planeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::planeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("新航班");
    string mess = "请继续录入航班";
    mess += std::to_string(init.currentPlaneid());
    mess += "的信息";
    ui->pidLabel->setText(mess.data());
}

planeDialog::~planeDialog()
{
    delete ui;
}

void planeDialog::on_commitButton_clicked()
{
    int price = ui->price->value();
    int seatsnum = ui->seatsnum->value();
    QString from = ui->fromEdit->text();
    QString to = ui->toEdit->text();
    QString company = ui->company->text();
    QString fromTime = ui->fromTimeEdit->text();
    QString toTime = ui->toTimeEdit->text();
    if(price == 99||seatsnum==1||from.isEmpty()||to.isEmpty()||company.isEmpty())
        QMessageBox::information(this,tr("警告！"),
                                 tr("输入有空或者值过小"),QMessageBox::Ok);
    else {
        string result=db.insertPlane(init.currentPlaneid(),price,seatsnum,from,to,company,fromTime,toTime).toStdString();
        if(result == "success")
            QMessageBox::information(this,tr("提示"),
                                     tr("增添航班成功"),QMessageBox::Ok);
        accept();
    }
}
