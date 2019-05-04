#include "mysqlapi.h"
using std::string;

connectMysql::connectMysql()
{
}

connectMysql::~connectMysql()
{
}

int connectMysql::ConnMysql(char *host,unsigned int port, char *Db,char *user, char *passwd, char *charset, char *Msg)
{
    if(mysql_init(&mysql)==NULL)
    {
        strcpy(Msg,"initial mysql handle error");
        return 1;
    }
    if(mysql_real_connect(&mysql, host, user, passwd, Db, port, NULL, 0)==NULL)
    {
        strcpy(Msg, "Failed to connect to database: Error");
        return 1;
    }
    if(mysql_set_character_set(&mysql,charset)!=0)
    {
        strcpy(Msg, "mysql_set_character_set Error");
        return 1;
    }
    return 0;
}

string connectMysql::SelectData(char *SQL, int Cnum, char *Msg)
{
    MYSQL_ROW m_row;
    MYSQL_RES *m_res;
    char sql[2048];
    sprintf(sql,"%s", SQL);
    int rnum = 0;

    if(mysql_query(&mysql,sql) != 0)
    {
        strcpy(Msg,"select ps_info Error");
        return "";
    }
    m_res =mysql_store_result(&mysql);
    if(m_res==NULL)
    {
        strcpy(Msg, "select username error");
        return "";
    }
    string str("");
    while(m_row =mysql_fetch_row(m_res))
    {
        for(int i=0;i<Cnum;i++)
        {
            str += m_row[i];
            str += cg;
        }
        str += rg;
        rnum++;
    }
    mysql_free_result(m_res);
    return str;
}

int connectMysql::InsertData(char *SQL, char *Msg)
{
    char sql[2048];
    sprintf(sql,"%s", SQL);
    if(mysql_query(&mysql, sql)!=0)
    {
        strcpy(Msg, "Insert data error");
        return 1;
    }
    return 0;
}

int connectMysql::UpdateData(char *SQL, char *Msg)
{
    char sql[2048];
    sprintf(sql,"%s", SQL);
    if(mysql_query(&mysql, sql)!=0)
    {
        strcpy(Msg, "Update data error");
        return 1;
    }
    return 0;
}

int connectMysql::DeleteData(char *SQL, char *Msg)
{
    char sql[2048];
    sprintf(sql,"%s", SQL);
    if(mysql_query(&mysql, sql)!=0)
    {
        strcpy(Msg, "Delete data error");
        return 1;
    }
    return 0;
}

void connectMysql::CloseMysqlConn()
{
    mysql_close(&mysql);
}
