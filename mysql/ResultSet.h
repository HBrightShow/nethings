
#ifndef  RESULT_H
#define  RESULT_H

#include<map>
#include "Common.h"

using namespace std;

namespace mysql {

class ResultSet {

public:
	ResultSet(MYSQL_RES*);
	virtual ~ResultSet();

	bool next();
	int getInt(const char *key);
	char *getString(const char* key);

private:
	int getIndex(const char* key);

	MYSQL_RES * m_res;
	MYSQL_ROW m_row;

	map<string, int> m_keyMap;
};
};

#endif 

