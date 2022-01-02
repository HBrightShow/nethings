#include<boost/property_tree/xml_parser.hpp>
#include<boost/property_tree/ptree.hpp>

#include "./cmdline.h"
#include "./system.h"


namespace bpt = boost::property_tree;

bool Cmdline::init() {
    cmdDfault["configfile"] = App::getInstance().g_workpath + "/" + name_config_file;

    return true;
}

void Cmdline::addData(const std::string& key, boost::any& value) {
    cmdByUsers[key] = value;
}


bool Cmdline::parCmdline() {

    std::map<std::string, boost::any>::iterator it;
    for(it = cmdByUsers.begin(); it != cmdByUsers.end(); ++it) {
        if (it->first == std::string("configfile")){
            std::string cfg_user = boost::any_cast<std::string&>(it->second);
            if(!loadConfigFile(cfg_user)) {
                return false;
            }
        }
    }
}

bool Cmdline::loadConfigFile(const std::string& cfg_user) {


    return true;
}


bool Cmdline::read_config_file(const std::string& cfg) {

    bpt::ptree root;
    try{
        bpt::read_xml(cfg, root);
        std::string strKey;

        std::string version = root.get<std::string>("Nethings.version");
        bpt::ptree sqlInfo = root.get_child("Nethings.mysql");

        for(auto& v : sqlInfo) {
            strKey = v.first;
            if (strKey == std::string("ip")) {
                m_xmlCfg.mysqlConnInfo.dbServerIp = v.second.data();
            }
            else if(strKey == std::string("port")) {
                m_xmlCfg.mysqlConnInfo.dbPort = v.second.data();
            }
            else if(strKey == std::string("user")) {
                m_xmlCfg.mysqlConnInfo.dbName = v.second.data();
            }
            else if(strKey == std::string("dbName")) {
                m_xmlCfg.mysqlConnInfo.dbUser = v.second.data();
            }
            else if(strKey == std::string("password")) {
                m_xmlCfg.mysqlConnInfo.dbPassword = v.second.data();
            }
            else {
                std::string info = std::string("read_config_file()  unknown mysql config") + "\n"; 
                App::getInstance().write_log_to_file(info);
            }

            std::cout << v.first << ":" << v.second.data() << std::endl;

        }
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
        std::string err = std::string("read_config_file() ") + e.what() + "\n"; 
        App::getInstance().write_log_to_file(err);
        return false;
    }

    return true;
}

bool Cmdline::initDefaultCmd() {
    

    return true;
}
