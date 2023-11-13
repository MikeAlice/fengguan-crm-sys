#include "stdafx.h"
#include "GetCustomerNameDAO.h"
#include "GetCustomerNameMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \

std::list<GetCustomerNameDO> GetCustomerNameDAO::selectByName(const GetCustomerNameQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT name,customer_id FROM cst_customer";
	SAMPLE_TERAM_PARSE(query, sql);
	GetCustomerNameMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GetCustomerNameDO, GetCustomerNameMapper>(sqlStr, mapper, params);
}
