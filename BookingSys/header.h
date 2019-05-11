#ifndef HEADER_H
#define HEADER_H
#include "sqlop.h"

extern DB db;  //全局类，用于操纵数据库

typedef struct Status
{
    bool Admin;
    bool login;
}status;

#endif // HEADER_H
