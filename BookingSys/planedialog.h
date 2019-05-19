#ifndef PLANEDIALOG_H
#define PLANEDIALOG_H

#include <QDialog>

namespace Ui {
class planeDialog;
}

class planeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit planeDialog(QWidget *parent = nullptr);
    ~planeDialog();

private slots:
    void on_commitButton_clicked();

private:
    Ui::planeDialog *ui;
};

#endif // PLANEDIALOG_H
