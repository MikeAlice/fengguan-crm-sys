#include "stdafx.h"
#include <sstream>
#include "ExportCapitalRecordDAO.h"
#include "ExportCapitalRecordMapper.h"
#include "domain/dto/fincapitalrecord/ExportCapitalRecordDTO.h"

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
if (query->bank_name) { \
	sql << " AND `fin_bank_account.name` = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->bank_name.getValue("")); \
} \
if (query->bank_card) { \
	sql << " AND `fin_bank_account.card` = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->bank_card.getValue("")); \
} \
if (query->money) { \
	sql << " AND `money` = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->money.getValue(0)); \
} \
if (query->intro) { \
	sql << " AND intro LIKE ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->intro.getValue("") + "%"); \
} \
if (query->create_time) { \
	sql << " AND `create_time` >= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->create_time.getValue("")); \
} \
if (query->happen_date) { \
	sql << " AND `happen_date` = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->happen_date.getValue("")); \
} \

namespace sqlHelpers {
	/*
	* 描述：添加IN后的()
	* 示例：在"SELECT xxx FROM xxx WHERE xxx IN "的后面
	*		添加(1,2,3,4)
	* 参数：sql语句、dto对象
	* 注意：record_id！
	*/
	template<typename T>
	void insertIdList(stringstream& sql, T& dto)
	{
		sql << "(";
		for (auto i = dto->begin(); i != dto->end(); i++)
		{
			if (i != dto->begin())	sql << ",";
			sql << (*i)->record_id.getValue({});
		}
		sql << ")";
	}
}

list<ExportCapitalRecordDO> ExportCapitalRecordDAO::selectAll(const ExportCapitalRecordQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM fin_capital_record WHERE ";
	FINCAPREC_TERAM_PARSE(query, sql);
	ExportCapitalRecordMapper mapper;
	string sqlStr = sql.str();
	//std::cout << "Export_sql:" << sqlStr << std::endl;
	return sqlSession->executeQuery<ExportCapitalRecordDO, ExportCapitalRecordMapper>(sqlStr, mapper, params);
}

std::list<ExportCapitalRecordDO> ExportCapitalRecordDAO::selectWithIdList(const oatpp::List<ExportCapitalRecordDTO::Wrapper>& dto)
{
	stringstream sql;
	sql << "SELECT fcr.record_id,ffr.bus_type,fcr.money,fba.name,fba.card,fcr.happen_date,fsu.name,fcr.create_time,fcr.intro "
		"FROM fin_capital_record fcr "
		"LEFT JOIN fin_flow_record ffr ON fcr.type_id=ffr.bus_id AND fcr.create_time=ffr.create_time "
		"LEFT JOIN fin_bank_account fba ON fcr.bank_id=fba.bank_id "
		"LEFT JOIN fly_sys_user fsu ON fcr.create_user_id=fsu.id "
		"WHERE record_id IN ";
	sqlHelpers::insertIdList(sql, dto);
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	ExportCapitalRecordMapper mapper;
	return sqlSession->executeQuery<ExportCapitalRecordDO, ExportCapitalRecordMapper>(sqlStr, mapper);
}
