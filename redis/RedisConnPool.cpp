#include "./RedisConnPool.h"


using namespace redisMode;

std::vector<std::shared_ptr<CRedisConn>> CRedisConnPool::connect_pool_;
std::mutex CRedisConnPool::mtx_;



bool CRedisConnPool::init(std::string ip, int port, std::string pwd,int db, int pool_size) {

    bool flag = true;
    if(pool_size <= 0)
    {
        flag = false;
    }
    mtx_.lock();
    
    for (int i = 0; i < pool_size; ++i) {
        //实例化连接
        CRedisConn* con = new CRedisConn();
        if(con->Connect(ip,port,pwd,db))
        {
            //放入连接池
            connect_pool_.push_back(std::shared_ptr<CRedisConn>(con));
        }else{
            std::cerr << "connect redirs :" <<ip << ":" << port << pwd << "failed" << std::endl;
        }
    }

    mtx_.unlock();

    int real_pool_size = connect_pool_.size();
    if(pool_size > real_pool_size)
    {
        std::cerr << "redis pool init failed! hope pool size:" << pool_size << "real size is " << real_pool_size << std::endl;
        flag = false;
    }else{
        std::cout << "redis pool init success! pool size:" << real_pool_size << std::endl;
    }

    return flag;
}


std::shared_ptr<CRedisConn> CRedisConnPool::Get() {

    mtx_.lock();
    if(connect_pool_.size() == 0)
    {
        throw "Zzredis pool is empty";
    }
    //从连接容器里返回一个连接
    std::shared_ptr<CRedisConn> tmp = connect_pool_.front();
    connect_pool_.erase(connect_pool_.begin());
    mtx_.unlock();
    return tmp;
}

void CRedisConnPool::Back(std::shared_ptr<CRedisConn> &con) {
    mtx_.lock();
    //归还到容器
    connect_pool_.push_back(con);
    mtx_.unlock();
}

int CRedisConnPool::size() {

    mtx_.lock();
    int size = connect_pool_.size();
    mtx_.unlock();
    return size;
}