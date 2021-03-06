#ifndef _NETHING_COMMON_H_
#define _NETHING_COMMON_H_

#include<iostream>
#include<map>
#include<boost/any.hpp>

#include "../mysql/Common.h"
#include "../redis/Common.h"


const uint32_t max_logfile_size_rollback = 1024*1024*20;

const std::string name_config_file = "config.xml";

const std::string name_log_file = "server-";





enum  global_error_code{
    ERROR_CONFIG_FILE_EXIST = 100,  // name of config file used by dir
};



typedef struct stXmlCfg{
    mysql::stMysqlInfo mysqlInfo;
    redisMode::stRedisInfo redisInfo;
}stXmlCfg,*PstXmlCfg;


class Common{
    public:
        Common();
        ~Common();



};


#endif


