#include "stdafx.h"
#include "ContractamountDAO.h"
//#include "ContractamountMapper.h"
#include "domain/query/contractamount/ContractamountQuery.h"
#include "domain/do/contractamount/ContractamountDO.h"
#include <sstream>

#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->contract_id) { \
	sql << " AND contract_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->contract_id.getValue(0)); \
}

//查询总金额
uint64_t ContractamountDAO::getTotal(const ContractamountQuery::Wrapper & query) {
	stringstream sql;
	if (query->type == "pay")
		sql << "SELECT sum(money) FROM fin_pay_plan";
	else if (query->type == "rece")
		sql << "SELECT sum(money) FROM fin_rece_plan";
	else
		return 0;
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " group by 'contract_id'";
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//查询去零金额
uint64_t ContractamountDAO::getZero(const ContractamountQuery::Wrapper& query) {
	stringstream sql;
	if (query->type == "pay")
		sql << "SELECT sum(zero_money) FROM fin_pay_record";
	else if (query->type == "rece")
		sql << "SELECT sum(zero_money) FROM fin_rece_record";
	else
		return 0;
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " group by 'contract_id'";
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//查询已付金额
uint64_t ContractamountDAO::getPaid(const ContractamountQuery::Wrapper& query) {
	stringstream sql;
	if (query->type == "pay")
		sql << "SELECT sum(money) FROM fin_pay_record";
	else if (query->type == "rece") 
		sql << "SELECT sum(money) FROM fin_rece_record";
	else
		return 0;
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " group by 'contract_id'";
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//查询已收发票金额
uint64_t ContractamountDAO::getInvoice(const ContractamountQuery::Wrapper& query) {
	stringstream sql;
	if (query->type == "pay")
		sql << "SELECT sum(money) FROM fin_invoice_pay";
	else if (query->type == "rece")
		sql << "SELECT sum(money) FROM fin_invoice_rece";
	else
		return 0;
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " group by 'contract_id'";
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
