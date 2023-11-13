#include "stdafx.h"
#include "GetSalesOppoDAO.h"
#include "GetSalesOppoMapper.h"

#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND name LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->customer_id) { \
	sql << " AND customer_id=?"; \
	SQLPARAMS_PUSH(params, "i", std::uint32_t, query->customer_id.getValue("")); \
}

std::list<Cst_chanceDO> SalesOppoDAO::selectByName(const GetSalesOppoQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT name,chance_id FROM cst_chance";
	//SAMPLE_TERAM_PARSE(query, sql);
	SqlParams params;
	sql << " WHERE 1=1";
	if (query->customer_id) {
		sql << " AND customer_id=?";
		SQLPARAMS_PUSH(params, "i", int, query->customer_id.getValue(0));
	}
	if (query->name) {
			sql << " AND name LIKE CONCAT('%',?,'%')"; 
			SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); 
	} 

	GetSalesOppoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<Cst_chanceDO, GetSalesOppoMapper>(sqlStr, mapper, params);
}

//std::list<Cst_chanceDO> GetSalesOppoDAO::selectByName(const GetSalesOppoQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT name,chance_id FROM cst_chance";
//	GetSalesOppoMapper mapper;
//	string sqlStr = sql.str();
//	return sqlSession->executeQuery<Cst_chanceDO, GetSalesOppoMapper>(sqlStr, mapper);
//}

//std::list<Cst_chanceDO> SalesOppoDAO::selectByCustomer_id(const uint32_t& query)
//{
//	stringstream sql;
//	sql << "SELECT name, chance_id FROM cst_chance";
//	SAMPLE_TERAM_PARSE(query, sql);
//	GetSalesOppoMapper mapper;
//	string sqlStr = sql.str();
//	return sqlSession->executeQuery<Cst_chanceDO, GetSalesOppoMapper>(sqlStr, mapper, params);
//}

//list<Cst_chanceDO> SalesOppoDAO::selectByCustomer_id(const uint32_t & customer_id)
//{
//	stringstream sql;
//	sql << "SELECT chance_id, name FROM cst_chance WHERE `customer_id`=?";
//	GetSalesOppoMapper mapper;
//	string sqlStr = sql.str();
//	return sqlSession->executeQuery<Cst_chanceDO, GetSalesOppoMapper>(sqlStr, mapper);
//}
