#include<iostream>
#include<unistd.h>
#include<linux/limits.h>
#include "system.h"
#include "common.h"



App &App::getInstance()
{
    // 局部静态特性的方式实现单实例
    static App signal;
    return signal;
}

App::App()
{
    init();
}

App::~App()
{
    
}

int App::init()
{
    setLogInfo();

    return 0;
}

bool App::setLogInfo(){

    //init path of worksapce
    char buf[PATH_MAX];
    memset(buf, 0, sizeof(buf));
    getcwd(buf, PATH_MAX);
    g_workpath = std::string(buf);

    g_logfile = std::unique_ptr<muduo::LogFile>(new muduo::LogFile(g_workpath + "/" + name_log_file, max_logfile_size_rollback,true ));
}

void App::write_log_to_file(std::string info) {
    g_logfile.get()->append(info.c_str(), info.length());
}


