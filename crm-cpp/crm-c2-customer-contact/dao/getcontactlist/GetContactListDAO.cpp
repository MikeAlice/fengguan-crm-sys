/*
* 负责人: 老菌
*/
#include "stdafx.h"
#include "GetContactListDAO.h"
#include "GetContactListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->customer_name) { \
	sql << " AND c.name LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", string, query->customer_name.getValue("")); \
} \
if (query->address) { \
	sql << " AND l.address LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", string, query->address.getValue("")); \
} \
if (query->key){	\
	sql << " AND ( l.name LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->key.getValue("")); \
	sql << " OR l.tel LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->key.getValue("")); \
	sql << " OR l.mobile LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->key.getValue("")); \
	sql << " OR l.qicq LIKE CONCAT('%',?,'%') )"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->key.getValue("")); \
}


uint64_t GetContactListDAO::count(const ListContactQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM cst_linkman l LEFT JOIN cst_customer c on l.customer_id = c.customer_id";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ListContactDO> GetContactListDAO::selectWithPage(const ListContactQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT l.linkman_id, c.name, l.name, l.gender, l.postion, l.tel, l.mobile, l.qicq \
			FROM cst_linkman l LEFT JOIN cst_customer c on l.customer_id = c.customer_id";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GetContactListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ListContactDO, GetContactListMapper>(sqlStr, mapper, params);
}
