#include "sqlop.h"

DB::DB()
{
    Msg = nullptr;
    connector = nullptr;
}

DB::~DB()
{
    connector->CloseMysqlConn();
}

DB::DB(char * DBname)
{
    strcpy(host,"localhost");
    strcpy(user,"root");
    port = 3306;
    strcpy(passwd,"newpass");
    strcpy(dbname,DBname);
    strcpy(charset,"utf8");
    Msg = NULL;
    connector = new connectMysql;
    if(connector->ConnMysql(host, port, dbname, user, passwd, charset, Msg))
    qDebug() << Msg;
    else
    qDebug()<< "连接成功";
}

std::string DB::selectAll(std::string select,std::string from,int col)
{
    std::string sqlstr ="SELECT ";
    sqlstr+=select;
    sqlstr+=" FROM ";
    sqlstr+=from;

    char * SQL = (char *)sqlstr.data();
    string result = connector->SelectData(SQL,col,Msg);
    if(result.length()>0)
    {
        qDebug() << "查询成功";
        return result;
    }
    else{ //啥都没查到
        qDebug()<<Msg;
        return "NULL";
    }
}

std::string DB::selectSql(std::string select,std::string from,std::string where,int col) //选择order表时用BookingSystem.order
{
    std::string sqlstr ="SELECT ";
    sqlstr+=select;
    sqlstr+=" FROM ";
    sqlstr+=from;
    sqlstr+=" WHERE ";
    sqlstr+=where;
    char * SQL = (char *)sqlstr.data();
    string result = connector->SelectData(SQL,col,Msg);
    if(result.length()>0)
    {
        qDebug() << "查询成功";
        return result;
    }
    else{ //啥都没查到
        qDebug()<<Msg;
        return "NULL";
    }
}

//插入重复主键的元组会发生异常退出
std::string DB::insertUser(const int id, std::string name, const int password)
{
    std::string sqlstr = "INSERT INTO user(id,name,password) VALUES(";
    sqlstr += std::to_string(id);
    sqlstr += ",'";
    sqlstr += name;
    sqlstr += "',";
    sqlstr += std::to_string(password);
    sqlstr += ")";
    char *SQL = (char *)sqlstr.data();
    if(connector->InsertData(SQL,Msg)==0)
        return "插入成功";
    return "failed";
}

std::string DB::deleteUser(const int id)
{
    std::string sqlstr = "DELETE FROM user WHERE id =";
    sqlstr += std::to_string(id);
    char *SQL = (char *)sqlstr.data();
    if(connector->DeleteData(SQL,Msg) == 0)
         return "success";
    return "failed";
}

std::string DB::updateUser(const int id,std::string username, const int password)
{
    std::string sqlstr = "UPDATE user SET ";
    if(username != "unchange")
    {
        sqlstr += " name = '";
        sqlstr += username;
        sqlstr += "'";
    }
    if(password!=-1)
    {
        sqlstr += " password = ";
        sqlstr += std::to_string(password);
    }
    sqlstr += " WHERE id =";
    sqlstr += std::to_string(id);
    char *SQL = (char *)sqlstr.data();
    if(connector->UpdateData(SQL,Msg)==0)
        return "success";
    return "failed";
}

std::string DB::insertOrder(int userid, int planeid,int num)
{
    std::string sqlstr = "INSERT INTO BookingSystem.order(num,userid,planeid) VALUES(";
    sqlstr += std::to_string(num);
    sqlstr += ",";
    sqlstr += std::to_string(userid);
    sqlstr += ",";
    sqlstr += std::to_string(planeid);
    sqlstr += ")";
    char *SQL = (char *)sqlstr.data();
    if(connector->InsertData(SQL,Msg)==0)
        return "插入成功";
    return "failed";
}

std::string DB::deleteOrder(int userid, int planeid)
{
    std::string sqlstr = "DELETE FROM BookingSystem.order WHERE userid=";
    sqlstr += std::to_string(userid);
    sqlstr += " AND planeid=";
    sqlstr += std::to_string(planeid);
    char *SQL = (char *)sqlstr.data();
    if(connector->DeleteData(SQL,Msg) == 0)
         return "success";
    return "failed";
}

std::string DB::updatePlaneSeats(int newSeatsNum, int pid)
{
    std::string sqlstr = "UPDATE plane SET seatsnum =";
    sqlstr += std::to_string(newSeatsNum);
    sqlstr += " WHERE pid = ";
    sqlstr += std::to_string(pid);
    char *SQL = (char *)sqlstr.data();
    if(connector->UpdateData(SQL,Msg) == 0)
        return "success";
    return "failed";
}
