#ifndef PLALTERDIALOG_H
#define PLALTERDIALOG_H

#include <QDialog>

namespace Ui {
class plAlterDialog;
}

class plAlterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit plAlterDialog(QWidget *parent = nullptr);
    ~plAlterDialog();

private slots:
    void on_AlterButton_clicked();

private:
    Ui::plAlterDialog *ui;
    int pri; //以下信息用于比较是否更改了航班信息
    QString comp;
    QString fE;
    QString tE;
    QString fTE;
    QString tTE;
};

#endif // PLALTERDIALOG_H
