#ifndef DBCONN_H
#define DBCONN_H

#include "Common.h"

namespace mysql {

const int  MAX_ESCAPE_STRING_LEN =  10240;

class ResultSet;
class DBPool;

class DBConn {
public:
	DBConn(DBPool *);
	virtual ~DBConn();

	int init();
	bool executeCreate(const char*sql_query);
	bool executeDrop(const char*sql_query);

	bool executeUpdate(const char*sql_query,bool care_affected_rows = true);

	uint  getInsertId();

	bool startTransaction();
	bool commit();
	bool rollback();
	const char *getPoolName();

	MYSQL* getMysql() { return m_mysql; }
	ResultSet* executeQuery(const char*sql_query);
private:

	DBPool *m_pDbPool;
	MYSQL* m_mysql;
	char m_escape_string[MAX_ESCAPE_STRING_LEN + 1];
};

};

#endif

