#include "ResultSet.h"
#include "DBPool.h"

using namespace mysql;

#define log_err printf

ResultSet::ResultSet(MYSQL_RES* res)
{
	m_res = res;

	int num_fields = mysql_num_fields(m_res);
	MYSQL_FIELD *fileds = mysql_fetch_fields(m_res);
	int i;
	for ( i =0;i< num_fields;i++)
	{
		m_keyMap.insert(make_pair(fileds[i].name, i));
	}
}

ResultSet::~ResultSet()
{
	if (m_res)
	{
		mysql_free_result(m_res);
		m_res = NULL;
	}
}

bool ResultSet::next()
{
	m_row = mysql_fetch_row(m_res);
	if (m_row)
	{
		return true;
	}
	return false;
}

int ResultSet::getInt(const char *key)
{
	int idx = getIndex(key);
	if (idx != -1)
	{
		return atoi(m_row[idx]);
	}
	return -1;
}

char * ResultSet::getString(const char* key)
{
	int idx = getIndex(key);
	if (idx != -1)
	{
		return m_row[idx];
	}
	return NULL;
}

int ResultSet::getIndex(const char* key)
{
	map<string, int>::iterator it = m_keyMap.find(key);
	if (it != m_keyMap.end())
	{
		return it->second;
	}
	return -1;
}

void ResultSet::printMap() {

	/*
	for(auto &v : m_keyMap) {
		//std::cout << v.first << " : " << v.second << std::endl;
		std::string filed = v.first;
		std::cout << "filed: " << filed << std::endl;
		std::cout << getIndex(filed.c_str()) << std::endl;
	}
	*/

	uint64_t filed_size = m_keyMap.size();
	while(next()) {

		/*
		for(int i = 0; i < filed_size; ++i) {
			std::cout << m_row[i] << std::endl;
		}*/

		
		std::cout << getString("address") << std::endl;
	}

}

