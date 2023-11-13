#include "stdafx.h"
#include "ExportPayRecordDAO.h"
#include "ExportPayRecordMapper.h"

list<ExportPayRecordDO> ExportPayRecordDAO::selectByID(const oatpp::List<ExportPayRecordDTO::Wrapper>& dto)
{
	//×é×°sqlÓï¾ä
	stringstream ssql;
	//ssql << "SELECT record_id, contract_name, supplier_name, pay_date, stages, money, zero_money, create_user_id, create_time, intro "
	//	"FROM fin_pay_record WHERE record_id IN (";
	ssql << "SELECT fpr.record_id, fpr.contract_name, fpr.supplier_name, fpr.pay_date, fpr.stages, fpr.money, fpr.zero_money, fsu.name as create_user, fpr.create_time, fpr.intro "
		    "FROM fin_pay_record as fpr "
			"LEFT JOIN fly_sys_user as fsu ON fpr.create_user_id=fsu.id "
		    "WHERE fpr.record_id IN (";
	for (auto i = dto->begin(); i != dto->end(); i++)
	{
		if (i != dto->begin())	ssql << ",";
		ssql << (*i)->record_id.getValue(1);
	}
	ssql << ");";
	string sql = ssql.str();
	//ssql >> sql;
	std::cout << sql << endl;
	//²éÑ¯
	ExportPayRecordMapper mapper;
	return sqlSession->executeQuery<ExportPayRecordDO, ExportPayRecordMapper>(sql, mapper);
}