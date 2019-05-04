#ifndef MYSQLAPI_H
#define MYSQLAPI_H
#include "mysql.h"
#include <string.h>
#include <string>
using std::string;

const char rg = 0x06;//行隔开符
const char cg = {0x05};//列隔开符

class connectMysql
{
public:
    MYSQL mysql;
    connectMysql(); //构造函数
    ~connectMysql(); //析构函数
    /*
            主要的功能：
            初始化数据库
            连接数据库
            设置字符集

            入口参数：
            host ：MYSQL服务器IP
            port:数据库端口
            Db：数据库名称
            user：数据库用户
            passwd：数据库用户的密码
            charset：希望使用的字符集
            Msg:返回的消息，包括错误消息

            出口参数：
            int ：0表示成功；1表示失败
            */
    int ConnMysql(char *host,unsigned int port, char *Db,char *user, char *passwd, char *charset, char *Msg);
    int InsertData(char *SQL,char *Msg);
    /*
          主要的功能：
          查询数据

          入口参数：
          SQL：查询的SQL语句
          Cnum:查询的列数
          Msg:返回的消息，包括错误消息

          出口参数：
          string 准备放置返回的数据，多条记录则用0x06隔开,多个栏位用0x05隔开
          如果 返回的长度＝ 0，责表示无结果
          */
    string SelectData(char *SQL,int Cnum ,char *Msg);
    int UpdateData(char *SQL,char *Msg);
    int DeleteData(char *SQL,char *Msg);
    void CloseMysqlConn();
};
#endif // MYSQLAPI_H
