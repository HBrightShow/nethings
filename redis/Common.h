#ifndef _REDIS_COMMON_H_
#define _REDIS_COMMON_H_




namespace redisMode {

typedef struct stRedisInfo{
    std::string  ip;
    std::string  port;
}stRedisInfo,*PstRedisInfo;

};

typedef enum en_redisResultType
{
    redis_reply_invalid = -1,
    redis_reply_string,
    redis_reply_integer,
    redis_reply_array,
    redis_reply_null
}redisResultType;

#endif