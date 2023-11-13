/*
* 负责人：老菌
*/
#include "stdafx.h"
#include "ExportCustomerDAO.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->create_user_id) { \
	sql << " AND c.create_user_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->create_user_id.getValue(0)); \
} \
if (query->owner_user_id) { \
	sql << " AND c.owner_user_id=? "; \
	SQLPARAMS_PUSH(params, "i", int, query->owner_user_id.getValue(0)); \
}


list<CustomerDO> ExportCustomerDAO::selectAll(const ExportCustomerQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT DISTINCT c.customer_id, c.name, c.customer_no, c.create_user_id, \
				c.owner_user_id, c.create_time, c.next_time, c.conn_time, \
				c.conn_body, c.linkman, c.source, c.grade, c.industry, \
				c.mobile, c.tel, c.address, c.intro, c.needs, u1.name, u2.name \
			FROM cst_customer c \
			LEFT JOIN fly_sys_user u1 ON c.create_user_id = u1.id \
			LEFT JOIN fly_sys_user u2 ON c.owner_user_id = u2.id";
	SAMPLE_TERAM_PARSE(query, sql);

	/*if (query->customer_id_list) {
		auto it = query->customer_id_list.getPtr()->begin();
		while (*it) {
			sql << " OR c.owner_user_id=?";
			SQLPARAMS_PUSH(params, "i", int, it->getValue(0));
			it++;
		}
	}*/
	if (query->customer_id_list) {
		for (auto id : *(query->customer_id_list.getPtr())) {
			sql << " OR c.customer_id=?";
			SQLPARAMS_PUSH(params, "i", int, id);
		}
	}
	//sql << "ORDER BY c.customer_id";
	ExportCustomerMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CustomerDO, ExportCustomerMapper>(sqlStr, mapper, params);
}

