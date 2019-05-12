#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QGridLayout>
#include "logindialog.h"
#include "header.h"

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    //栅格布局
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(ui->username,0,0,1,1);
    layout->addWidget(ui->userButton,0,1,1,1);
    layout->addWidget(ui->exitButton,0,2,1,1);
    layout->addWidget(ui->fromlineEdit,1,0,2,1);
    layout->addWidget(ui->arrowpix,1,1,2,1);
    layout->addWidget(ui->tolineEdit,1,2,2,1);
    layout->addWidget(ui->planemess,3,0,5,3);
    layout->addWidget(ui->label,8,0,1,1);
    layout->addWidget(ui->plainIdInput,8,1,1,1);
    layout->addWidget(ui->bookButton,8,2,1,1);
    setLayout(layout);
    ui->fromlineEdit->setText(tr("出发"));
    ui->tolineEdit->setText(tr("到达"));
    ui->planemess->hide(); //开始的时候隐藏机票查询的信息
    initer init;
    QString welcome = "欢迎！";
    welcome += init.currentUser().data();
    ui->username->setText(welcome);
}

mainWidget::~mainWidget()
{
    delete ui;
}

//查询按钮
void mainWidget::on_inquireButton_clicked(bool checked)
{
    QString Qfrom = ui->fromlineEdit->text();
    QString Qto = ui->tolineEdit->text();
    if(Qfrom.isEmpty()&&Qto.isEmpty()||Qfrom == "出发"&&Qto =="到达")
    {
        string allplane = db.selectAll("*","plane",7);
        ui->planemess->setText(init.planeFormat(allplane).data());
    }
    ui->planemess->setVisible(true);
}

void mainWidget::on_exitButton_clicked()
{
    initer init;
    init.userQuit();
    ui->planemess->clear();
    ui->fromlineEdit->setText(tr("出发"));
    ui->tolineEdit->setText(tr("到达"));
    close();
    loginDialog ldialog;
    if(ldialog.exec() == QDialog::Accepted)
        show();
}
