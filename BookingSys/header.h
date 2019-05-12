#ifndef HEADER_H
#define HEADER_H
#include "sqlop.h"
#include "initer.h"

extern DB db;  //全局类，用于操纵数据库，声明可以重复多次，用于包含在各个头文件中
extern initer init;

#endif // HEADER_H
