#include<iostream>
#include<unistd.h>
#include "system.h"
#include "common.h"



App &App::GetInstance()
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
    //init path of worksapce
    char buf[max_file_path_size];
    memset(buf, 0, sizeof(buf));
    getcwd(buf, max_file_path_size);
    g_workpath = std::string(buf);

    g_logfile = std::unique_ptr<muduo::LogFile>(new muduo::LogFile(g_workpath + "/" + name_log_file, max_logfile_size_rollback,true ));

    return 0;
}