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

private slots:
    void on_myorderButton_clicked();

    void on_nameButton_3_clicked();

    void on_passwButton_clicked();

    void on_unsubButton_clicked();

private:
    Ui::selfmesDialog *ui;
};

#endif // SELFMESDIALOG_H
