#ifndef PREPARESTATEMENT_H
#define PREPARESTATEMENT_H

#include  "Common.h"

namespace mysql {

class PrepareStatement {

public:
	PrepareStatement();
	virtual ~PrepareStatement();


	bool Init(MYSQL* mysql, std::string& sql);

	void setParam(uint32_t index,int &value);
	void setParam(uint32_t index, uint8_t &value);
	void setParam(uint32_t index, uint32_t& value);
	void setParam(uint32_t index, std::string& value);
	void setParam(uint32_t index, const std::string & value);

	bool executeUpdate();
	uint32_t getInsertId();
private:
	MYSQL_STMT*		m_stmt;
	MYSQL_BIND *	m_paramBind;
	uint32_t		m_paramCnt;
};

};
#endif
