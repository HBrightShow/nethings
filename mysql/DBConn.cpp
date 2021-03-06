#include "DBConn.h"
#include "ResultSet.h"
#include "DBPool.h"

using namespace mysql;

DBConn::DBConn(DBPool * pool)
{
	m_pDbPool = pool;
	m_mysql = NULL;
}

DBConn::~DBConn()
{
	if (m_mysql)
	{
		mysql_close(m_mysql);
	}
}

int DBConn::init()
{
	m_mysql = mysql_init(NULL);
	if (NULL == m_mysql)
	{
		return -1;
	}

	bool reconnect = true;
	mysql_options(m_mysql,MYSQL_OPT_RECONNECT,&reconnect);
	mysql_options(m_mysql,MYSQL_SET_CHARSET_NAME,"utf8mb4");

	

	if (!mysql_real_connect(m_mysql,m_pDbPool->getDBServerHostIp(),m_pDbPool->getUserName(),m_pDbPool->getUSerPasswd(),
		m_pDbPool->getDBName(),m_pDbPool->getDBServerPort(),NULL,0))
	{
		cout << "connect error " << mysql_error(m_mysql) << endl;
		return -1;
	}
	return 0;
}

bool DBConn::executeCreate(const char*sql_query)
{
	mysql_ping(m_mysql);
	if (mysql_real_query(m_mysql,sql_query,strlen(sql_query)))
	{
		cout << "error " << mysql_error(m_mysql) << endl;
		return false;
	}
	return true;
}

bool DBConn::executeDrop(const char*sql_query)
{

	mysql_ping(m_mysql);
	if (mysql_real_query(m_mysql, sql_query, strlen(sql_query)))
	{
		cout << "error " << mysql_error(m_mysql) << endl;
		return false;
	}
	return true;
}

bool DBConn::executeUpdate(const char*sql_query, bool care_affected_rows /*= true*/)
{
	mysql_ping(m_mysql);
	if (mysql_real_query(m_mysql, sql_query, strlen(sql_query)))
	{
		cout << "error " << mysql_error(m_mysql) << endl;
		return false;
	}

	if (mysql_affected_rows(m_mysql) > 0)
	{
		return 0;
	}


	if (care_affected_rows)
	{
		cout << " real_query error " << mysql_error(m_mysql) << endl;
		return false;
	}

	return true;
}

unsigned int DBConn::getInsertId()
{
	return (uint32_t)mysql_insert_id(m_mysql);
}

bool DBConn::startTransaction()
{
	mysql_ping(m_mysql);
	if (mysql_real_query(m_mysql, "start transaction\n", 17)) {
		cout << " error" << mysql_error(m_mysql) << endl;
		return false;
	}
	return true;
}

bool DBConn::commit()
{

	mysql_ping(m_mysql);
	if (mysql_real_query(m_mysql, "commit\n",6)) {
		cout << " error" << mysql_error(m_mysql) << endl;
		return false;
	}
	return true;
}

bool DBConn::rollback()
{
	mysql_ping(m_mysql);
	if (mysql_real_query(m_mysql, "rollback\n", 8)) {
		cout << " error" << mysql_error(m_mysql) << endl;
		return false;
	}
	return true;

}

const char * DBConn::getPoolName()
{
	return m_pDbPool->getPoolName();
}

ResultSet* DBConn::executeQuery(const char*sql_query)
{
	mysql_ping(m_mysql);

	if (mysql_real_query(m_mysql,sql_query,strlen(sql_query)))
	{
		return NULL;
	}
	MYSQL_RES *res = mysql_store_result(m_mysql);
	if (NULL == res)
	{
		if (mysql_field_count(m_mysql) >0)
		{
			cout << "error " << mysql_error(m_mysql) << endl;
		}
		return  NULL;
	}
	ResultSet *rset = new ResultSet(res);
	if (!rset)
	{
		return NULL;
	}
	return rset;
}

