#ifndef SELFMESDIALOG_H
#define SELFMESDIALOG_H

#include <QDialog>

namespace Ui {
class selfmesDialog;
}

class selfmesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit selfmesDialog(QWidget *parent = nullptr);
    ~selfmesDialog();

private:
    Ui::selfmesDialog *ui;
};

#endif // SELFMESDIALOG_H
