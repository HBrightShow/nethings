#ifndef _MYSQL_COMMON_H_
#define _MYSQL_COMMON_H_

#include<mysql.h>
#include<iostream>
#include<list>
#include<cstring>


namespace mysql {


struct stMysqlInfo{
    std::string ip;
    std::string port;
    std::string name;
    std::string user;
    std::string pwd;
};

};
#endif