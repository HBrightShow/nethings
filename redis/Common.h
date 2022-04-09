#ifndef _REDIS_COMMON_H_
#define _REDIS_COMMON_H_




namespace redisMode {

typedef struct stRedisInfo{
    std::string  ip;
    std::string  port;
}stRedisInfo,*PstRedisInfo;

};








#endif