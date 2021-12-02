#ifndef _NETHINGS_SYSTEM_H_
#define _NETHINGS_SYSTEM_H_

#include<iostream>
#include "muduo/base/LogFile.h"

class App
{

public:
    // 获取单实例对象
    static App &GetInstance();

public:
    //workspace of app
    std::string g_workpath;

    //logfile ptr
    std::unique_ptr<muduo::LogFile> g_logfile;


private:
    // 禁止外部构造
    App();

    // 禁止外部析构
    ~App();

    // 禁止外部复制构造
    App(const App &signal);

    // 禁止外部赋值操作
    const App &operator=(const App &signal);

    int  init();

private:
    
};


#endif