#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QGridLayout>
#include <QPixmap>
#include <QMessageBox>
#include <QInputDialog>
#include "logindialog.h"
#include "header.h"

bool isDigitString(const QString &src){
    const char *s = src.toUtf8().data();
    while(*s && *s>='0' && *s<='9')s++;
    return !bool(*s);
}

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
    layout->addWidget(ui->exchangeButton,1,1,2,1);
    layout->addWidget(ui->tolineEdit,1,2,2,1);
    layout->addWidget(ui->planemess,3,0,5,3);
    layout->addWidget(ui->label,8,0,1,1);
    layout->addWidget(ui->plainIdInput,8,1,1,1);
    layout->addWidget(ui->bookButton,8,2,1,1);
    setLayout(layout);

    QIcon icon; //交换图标设置
    icon.addFile(tr("/users/sjy/desktop/BookingSystem/exchange.jpg"));
    ui->exchangeButton->setMaximumSize(141,41);
    ui->exchangeButton->setMinimumSize(141,41);
    ui->exchangeButton->setIcon(icon);
    ui->exchangeButton->setIconSize(QSize(141,41)); //最大最小都相等，让图片充满按钮

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
    if(Qfrom.isEmpty()&&Qto.isEmpty()||Qfrom == "出发"&&Qto =="到达"||Qfrom =="到达"&&Qto=="出发")
    {
        string allplane = db.selectAll("*","plane",7);
        ui->planemess->setText(init.planeFormat(allplane).data());
    }
    //只填写了出发地
    else if(!Qfrom.isEmpty() && Qto.isEmpty()||!Qfrom.isEmpty()&&Qto == "到达")
    {
        string from = "plane.from = '";
        from += Qfrom.toStdString();
        from += "'";
        string fromplane = db.selectSql("*","plane",from,7);
        if(fromplane != "NULL")
            ui->planemess->setText(init.planeFormat(fromplane).data());
        else {
            ui->planemess->setText("无结果");
        }
    }
    //只填写了目的地
    else if (Qfrom.isEmpty() && !Qto.isEmpty() || Qfrom=="出发"&&!Qto.isEmpty()) {
        string to = "plane.to = '";
        to += Qto.toStdString();
        to += "'";
        string toplane = db.selectSql("*","plane",to,7);
        if(toplane != "NULL")
            ui->planemess->setText(init.planeFormat(toplane).data());
        else {
            ui->planemess->setText("无结果");
        }
    }
    else {
        string fromto = "plane.from = '";
        fromto += Qfrom.toStdString();
        fromto += "' AND plane.to = '";
        fromto += Qto.toStdString();
        fromto += "'";
        string fromtoplane = db.selectSql("*","plane",fromto,7);
        if(fromtoplane!="NULL")
            ui->planemess->setText(init.planeFormat(fromtoplane).data());
        else
        {
            ui->planemess->setText("无结果");
        }
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

void mainWidget::on_exchangeButton_clicked()//交换出发和到达
{
    QString Qfrom = ui->fromlineEdit->text();
    QString Qto = ui->tolineEdit->text();
    QString temp = Qfrom;
    Qfrom = Qto;
    Qto = temp;
    ui->fromlineEdit->setText(Qfrom);
    ui->tolineEdit->setText(Qto);
}

void mainWidget::on_bookButton_clicked() //订票按钮
{
    QString planeId = ui->plainIdInput->text();
    if(planeId.isEmpty()) //若输入为空
    {
        QMessageBox::information(this,tr("输入为空"),
                                 tr("请输入航班号"),QMessageBox::Ok);
    }
    else if(!isDigitString(planeId)){
        QMessageBox::information(this,tr("输入错误"),
                                 tr("请输入数字组成的航班号"),QMessageBox::Ok);
        ui->plainIdInput->clear();
    }
    else {
        string pid = "pid = ";
        pid += planeId.toStdString();
        string result = db.selectSql("seatsnum","plane",pid,1);
        //qDebug() << result.data();
        if(result != "NULL")
        {
            bool ok;
             int bookNum = QInputDialog::getInt(this,tr("输入订票数量"),
                                                tr("请输入你的订票数量："),1,1,10,1,&ok);
             int seatsleft = atoi(result.data()); //剩余座位数
             if(ok && bookNum<=seatsleft) //订票数量正确
             {
                 string check = "userid = ";
                 check += std::to_string(init.currentUserid());
                 check +=" AND planeid = ";
                 check += planeId.toStdString();
                 if(db.selectSql("*","BookingSystem.order",check,3)=="NULL") //该乘客未订购过该航班
                 {
                    db.insertOrder(init.currentUserid(),planeId.toInt(),bookNum);
                    db.updatePlaneSeats(seatsleft-bookNum,planeId.toInt());
                    string info = "成功订票，航班号：";
                    info += planeId.toStdString();
                    info += ",数量：";
                    info += std::to_string(bookNum);
                    QMessageBox::information(this,tr("成功"),
                                             tr(info.data()),QMessageBox::Ok);
                 }
                 else {
                     QMessageBox::information(this,tr("警告"),
                                              tr("你已订购过该航班，请勿重复订票"),QMessageBox::Ok);
                     ui->plainIdInput->clear();
                 }
             }
             else {
                 QMessageBox::information(this,tr("警告"),
                                          tr("订票数量超过余票"),QMessageBox::Ok);
             }
        }
        else {
            QMessageBox::information(this,tr("错误输入"),
                                     tr("请输入正确的航班号"),QMessageBox::Ok);
            ui->plainIdInput->clear();
        }
    }
}

void mainWidget::on_userButton_clicked() //显示用户个人信息页面
{
    selfdlg->raise();
    selfdlg->exec();
}
