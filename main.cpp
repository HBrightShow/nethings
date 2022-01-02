
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



#include "nethings.h"
#include "muduo/base/Logging.h"
#include "muduo/net/EventLoop.h"
#include "system/system.h"
#include "system/common.h"
#include "system/cmdline.h"

#include "mysql/DBPool.h"
#include "mysql/DBConn.h"
#include "mysql/TableOPerator.h"
#include "mysql/Common.h"

#include <hiredis/hiredis.h>



// using namespace muduo;
// using namespace muduo::net;

namespace opt = boost::program_options;
namespace bfs = boost::filesystem;




int set_env(){

    umask(077);

    return 0;
}



int create_config_file(std::string cfg) {
    try {
    
        int fd = open(cfg.c_str(), O_CREAT | O_WRONLY, 0666);
        if(fd == -1){
            return -1;
        }else {
            close(fd);
        }
        
        bpt::ptree root,resource,version;
        version.put<std::string>("version", "1.0");
        root.add_child("Nethings", version);

        bpt::ptree sqlInfo;
        sqlInfo.put<std::string>("ip","192.168.2.65");
        sqlInfo.put<int>("port", 3306);
        sqlInfo.put<std::string>("user","net");
        sqlInfo.put<std::string>("password","123456");
        sqlInfo.put<std::string>("dbName", "shop");
        root.add_child("Nethings.mysql", sqlInfo);

        bpt::ptree redisInfo;
        redisInfo.put<std::string> ("ip", "192.168.2.65");
        redisInfo.put<int>("port", 6379);
        root.add_child("Nethings.redis", redisInfo);

        bpt::write_xml(cfg, root, std::locale(), bpt::xml_writer_make_settings<std::string>('\t',1));

        

    }catch(...) {
        std::string err = "create_config_file() failed!";
        std::cout << err << std::endl;
        write_log_to_file(err);
    }
    

    return 0;
}

#if 0
int init_config_file(const std::string& cfg){
    try{
        App& app = App::GetInstance();
        

        bfs::path cfg_path(cfg);
        boost::system::error_code err_code;

        auto file_status = bfs::status(cfg_path, err_code);
        
        if(err_code.value() != 0 || !bfs::exists(file_status)) {
            create_config_file(cfg);
        }

        if(!bfs::is_directory(file_status)) {

            if(read_config_file(cfg)){
                return -1;
            }
        }
        else {
            std::string err = std::string("Error code: ") + std::to_string(ERROR_CONFIG_FILE_EXIST);
            write_log_to_file(err);
            return -2;
        }
    }catch(...){
        std::string err = "init_config_file() failed!\n";
        write_log_to_file(err);
    }
    return 0;
}
#endif
void test_mysql(){

    
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
    
    App& app = App::GetInstance();
    std::string log = "start serverpid=" + std::to_string(getpid()) + "\n";
    write_log_to_file(log);


    if(set_env() < 0) {
        return -1;
    }




   opt::options_description desc("Usage: Data collection system for server");
    desc.add_options()
    ("help,h", "server help message")
    ("configfile,c", opt::value<std::string>()->default_value("./"), "set the path of config file");

    opt::variables_map vm;

    try {
        opt::store(opt::parse_command_line(argc, argv, desc), vm);
    }
    catch(opt::error& e){
        std::cout << e.what() << std::endl;
        std::string err = std::string(e.what()) + "\n";
        write_log_to_file(err);
        return -2;
    }
    
    opt::notify(vm);    

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 0;
    }

    //std::map<std::string, boost::any>  cmd;

    //default path of confile file
    std::string cfg_default = App::GetInstance().g_workpath + "/" + name_config_file;

    std::string key;
    Cmdline cmd;
    cmd.init();

    if (vm.count("configfile")|| vm.count("c")) {
        
        key = std::string("configfile");
        std::string cfg_user = vm[key].as<std::string>();
        char cfg_buf[PATH_MAX];
        memset(cfg_buf, 0, sizeof(cfg_buf));
        realpath(cfg_user.c_str(), cfg_buf);
        cfg_user = cfg_user + "/" + name_config_file;
        
        cmd.addData(key, cfg_user);

        //std::cout <<  boost::any_cast<std::string&>(cmd["configfile"]) << std::endl;

    #if 0


        if(cfg_user != cfg_default) {
            
            if(read_config_file(cfg_user) < 0) {
                return -3;
            }
        }else {
            
            if(init_config_file(cfg_default)) {
                return -4;
            }
        }

    #endif

    } 
    else {
 
        #if 0
        if(init_config_file(cfg_default))
        {
            return -5;
        }    
        #endif
    }

    cmd.parCmdline();
    cmd.initDefaultCmd();
   

    test_mysql();
    test_redis();
    
 #if 1
  muduo::net::EventLoop loop;
  muduo::net::InetAddress listenAddr(6666);
  NethingsServer server(&loop, listenAddr);
  server.start();
  loop.loop();

  #endif 


  return 0;
}

