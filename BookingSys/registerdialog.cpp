#include "registerdialog.h"
#include "ui_registerdialog.h"

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


void registerDialog::on_regButton_clicked()
{
    accept();
}

void registerDialog::on_returnButton_clicked()
{
    close();
}
