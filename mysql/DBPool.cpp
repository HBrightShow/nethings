

#include "DBPool.h"
#include "DBConn.h"


using namespace mysql;

DBPool::DBPool()
{

}

DBPool::DBPool(const char* name, const char* ip, unsigned short port, const char* userName, const char*passwd, const char*dbName, int maxConn)
{
	m_poolName = name;
	m_dbServerIp = ip;
	m_dbServerPort = port;
	m_userName = userName;
	m_passwd = passwd;
	m_dbName = dbName;

	m_dbCurConnCnt = 1;
	m_dbMaxConnCnt = maxConn;

	 m_freeList.clear();
	m_freeNotify.init();

}

int DBPool::init()
{
	int i = 0;
	for (i=0;i<1;i++)
	{
		DBConn *pDbConn = new DBConn(this);
		if (NULL == pDbConn)
		{
			continue;
		}
		int ret = pDbConn->init();
		if (ret)
		{
			delete pDbConn;
			return ret;
		}
		m_freeList.push_back(pDbConn);
	//	m_dbCurConnCnt ++;
	
	}
	return 0;
}

DBConn * DBPool::getDBConn()
{
	m_freeNotify.lock();
	while(m_freeList.empty())
	{
		if (m_dbCurConnCnt >= m_dbMaxConnCnt)
		{
			m_freeNotify.wait();
		}
		else
		{
			DBConn * conn = new DBConn(this);
			if (conn->init() != 0)
			{
				delete conn;
				m_freeNotify.unLock();
				return NULL;
			}

			m_freeList.push_back(conn);
			m_dbCurConnCnt++;
			printf("conn %d\n",m_dbCurConnCnt);
		}
	}

	DBConn *pconn = m_freeList.front();

	m_freeList.pop_front();
	
	m_freeNotify.unLock();
	return pconn;
}

void DBPool::relConn(DBConn* conn)
{
	m_freeNotify.lock();
	
	std::list<DBConn*>::iterator it = m_freeList.begin();
	for (;it != m_freeList.end();it ++)
	{
		if (*it == conn)
		{
			break;
		}
	}

	if (it == m_freeList.end())
	{
		m_freeList.push_back(conn);
	}
	
	m_freeNotify.signal();
	m_freeNotify.unLock();
}

DBPool::~DBPool()
{
	std::list<DBConn*>::iterator it = m_freeList.begin();
	
	for (; it != m_freeList.end(); it++) {

		DBConn* pconn = *it;
		delete pconn;
	}
	m_freeList.clear();
}
