#include "stdafx.h"
#include "GetCustomerDAO.h"
#include "GetCustomerMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->conn_time) { \
	if(query->conn_time=="Recent contact time for all") { \
		sql << " AND 1=1"; \
	} \
	else if(query->conn_time=="Last three days") { \
		sql << " AND `conn_time` > DATE_SUB(CURDATE(), INTERVAL 3 DAY)"; \
	}else if(query->conn_time=="Last week"){ \
		sql << " AND conn_time >  DATE_SUB(CURDATE(), INTERVAL 7 DAY)"; \
	}else if(query->conn_time=="Last half month") { \
		sql << " AND conn_time > DATE_SUB(CURDATE(), INTERVAL 15 DAY)"; \
	}else if(query->conn_time=="Last month") { \
		sql << " AND conn_time > DATE_SUB(CURDATE(), INTERVAL 30 DAY)"; \
	}else if(query->conn_time=="Last three months") { \
		sql << " AND conn_time > DATE_SUB(CURDATE(), INTERVAL 90 DAY)"; \
	}else if(query->conn_time=="Last six months") { \
		sql << " AND conn_time > DATE_SUB(CURDATE(), INTERVAL 180 DAY)"; \
	}else if(query->conn_time=="Last year") { \
		sql << " AND conn_time > DATE_SUB(CURDATE(), INTERVAL 365 DAY)"; \
	} \
} \
if (query->next_time) { \
	if(query->conn_time=="Next contact time all") { \
		sql << " AND 1=1"; \
	} \
	else if(query->next_time=="Last three days") { \
		sql << " AND `next_time` > DATE_SUB(CURDATE(), INTERVAL 3 DAY)"; \
	}else if(query->next_time=="Last week"){ \
		sql << " AND next_time > DATE_SUB(CURDATE(), INTERVAL 7 DAY)"; \
	}else if(query->next_time=="Last half month") { \
		sql << " AND next_time > DATE_SUB(CURDATE(), INTERVAL 15 DAY)"; \
	}else if(query->next_time=="Last month") { \
		sql << " AND next_time > DATE_SUB(CURDATE(), INTERVAL 30 DAY)"; \
	}else if(query->next_time=="Last three months") { \
		sql << " AND next_time > DATE_SUB(CURDATE(), INTERVAL 90 DAY)"; \
	}else if(query->next_time=="Last six months") { \
		sql << " AND next_time > DATE_SUB(CURDATE(), INTERVAL 180 DAY)"; \
	}else if(query->next_time=="Last year") { \
		sql << " AND next_time > DATE_SUB(CURDATE(), INTERVAL 365 DAY)"; \
	} \
} \
sql<<" AND ( 1=0 "; \
if (query->name) { \
	sql << " OR name LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->mobile) { \
	sql << " OR mobile LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->mobile.getValue("")); \
} \
if (query->tel) { \
	sql << " OR tel LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->tel.getValue("")); \
} \
if (query->address) { \
	sql << " OR address LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->address.getValue("")); \
} \
if(!query->name&&!query->mobile&&!query->tel&&!query->address) { \
	sql<<" OR 1=1"; \
} \
sql<<" )"; \

uint64_t GetCustomerDAO::count(const GetCustomerQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM cst_customer";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<GetCustomerDO> GetCustomerDAO::selectWithPage(const GetCustomerQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT name,customer_id,owner_user_id,conn_time,conn_body,next_time FROM cst_customer";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GetCustomerMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GetCustomerDO, GetCustomerMapper>(sqlStr, mapper, params);
}
