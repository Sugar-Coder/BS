#include "header.h"

using namespace std;
//类中的静态变量必须单独定义
string initer::AdminName = "admin";
int initer::AdminPassword = 888;
status initer::state = {false,false};
string initer::user = "null";
int initer::userid = -1;

DB db = DB("BookingSystem"); //全局类的定义，只能定义一次

initer::initer()
{

}

initer::~initer()
{

}

bool initer::setlogin(string name,int password)
{
    if(name.compare(AdminName)==0 && password == AdminPassword)
    {
        state.Admin = true;
        return true;
    }
    string result;
    string nm = "name='";
    nm += name;
    nm += "'";
    result = db.selectSql("password","user",nm,1);

    if(result.compare("NULL")!=0)
    {
        int temp = atoi(result.data()); //把查询的结果转换为int类型
        if(temp == password)
        {
            state.login = true;
            this->user = name;  //将状态保存为该用户的登录状态
            int id = atoi(db.selectSql("id","user",nm,1).data());
            this->userid = id;
            qDebug() << id;
            return true;
        }
        else
            return false; //密码错误
    }
    else
        return false;  //用户名错误
}

string initer::planeFormat(string searchResult)
{
    int i=0;
    int colcounter=0;
    string buffer="航班号\t座位剩余\t票价\t出发\t到达\t航空公司\t\t起降时间\t日期\n";
    while(i<searchResult.length())
    {
        if(searchResult[i]!=rg&&searchResult[i]!=cg)
        {
            buffer+=searchResult[i++];
        }
        else if(searchResult[i]==cg){ //列分隔符
            i++;
            colcounter ++;
            if(colcounter==6) //对于航空公司，多给一些地方
            buffer += "\t\t|";
            else {
                buffer += "\t|";
            }
        }
        else if(searchResult[i]==rg){ //行分隔符
            i++;
            colcounter = 0;
            buffer += '\n';
        }
    }
    //qDebug() << buffer.data();
    return buffer;
}

string initer::orderFormat(string myorder)
{
    int i=0;
    string buffer = "航班号\t订票数量\t出发\t到达\n";
    while(i<myorder.length())
    {
        if(myorder[i]!=rg&&myorder[i]!=cg)
        {
            buffer += myorder[i++];
        }
        else if(myorder[i]==cg){ //列分隔符
            i++;
            buffer += "\t|";
        }
        else if(myorder[i]==rg){//行分割
            i++;
            buffer+="\n";
        }
    }
    return buffer;
}
