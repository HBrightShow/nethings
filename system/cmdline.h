#ifndef _CMDLINE_H_
#define _CMDLINE_H_

#include "./common.h"

class Cmdline{
    public:
        Cmdline() = default;
        ~Cmdline() {}


        bool init();
        bool initDefaultCmd();
        bool parCmdline();
        void addData(const std::string& key, boost::any& value);

    private:
        bool loadConfigFile(const std::string& cfg_user);
        bool read_config_file(const std::string& cfg);


    private:
        typedef std::map<std::string, boost::any>  CmdMap;
        CmdMap  cmdByUsers;
        CmdMap  cmdDfault;


        stXmlCfg m_xmlCfg;
};



#endif