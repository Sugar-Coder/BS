#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "selfmesdialog.h" //个人信息界面

namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private slots:
    void on_inquireButton_clicked(bool checked);

    void on_exitButton_clicked();

    void on_exchangeButton_clicked();

    void on_bookButton_clicked();

    void on_userButton_clicked();

private:
    Ui::mainWidget *ui;
    //selfmesDialog *selfdlg = new selfmesDialog;
};

#endif // MAINWIDGET_H
