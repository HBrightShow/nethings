
#include<iostream>
#include <unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<map>
#include<boost/any.hpp>
#include<boost/program_options.hpp>
#include<boost/filesystem.hpp>
#include <hiredis/hiredis.h>
#include "./core/nethings.h"
#include "muduo/base/Logging.h"
#include "muduo/net/EventLoop.h"
#include "system/system.h"
#include "system/common.h"
#include "system/cmdline.h"
#include "mysql/DBPool.h"
#include "mysql/DBConn.h"
#include "mysql/TableOPerator.h"
#include "mysql/Common.h"
#include "mysql/ResultSet.h"

// using namespace muduo;
// using namespace muduo::net;
namespace opt = boost::program_options;
namespace bfs = boost::filesystem;


int set_env(){
    umask(077);
    return 0;
}

void test_mysql(){
    mysql::DBPool *pool = new mysql::DBPool("mypool", "192.168.2.65", 3306, "net", "123456", "shop", 2);
	if (pool->init())
	{
		return;
	} 
    else {
        std::cout << "mysql init success." << std::endl;
    }

    mysql::DBConn *conn = pool->getDBConn();
	if (conn == NULL)
    {
        std::cout << "mysql connect failed." << std::endl;
    }
	
    // query
    std::string getAddress = "select * from address";
    mysql::ResultSet* result = conn->executeQuery(getAddress.c_str());
    //result->printMap();

    while(result->next()) {
        std::cout << result->getString("id") << std::endl;
        std::cout << result->getString("uid") << std::endl;
        std::cout << result->getString("phone") << std::endl;
        std::cout << result->getString("name") << std::endl;
        std::cout << result->getString("zipcode") << std::endl;
        std::cout << result->getString("address") << std::endl;
        std::cout << result->getString("default_address") << std::endl;
        std::cout << result->getString("add_time") << std::endl;
    }
    delete result;
    result = NULL;

    //insert
    std::string insertAddress = "INSERT INTO address (uid, phone, name, zipcode, address, default_address, add_time)VALUES(3, '18390987867', 'hml', '20000', '南昌社区',1, unix_timestamp(now()))";
    conn->executeUpdate(insertAddress.c_str(), true);
    
}

void test_redis() {
    redisContext* conn = redisConnect("0.0.0.0", 6379);

    if(conn->err) {
        std::cout << "connect redis falild!" << std::endl;
        return ;
    }
    else {
        std::cout << "connect redis success!" << std::endl;
    }

    redisReply* reply = (redisReply*)redisCommand(conn,"set foo 1234");
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(conn,"get foo");
    printf("%s\n",reply->str);
    freeReplyObject(reply);

    redisFree(conn);

    return ;
}


int main(int argc, char** argv)
{
    //test(argc, argv);
    App& app = App::getInstance();
    app.init();
    std::string log = "start serverpid=" + std::to_string(getpid()) + "\n";
    std::cout << "log: " << log << std::endl;
    app.write_log_to_file(log);

    Cmdline cmd;
    cmd.init();
    std::string key;





    opt::options_description opts("all options"); 
    opt::variables_map vm;

    opts.add_options()  
    ("config", opt::value<std::string>(), "config file not found")
    ("help", "help information of server");

    try{
        opt::store(opt::parse_command_line(argc, argv, opts), vm);
    }
    catch(...){
        std::cout << "invaild input." << std::endl;
        return 0;
    }

    if(vm.count("help") ){
        std::cout << opts << std::endl;   
    }

    if(vm.count("config") ){
        std::cout << "find " << vm["config"].as<std::string>() << std::endl;

        key = std::string("config");
        std::string cfg_user = vm[key].as<std::string>();
        char cfg_buf[PATH_MAX];
        memset(cfg_buf, 0, sizeof(cfg_buf));
        realpath(cfg_user.c_str(), cfg_buf);
        cfg_user = cfg_user + name_config_file;

        std::cout << "cfg_user: " << cfg_user << std::endl;
        
        cmd.addData(key, cfg_user);
    }
    if(vm.empty() ){
        //std::cout << "no options input" << std::endl;
    }
    
    //std::cout << "start par " << std::endl;

    if(!cmd.parCmdline()) {
        std::cerr << "cmd input error!" << std::endl;
        return -1;
    }
    cmd.initDefaultCmd();
   

    test_mysql();
    //test_redis();
    
 #if 0

  muduo::net::EventLoop loop;
  muduo::net::InetAddress listenAddr(6666);
  NethingsServer server(&loop, listenAddr);
  server.start();
  loop.loop();

  

#endif
  return 0;
}

