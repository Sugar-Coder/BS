#include "mainwidget.h"
#include <QApplication>
#include <mysqlapi.h>
#include <sqlop.h>
#include <QDebug>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWidget w;
    loginDialog ldialog;
    if(ldialog.exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else return 0;
    //DB db = DB("BookingSystem");
    //string result = db.selectAll("*","plane",7);
    //qDebug() << result.data();
    //qDebug() << db.insertUser(1,"testuser",12345).data();
    //qDebug() << db.selectSql("*","order","num=1",3).data();
    //qDebug() << db.deleteUser(1).data();
    //qDebug() << db.updateUser(1,"tuser",123).data();
    //qDebug() << db.insertOrder(2,2002,1).data();
    //qDebug() << db.deleteOrder(1,1092).data(); //删除的一直为success
}
