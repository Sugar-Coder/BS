#include "mainwidget.h"
#include <QApplication>
//#include <sqlop.h>
#include <QDebug>
#include "logindialog.h"
#include "header.h"
//#include "initer.h" //header include initer


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginDialog ldialog;
    ldialog.setWindowTitle(QObject::tr("登陆"));

    if(ldialog.exec()==QDialog::Accepted)
    {
        mainWidget w;
        w.setWindowTitle(QObject::tr("订票系统"));
        w.show();
        initer ini;
        return a.exec();
    }
    else return 0;
    //DB db = DB("BookingSystem");
    //string result=db.selectSql("id","user","name = 'u'",1);
    //string result = db.selectAll("*","plane",7);
    //qDebug() << result.data();
    //qDebug() << db.insertUser(1,"testuser",12345).data();
    //qDebug() << db.selectSql("*","BookingSystem.order","userid=2",3).data();
    //qDebug() << db.deleteUser(1).data();
    //qDebug() << db.updateUser(1,"tuser",123).data();
    //qDebug() << db.insertOrder(2,2002,1).data();
    //qDebug() << db.deleteOrder(1,1092).data(); //删除的一直为success
    /*
    DB db = DB("BookingSystem");
    string result = db.selectSql("password","user","name='tuser'",1);
    qDebug() << result.data();
    bool judg = result.compare(std::to_string(123));
    qDebug() << judg;*/
}
