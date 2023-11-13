/*
* 负责人：老菌
*/
#include "stdafx.h"
#include <sstream>
#include "GetContactFieldExtDAO.h"
#include "GetContactFieldExtDAO.h"



uint64_t GetContactFieldExtDAO::selectVisibleByName(string field_name)
{
	stringstream sql;

	sql << "SELECT visible FROM cst_field_ext";
	SqlParams params;
	sql << " WHERE field_name=?";
	SQLPARAMS_PUSH(params, "s", string, field_name);

	GetFieldExtMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

