#ifndef _CMDLINE_H_
#define _CMDLINE_H_

#include "./common.h"

typedef std::map<std::string, boost::any>  CmdMap;

class Cmdline{
    private:
        
        CmdMap  cmdByUsers;
        CmdMap  cmdDfault;
        stXmlCfg m_xmlCfg;
    public:
        Cmdline() = default;
        ~Cmdline() {}


        bool init();
        bool initDefaultCmd();
        bool parCmdline();
        void addData(const std::string& key, const boost::any& value);
        bool  createConfigFile(std::string cfg);

    private:
        bool loadConfigFile(const std::string& cfg_user);
        bool readConfigFile(const std::string& cfg);
        const CmdMap& CompareMap(const CmdMap &mapSrc, const CmdMap &mapDst, CmdMap& diffMap);
        bool initConfigFile(const std::string& cfg);



};



#endif