#ifndef CONFIG_H
#define CONFIG_H

namespace mysql {
namespace sqlinfo {

        static const char *dbPoolName = "mypool";
        static const char* dbHost = "127.0.0.1";
        static const int   dbPort = 3306;
        static const char* dbDBname = "test_pool";
        static const char* dbUserName = "root";
        static const char* dbPassword = "12345678";
        static const int   dbMaxConnCnt = 4;

};

};


#endif
