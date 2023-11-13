#include "stdafx.h"
#include "QueryInvoiceReceiveDAO.h"
#include "FinInvoiceReceiveMapper.h"
#include <sstream>

//定义条件解析宏
#define FININVREC_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->rece_date) { \
	sql << " AND fir.rece_date= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->rece_date.getValue("")); \
} \
if (query->create_time) { \
	sql << " AND fir.create_time = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->create_time.getValue("")); \
} \
if (query->contract_name) { \
	sql << " AND fir.contract_name = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contract_name.getValue("")); \
} \
if (query->supplier_name) { \
	sql << " AND fir.supplier_name = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->supplier_name.getValue("")); \
} \
if (query->money) { \
	sql << " AND fir.money = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->money.getValue(0)); \
} 


// 统计数据条数
uint64_t QueryInvoiceReceiveDAO::count(const QueryInvoiceReceiveQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM fin_invoice_rece AS fir ";
	FININVREC_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
// 分页查询数据
list<FinInvoiceReceiveDO> QueryInvoiceReceiveDAO::selectWithPage(const QueryInvoiceReceiveQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT fir.record_id, fir.supplier_name, fir.contract_name, fir.name, fir.invoice_no, fir.money, fir.rece_date, fir.stages, fsu.name AS create_user, fir.intro "
		   "FROM fin_invoice_rece AS fir "
		   "LEFT JOIN fly_sys_user as fsu ON fir.create_user_id=fsu.id ";
	FININVREC_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	FinInvoiceReceiveMapper mapper;
	string sqlStr = sql.str();
	//std::cout << std::endl << std::endl << sqlStr << std::endl<< std::endl;
	return sqlSession->executeQuery<FinInvoiceReceiveDO, FinInvoiceReceiveMapper>(sqlStr, mapper, params);
}