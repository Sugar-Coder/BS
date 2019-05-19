#ifndef INITER_H
#define INITER_H
#include <string>

using std::string;

typedef struct Status
{
    bool Admin;
    bool login;
}status;

class initer
{
private:
    static status state; //登录状态，是否为管理员还是用户
    static string AdminName;
    static int AdminPassword;
    static string user; //已登陆的用户名，初值为null
    static int userid;
    static int planeid; //正在操作的航班号(添加、删除)
public:
    initer();
    ~initer();
    bool isAdmin(){return state.Admin;} //是否是管理员
    bool AdminQuit(){state.Admin = false;} //管理员退出
    bool islogin(){return state.login;} //是否是用户登录
    bool setlogin(string name,int password); //在登录窗口判断是否登录
    void setCurrentUser(string name){user = name;} //重新设置当前用户
    string currentUser(){return user;}  //返回当前用户
    void userQuit(){user = "null"; userid = -1; state.login = false;}  //用户退出登录
    string planeFormat(string searchResult); //格式化输出plane信息
    int currentUserid(){return userid;} //返回当前用户id
    string orderFormat(string myorder); //格式化输出order信息
    void setPlaneid(int id){planeid = id;} //设置当前正在操作的航班号
    int currentPlaneid(){return planeid;} //返回当前正在操作的航班号
};

#endif // INITER_H
