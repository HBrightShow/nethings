
#ifndef DBPOOL_H
#define DBPOOL_H
#include "Common.h"
#include "ThreadNotify.h"


namespace mysql {

class DBConn;
class DBPool {

public:

	DBPool();
	DBPool(const char* name, const char* ip, unsigned short port, 
	const char* userName, const char*passwd, const char*dbName, int maxConn);

	int init();
	DBConn *getDBConn();
	void relConn(DBConn*);

	~DBPool();

	const char* getPoolName() { return m_poolName.c_str(); }
	const char* getDBServerHostIp() { return m_dbServerIp.c_str(); }
	unsigned short getDBServerPort() { return m_dbServerPort; }

	const char* getUserName() { return m_userName.c_str(); }
	const char*getUSerPasswd() { return m_passwd.c_str(); }
	const char*getDBName() { return m_dbName.c_str(); }

	int getCurConnCnt() { return m_dbCurConnCnt; }
	int getMaxConnCnt() { return m_dbMaxConnCnt; }

private:
	
	std::string	m_poolName;
	std::string  m_dbServerIp;
	unsigned short m_dbServerPort;
	std::string m_userName;
	std::string m_passwd;
	std::string m_dbName;

	int m_dbCurConnCnt;
	int m_dbMaxConnCnt;

	std::list<DBConn*> m_freeList;
	CThreadNotify m_freeNotify;
};
};

#endif
