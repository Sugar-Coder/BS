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
public:
    initer();
    ~initer();
    bool isAdmin(){return state.Admin;} //是否是管理员
    bool islogin(){return state.login;} //是否是用户登录
    bool setlogin(string name,int password); //在登录窗口判断是否登录
    void setCurrentUser(string name){user = name;} //重新设置当前用户
    string currentUser(){return user;}  //返回当前用户
    void userQuit(){user = "null"; userid = -1; state.login = false;}  //用户退出登录
    string planeFormat(string searchResult); //格式化输出plane信息
    int currentUserid(){return userid;} //返回当前用户id
    string orderFormat(string myorder); //格式化输出order信息
};

#endif // INITER_H
