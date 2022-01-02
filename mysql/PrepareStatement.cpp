#include "PrepareStatement.h"

using namespace mysql;

PrepareStatement::PrepareStatement()
{
	m_stmt = NULL;
	m_paramBind = NULL;
	m_paramCnt = 0;
}

PrepareStatement::~PrepareStatement()
{
	if (m_stmt)
	{
		mysql_stmt_close(m_stmt);
		m_stmt = NULL;
	}
	if (m_paramBind)
	{
		delete[] m_paramBind;
		m_paramBind = NULL;
	}
}

bool PrepareStatement::Init(MYSQL* mysql, std::string& sql)
{
	mysql_ping(mysql);
	m_stmt = mysql_stmt_init(mysql);
	if (!m_stmt)
	{
		return false;
	}

	if (mysql_stmt_prepare(m_stmt, sql.c_str(), sql.size()))
	{
		return false;
	}
	m_paramCnt = mysql_stmt_param_count(m_stmt);
	if (m_paramCnt>0)
	{
		m_paramBind = new MYSQL_BIND[m_paramCnt];
		if (!m_paramBind)
		{
			return false;
		}
		std::memset(m_paramBind,0,sizeof(MYSQL_BIND)*m_paramCnt);
	}
	return true;

}

void PrepareStatement::setParam(uint32_t index, int &value)
{
	if (index > m_paramCnt)
	{
		return;
	}
	m_paramBind[index].buffer_type = MYSQL_TYPE_LONG;
	m_paramBind[index].buffer = &value;
}

void PrepareStatement::setParam(uint32_t index, uint32_t& value)
{
	if (index > m_paramCnt)
	{
		return;
	}
	m_paramBind[index].buffer_type = MYSQL_TYPE_LONG;
	m_paramBind[index].buffer = &value;
}

void PrepareStatement::setParam(uint32_t index, std::string& value)
{
	if (index > m_paramCnt)
	{
		return;
	}
	m_paramBind[index].buffer_type = MYSQL_TYPE_STRING;
	m_paramBind[index].buffer = (char*)value.c_str();
	m_paramBind[index].buffer_length = value.size();

}

void PrepareStatement::setParam(uint32_t index, const std::string & value)
{
	if (index > m_paramCnt)
	{
		return;
	}
	m_paramBind[index].buffer_type = MYSQL_TYPE_STRING;
	m_paramBind[index].buffer = (char*)value.c_str();
	m_paramBind[index].buffer_length = value.size();
}

void PrepareStatement::setParam(uint32_t index, uint8_t &value)
{
	if (index > m_paramCnt)
	{
		return;
	}
	m_paramBind[index].buffer_type = MYSQL_TYPE_STRING;
	m_paramBind[index].buffer = (char*)(value);

}

bool PrepareStatement::executeUpdate()
{
	if (!m_stmt)
	{
		return false;
	}
	if (mysql_stmt_bind_param(m_stmt,m_paramBind))
	{
		std::cout << "stmt bind error" << mysql_stmt_errno(m_stmt) << std::endl;
		return false;
	}
	if (int i =mysql_stmt_execute(m_stmt))
	{
		std::cout << "stmt execute error :"<<i<<" " << mysql_stmt_errno(m_stmt) << std::endl;
		return false;
	}
	if (mysql_stmt_affected_rows(m_stmt) == 0)
	{
		std::cout << "stmt affected error" << mysql_stmt_errno(m_stmt) << std::endl;
		return false;
	}
	return true;
}

uint32_t PrepareStatement::getInsertId()
{
	return mysql_stmt_insert_id(m_stmt);
}

