#include "stdafx.h"
#include "QueryCapitalRecordDAO.h"
#include <iostream>
#include <string>
#include <sstream>
#include "dao/fincapitalrecord/querycapitalrecord/QueryCapitalRecordMapper.h"

#define FINCAPREC_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->record_id) { \
	sql << " AND `record_id`= ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->record_id.getValue(0)); \
} \
if (query->type) { \
	sql << " AND `type`= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->type.getValue("")); \
} \
if (query->create_user) { \
	sql << " AND `create_user` = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->create_user.getValue("")); \
} \
if (query->bank_id) { \
	sql << " AND `bank_id` = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->bank_id.getValue(0)); \
} \
if (query->bank_card) { \
	sql << " AND fbc.bank_card LIKE ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->bank_card.getValue("") + "%"); \
} \
if (query->money) { \
	sql << " AND `money` = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->money.getValue(0)); \
} \
if (query->intro) { \
	sql << " AND intro LIKE ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->intro.getValue("") + "%"); \
} \
if(query->latest_happen_date){\
	sql<<" AND TIMESTAMPDIFF(DAY,fcr.happen_date,NOW())<=?";\
	SQLPARAMS_PUSH(params,"i",int,query->latest_happen_date.getValue(0));\
}\
if(query->latest_create_time){\
	sql<<" AND TIMESTAMPDIFF(DAY,fcr.create_time,NOW())<=?";\
	SQLPARAMS_PUSH(params,"i",int,query->latest_create_time.getValue(0));\
}\


uint64_t QueryCapitalRecordDAO::count(const CapitalRecordPageQuery::Wrapper& query)
{
	stringstream sql;
	// 需要去银行账户表中查看有没有这个银行账号
	sql << "SELECT COUNT(*) FROM fin_capital_record As fcr "
		"LEFT JOIN fin_bank_account AS fba ON fcr.bank_id=fba.bank_id "
		"LEFT JOIN fin_flow_record AS ffr ON fcr.type_id=ffr.bus_id AND fcr.create_time=ffr.create_time "
	    "LEFT JOIN fly_sys_user fsu ON fcr.create_user_id=fsu.id ";
	FINCAPREC_TERAM_PARSE(query, sql);
	std::string sqlStr = sql.str();
	std::cout <<"Query_sql:" << sqlStr << std::endl;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<CapitalRecordDO> QueryCapitalRecordDAO::selectWithPage(const CapitalRecordPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT fcr.record_id,ffr.bus_type,fsu.name,fcr.bank_id,fba.name,fba.card,fcr.money,fcr.intro,fcr.create_time,fcr.happen_date "
		"FROM fin_capital_record fcr "
		"LEFT JOIN fin_flow_record ffr ON fcr.type_id=ffr.bus_id AND fcr.create_time=ffr.create_time "
		"LEFT JOIN fin_bank_account fba ON fcr.bank_id=fba.bank_id "
		"LEFT JOIN fly_sys_user fsu ON fcr.create_user_id=fsu.id ";
	FINCAPREC_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	QueryCapitalRecordMapper mapper;
	std::string sqlStr = sql.str();
	std:cout << "selectWithPage_sql:" << sqlStr << std::endl;
	return sqlSession->executeQuery<CapitalRecordDO, QueryCapitalRecordMapper>(sqlStr, mapper, params);
}

