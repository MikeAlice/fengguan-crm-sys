#include "stdafx.h"
#include "ExportSalesDAO.h"
#include "domain/do/CstFieldExt/CstFieldExtDO.h"
#include "dao/mapper/CstFieldExtMapper.h"
#include "dao/mapper/ExportSalesMapper.h"
#include "dao/mapper/ToStringMapper.h"

std::list<ExportSalesDO> ExportSalesDAO::selectAll(const ExportSalesQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM sal_contract";
	std::string sql_str = sql.str();
	ExportSalesMapper mapper;
	return sqlSession->executeQuery<ExportSalesDO, ExportSalesMapper>(sql_str, mapper);
}

std::list<std::string> ExportSalesDAO::selectField(const std::string& table)
{
	stringstream sql;
	sql << "DESC " << table;
	std::string sql_str = sql.str();
	ToStringMapper mapper;
	return sqlSession->executeQuery<std::string, ToStringMapper>(sql_str, mapper);
}

/*

#define EXPORT_TERM_PARSE(_QUERY_, _SQL_) \
SqlParams params; \
_SQL_ << " WHERE 1=1"; \
if (_QUERY_->chance_id) {	\
	_SQL_ << " AND a.chance_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, _QUERY_->chance_id.getValue(1)); \
} 

std::list<Cst_chanceDO> ExportSalOppDAO::selectAll(const OpportunityQuery::Wrapper& query)
{
	// ²éÑ¯À©Õ¹×Ö¶Î
	stringstream get_ids;
	get_ids << "SELECT chance_id FROM cst_chance ";// WHERE `main_table`='cst_chance' AND `ext_table`='cst_chance'";
	std::string get_ids_str = get_ids.str();
	ToStringMapper ext_mapper;
	std::list<std::string> ids = sqlSession->executeQuery<std::string, ToStringMapper>(get_ids_str, ext_mapper);

	stringstream sql;
	sql << "SELECT a.chance_id, a.customer_id, a.linkman_id, a.find_date, a.bill_date, a.salestage, a.money, a.success_rate, a.userID, a.name, a.intro, a.status, a.intro, a.create_user_id, a.create_time";

	sql << " FROM cst_chance as a";
	EXPORT_TERM_PARSE(query, sql);
	std::string sql_str = sql.str();
	SalesOpportunityMapper mapper(ids);
	return sqlSession->executeQuery<Cst_chanceDO, SalesOpportunityMapper>(sql_str, mapper, params);
}

std::list<std::string> ExportSalOppDAO::selectField(const std::string& table)
{
	stringstream sql;
	sql << "DESC " << table;
	std::string sql_str = sql.str();
	ToStringMapper mapper;
	return sqlSession->executeQuery<std::string, ToStringMapper>(sql_str, mapper);
} */