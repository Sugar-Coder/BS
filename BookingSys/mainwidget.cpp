#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QGridLayout>
#include "logindialog.h"

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
    ui->planemess->hide();
}

mainWidget::~mainWidget()
{
    delete ui;
}

void mainWidget::on_inquireButton_clicked(bool checked)
{
    ui->planemess->setVisible(true);
}

void mainWidget::on_exitButton_clicked()
{
    close();
    loginDialog ldialog;
    if(ldialog.exec() == QDialog::Accepted)
        show();
}
