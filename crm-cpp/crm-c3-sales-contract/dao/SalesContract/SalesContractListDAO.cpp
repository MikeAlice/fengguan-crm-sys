#include "stdafx.h"
#include "SalesContractListDAO.h"
#include "dao/mapper/SalesContractMapper.h"

#define FINCAPREC_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->start_date) { \
	sql << " AND `start_date` >= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->start_date.getValue("")); \
} \
if (query->end_date) { \
	sql << " AND `end_date` <= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->end_date.getValue("")); \
} \


uint64_t querySalesContractListDAO::count(const SalesContractPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sal_contract";
	FINCAPREC_TERAM_PARSE(query, sql);
	std::string sqlStr = sql.str();
	std::cout << "Query_sql:" << sqlStr << std::endl;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<sal_contractDO> querySalesContractListDAO::selectWithPage(const SalesContractPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT a.title, a.customer_id, a.money, a.back_money, a.back_status, "
		"a.invoice_money, a.invoice_status, a.start_date, a.end_date, a.status, "
		"a.deliver_status, a.create_time, b.name, c.name, a.zero_money, a.owe_money, "
		"a.contract_id, a.contract_no "
		"FROM sal_contract a, cst_customer b, cst_linkman c ";
	FINCAPREC_TERAM_PARSE(query, sql);
	sql << " AND a.linkman_id=c.linkman_id AND a.customer_id=b.customer_id";
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	SalesContractMapper mapper;
	std::string sqlStr = sql.str();
std:cout << "selectWithPage_sql:" << sqlStr << std::endl;
	return sqlSession->executeQuery<sal_contractDO, SalesContractMapper>(sqlStr, mapper, params);
}

