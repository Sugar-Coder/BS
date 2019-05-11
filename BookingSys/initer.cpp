#include "initer.h"

using namespace std;

string initer::AdminName = "admin";
int initer::AdminPassword = 888;
status initer::state = {false,false};

DB db = DB("BookingSystem");

initer::initer()
{

}

initer::~initer()
{

}

bool initer::setlogin(string name,int password)
{
    int i=0;
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
        if(result.compare(to_string(password))==1)
        {
            state.login = true;
            return true;
        }
        else
            return false; //密码错误
    }
    else
        return false;  //用户名错误
}
