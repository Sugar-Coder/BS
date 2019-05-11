#ifndef INITER_H
#define INITER_H
#include "header.h"
#include <string>

using std::string;

class initer
{
private:
    static status state;
    static string AdminName;
    static int AdminPassword;
public:
    initer();
    ~initer();
    bool isAdmin(){return state.Admin;}
    bool islogin(){return state.login;}
    bool setlogin(string name,int password);
};

#endif // INITER_H
