#include "stdafx.h"
#include "BillingRecordsDAO.h"
#include <sstream>
#include"dao/BillingRecords/BillingRecordsMapper.h"

int BillingRecordsDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `fin_invoice_pay` WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}


//通过id导出数据
list<BillingRecordsDO> BillingRecordsDAO::selectbyID(const oatpp::List<oatpp::UInt64>& dto)
{
	//list<BillingRecordsDO> resultdata;

	string sql = "SELECT contract_id,customer_name,money,invoice_no,pay_date,stages,name,intro FROM `fin_invoice_pay` WHERE `record_id` IN (";

	BillingRecordsMapper mapper;
	SqlParams params;
	bool isFirst = true;
	for (auto i = dto->begin(); i != dto->end(); i++)
	{
		auto istart = i->getValue(0);
		if (isFirst) {
			sql += "?";
			isFirst = false;
		}
		else sql += ",?";
		params.push_back(SqlParam("ull", std::make_shared<uint64_t>(i->getValue(0))));
	}
	sql += ")";
	auto result = sqlSession->executeQuery<BillingRecordsDO, BillingRecordsMapper>(sql, mapper, params);
	return result;
}
