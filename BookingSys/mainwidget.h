#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

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

private:
    Ui::mainWidget *ui;
};

#endif // MAINWIDGET_H
