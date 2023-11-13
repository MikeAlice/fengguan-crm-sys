#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "QueryBankAccountDAO.h"
#include "dao/fincapitalrecord/querybankaccount/QueryBankAccountMapper.h"

#define FINCAPREC_TERAM_PARSE(query, sql) \
SqlParams params; \

uint64_t QueryBankAccountDAO::count(const BankAccountPageQuery::Wrapper& query)
{
	stringstream sql;
	// 需要去银行账户表中查看有没有这个银行账号
	sql << "SELECT COUNT(*) FROM fin_bank_account";
	std::string sqlStr = sql.str();
	std::cout << "Query_sql:" << sqlStr << std::endl;
	return sqlSession->executeQueryNumerical(sqlStr);
}

std::list<BankAccountDO> QueryBankAccountDAO::selectWithPage(const BankAccountPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT fba.name,fba.card FROM fin_bank_account fba";
	FINCAPREC_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	QueryBankAccountMapper mapper;
	std::string sqlStr = sql.str();
	// std:cout << "selectWithPage_sql:" << sqlStr << std::endl;
	return sqlSession->executeQuery<BankAccountDO, QueryBankAccountMapper>(sqlStr, mapper, params);
}

