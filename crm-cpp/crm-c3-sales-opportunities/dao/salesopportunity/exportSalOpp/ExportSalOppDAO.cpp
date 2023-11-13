#include "stdafx.h"
#include "ExportSalOppDAO.h"
//#include "domain/do/cstFieldExt/CstFieldExtDO.h"
#include "dao/mapper/CstFieldExtMapper.h"
#include "dao/mapper/SalesOpportunityMapper.h"
#include "dao/mapper/ToStringMapper.h"

#define EXPORT_TERM_PARSE(_QUERY_, _SQL_) \
SqlParams params; \
_SQL_ << " WHERE 1=1"; \
if (_QUERY_->chance_id) {	\
	_SQL_ << " AND a.chance_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, _QUERY_->chance_id.getValue(1)); \
} 

std::list<Cst_chanceDO> ExportSalOppDAO::selectAll(const OpportunityQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT a.chance_id, a.customer_id, a.linkman_id, a.find_date, a.bill_date, a.salestage, a.money, a.success_rate, a.userID, a.name, a.intro, a.status,  a.create_user_id, a.create_time";
	sql << " FROM cst_chance as a";
	EXPORT_TERM_PARSE(query, sql);
	std::string sql_str = sql.str();
	SalesOpportunityMapper mapper;
	return sqlSession->executeQuery<Cst_chanceDO, SalesOpportunityMapper>(sql_str, mapper, params);
}

std::list<std::string> ExportSalOppDAO::selectField(const std::string& table)
{
	stringstream sql;
	sql << "DESC " << table;
	std::string sql_str = sql.str();
	ToStringMapper mapper;
	return sqlSession->executeQuery<std::string, ToStringMapper>(sql_str, mapper);
}