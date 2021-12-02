
#include<iostream>
#include <unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<boost/program_options.hpp>
#include<boost/filesystem.hpp>
#include<boost/property_tree/xml_parser.hpp>
#include<boost/property_tree/ptree.hpp>


#include "nethings.h"
#include "muduo/base/Logging.h"
#include "muduo/net/EventLoop.h"
#include "system/system.h"
#include "system/common.h"



// using namespace muduo;
// using namespace muduo::net;

namespace opt = boost::program_options;
namespace bfs = boost::filesystem;
namespace bpt = boost::property_tree;

int set_env(){

    umask(077);

    return 0;
}

void write_log_to_file(std::string info) {
    App::GetInstance().g_logfile.get()->append(info.c_str(), info.length());
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
        sqlInfo.put<std::string>("ip","127.0.0.1");
        sqlInfo.put<int>("port", 8000);
        sqlInfo.put<std::string>("user","sa");
        sqlInfo.put<std::string>("password","bright=250");
        root.add_child("Nethings.mysql", sqlInfo);

        bpt::write_xml(cfg, root, std::locale(), bpt::xml_writer_make_settings<std::string>('\t',1));

        

    }catch(...) {
        std::string err = "create_config_file() failed!";
        std::cout << err << std::endl;
        write_log_to_file(err);
    }
    

    return 0;
}

int read_config_file(std::string cfg) {

    bpt::ptree root;
    try{
        
        bpt::read_xml(cfg, root);

    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
        std::string err = std::string("read_config_file() ") + e.what() + "\n"; 
        write_log_to_file(err);

        return -1;
    }

    std::string version = root.get<std::string>("Nethings.version");

    bpt::ptree sql_info = root.get_child("Nethings.mysql");
    for(auto& v : sql_info) {
        std::cout << v.first << ":" << v.second.data() << std::endl;
    }

    return 0;
}

int init_config_file(std::string cfg){
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

    //default path of confile file
    std::string cfg_default = App::GetInstance().g_workpath + "/" + name_config_file;

    if (vm.count("configfile")|| vm.count("c")) {
     
        std::string cfg_uesr = vm["configfile"].as<std::string>();

        char cfg_buf[PATH_MAX];
        memset(cfg_buf, 0, sizeof(cfg_buf));
        realpath(cfg_uesr.c_str(), cfg_buf);
        
        std::string cfg_user = std::string(cfg_buf);
        
        std::cout << cfg_user<< std::endl;
        cfg_user = cfg_user + "/" + name_config_file;


        if(cfg_user != cfg_default) {
            
            if(read_config_file(cfg_user) < 0) {
                return -3;
            }
        }else {
            
            if(init_config_file(cfg_default)) {
                return -4;
            }
        }

    } 
    else {
        
        if(init_config_file(cfg_default))
        {
            return -5;
        }    
    }







 #if 0 
  muduo::net::EventLoop loop;
  muduo::net::InetAddress listenAddr(6666);
  NethingsServer server(&loop, listenAddr);
  server.start();
  loop.loop();

  #endif 


  return 0;
}

