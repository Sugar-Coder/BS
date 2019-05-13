#include "selfmesdialog.h"
#include "ui_selfmesdialog.h"
#include <QDebug>
#include <QGridLayout>
#include <QMessageBox>
#include "header.h"

selfmesDialog::selfmesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selfmesDialog)
{
    ui->setupUi(this);
}

selfmesDialog::~selfmesDialog()
{
    delete ui;
}
