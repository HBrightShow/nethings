#ifndef _MYSQL_COMMON_H_
#define _MYSQL_COMMON_H_

#include<mysql.h>
#include<iostream>
#include<list>
#include<cstring>


namespace mysql {


struct stMysqlConnInfo{
    std::string dbServerIp;
    std::string dbPort;
    std::string dbName;
    std::string dbUser;
    std::string dbPassword;
};

};
#endif