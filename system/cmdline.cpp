#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<boost/any.hpp>
#include<boost/property_tree/xml_parser.hpp>
#include<boost/property_tree/ptree.hpp>
#include<boost/filesystem.hpp>
#include "./cmdline.h"
#include "./system.h"


namespace bpt = boost::property_tree;
namespace bfs = boost::filesystem;

bool Cmdline::init() {
    cmdDfault["config"] = App::getInstance().g_workpath + "/" + name_config_file;

    return true;
}

void Cmdline::addData(const std::string& key, const boost::any& value) {
    cmdByUsers[key] = value;
}


bool Cmdline::parCmdline() {
    //std::cout << "parCmdline() +++++++ " << std::endl;
    
    std::map<std::string, boost::any>::iterator it;
    for(it = cmdByUsers.begin(); it != cmdByUsers.end(); ++it) {
        if (it->first == std::string("config")){
            std::string cfg_user = boost::any_cast<std::string&>(it->second);
            if(!loadConfigFile(cfg_user)) {
                return false;
            }
        }
    }

    //std::cout << "parCmdline() ------- " << std::endl;

    return true;
}

bool Cmdline::loadConfigFile(const std::string& cfg_user) {
    //std::cout << "loadConfigFile() +++++++ " << std::endl;
    std::cout << "cfg_user:" << cfg_user << std::endl;
    if(!readConfigFile(cfg_user)) {
        return false;
    }


    //std::cout << "loadConfigFile() ------- " << std::endl;
    return true;
}


bool Cmdline::readConfigFile(const std::string& cfg) {
    //std::cout << "readConfigFile() +++++++ " << std::endl;

    bpt::ptree root;
    try{
        bpt::read_xml(cfg, root);
        std::string strKey;

        std::string version = root.get<std::string>("Nethings.version");
        bpt::ptree sqlInfo = root.get_child("Nethings.mysql");
        for(auto& v : sqlInfo) {
            strKey = v.first;
            if (strKey == std::string("ip")) {
                m_xmlCfg.mysqlInfo.ip = v.second.data();
            }
            else if(strKey == std::string("port")) {
                m_xmlCfg.mysqlInfo.port = v.second.data();
            }
            else if(strKey == std::string("user")) {
                m_xmlCfg.mysqlInfo.name = v.second.data();
            }
            else if(strKey == std::string("dbName")) {
                m_xmlCfg.mysqlInfo.user = v.second.data();
            }
            else if(strKey == std::string("password")) {
                m_xmlCfg.mysqlInfo.pwd = v.second.data();
            }
            else {
                std::string info = std::string("read_config_file()  unknown mysql config") + "\n"; 
                App::getInstance().write_log_to_file(info);
            }

            std::cout << v.first << ":" << v.second.data() << std::endl;

        }

        bpt::ptree redisInfo = root.get_child("Nethings.redis");
        for(auto& v : redisInfo) {
            strKey = v.first;
            if (strKey == std::string("ip")) {
                m_xmlCfg.redisInfo.ip = v.second.data();
            }
            else if(strKey == std::string("port")) {
                m_xmlCfg.redisInfo.port = v.second.data();
            }
            else {
                
            }

            std::cout << v.first << ":" << v.second.data() << std::endl;

        }

    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
        std::string err = std::string("read_config_file() ") + e.what() + "\n"; 
        App::getInstance().write_log_to_file(err);
        return false;
    }

    //std::cout << "readConfigFile() ------- " << std::endl;
    return true;
}

bool Cmdline::initDefaultCmd() {
    //std::cout << "initDefaultCmd() +++++++ " << std::endl;

    CmdMap diffMap;
     diffMap = CompareMap(cmdByUsers, cmdDfault, diffMap);

    //std::cout << "diffMap  size: " << diffMap.size() <<  std::endl;

    std::string key;
    CmdMap::const_iterator it = diffMap.begin();
    while(it != diffMap.end()) {
        key = it->first;

        if(key == "config") {
            const std::string cfgfileDefault = boost::any_cast<std::string>(it->second);
            if(!initConfigFile(cfgfileDefault)) {
                return false;
            }
        }
        ++it;
    }

    //std::cout << "initDefaultCmd() ------- " << std::endl;
    return true;
}

const CmdMap& Cmdline::CompareMap(const CmdMap& mapSrc, const CmdMap& mapDst, CmdMap& diffMap)
{

    //std::cout << "mapSrc size: " << mapSrc.size() << std::endl;
    //std::cout << "mapDst size: " << mapDst.size() << std::endl;
	if (mapSrc.size() == 0)
	{
		return mapDst;
	}

    CmdMap::const_iterator itDst;
	CmdMap::const_iterator itSrc = mapSrc.begin();

	while (itSrc != mapSrc.end())
	{
		itDst = mapDst.find(itSrc->first);
		if (itDst == mapDst.end())
		{
			diffMap.insert(make_pair(itSrc->first, itSrc->second));	
		}

		++itSrc;
	}

	return diffMap;
}


bool Cmdline::initConfigFile(const std::string& cfg){

    //std::cout << "initConfigFile() +++++++ " << std::endl;
    try{
        App& app = App::getInstance();
        
        bfs::path cfg_path(cfg);
        boost::system::error_code err_code;

        auto file_status = bfs::status(cfg_path, err_code);
        
        if(err_code.value() != 0 || !bfs::exists(file_status)) {
            createConfigFile(cfg);
        }

        if(!bfs::is_directory(file_status)) {

            if(!readConfigFile(cfg)){
                return false;
            }
        }
        else {
            std::string err = std::string("Error code: ") + std::to_string(ERROR_CONFIG_FILE_EXIST);
            app.write_log_to_file(err);
            return false;
        }
    }catch(...){
        std::string err = "init_config_file() failed!\n";
        App::getInstance().write_log_to_file(err);
    }

    //std::cout << "initConfigFile() ------- " << std::endl;

    return true;
}


bool Cmdline::createConfigFile(std::string cfg) {

     //std::cout << "createConfigFile() +++++++ " << std::endl;
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
        App::getInstance().write_log_to_file(err);

        return false;
    }
    


    m_xmlCfg.mysqlInfo.ip = "192.168.2.65";
    m_xmlCfg.mysqlInfo.port = "3306";
    m_xmlCfg.mysqlInfo.name = "shop";
    m_xmlCfg.mysqlInfo.user = "net";
    m_xmlCfg.mysqlInfo.pwd = "123456";

    m_xmlCfg.redisInfo.ip = "192.168.2.65";
    m_xmlCfg.redisInfo.port = "6739";

    //std::cout << "createConfigFile() ------- " << std::endl;
    return true;
}
