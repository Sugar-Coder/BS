#ifndef SQLOP_H
#define SQLOP_H

#include "mysqlapi.h"
#include <string>
#include <QDebug>
#include <string.h>

class DB{
private:
    char host[30];
    char user[30];
    unsigned int port;
    char passwd[30];
    char dbname[30];
    char charset[30];
    char *Msg;
    connectMysql *connector;
public:
    DB();  //默认构造函数
    ~DB(); //析构函数
    DB(char *DBname);  //选择数据库并连接
    //查询语句返回查询结果,col代表查询的列数
    std::string selectAll(std::string select,std::string from,int col);
    std::string selectSql(std::string select,std::string from,std::string where,int col);
    //插入注册用户信息，要判断重复
    std::string insertUser(const int id,std::string name,const int password);
    //删除用户信息
    std::string deleteUser(const int id);
    //更改用户信息
    std::string updateUser(const int id,std::string username,const int password);
    //插入订票信息
    std::string insertOrder(int userid,int planeid,int num);
    //删除订票信息
    std::string deleteOrder(int userid,int planeid);
    //更改航班信息
    //std::string updatePlane(std::string field,std::string new_value);
};

#endif // SQLOP_H