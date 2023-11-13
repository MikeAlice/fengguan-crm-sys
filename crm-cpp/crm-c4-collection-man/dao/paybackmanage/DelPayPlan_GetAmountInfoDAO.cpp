#include "stdafx.h"
#include "DelPayPlan_GetAmountInfoDAO.h"
#include "GetAmountInfoMapper.h"
#include <sstream>


//定义条件解析宏，减少重复代码
//#define SAMPLE_TERAM_PARSE(query, sql) \
//SqlParams params; \
//sql<<" WHERE 1=1"; \
//if (query->name) { \
//	sql << " AND `name`=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
//} \
//if (query->sex) { \
//	sql << " AND sex=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
//} \
//if (query->age) { \
//	sql << " AND age=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
//}

uint64_t DelPayPlan_GetAmountInfoDAO::count(const uint64_t & amountid)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `fin_rece_plan` WHERE `contract_id` = ? ";
	//SAMPLE_TERAM_PARSE(amountid, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, "%ull", amountid);
}

PaybackInfoDO DelPayPlan_GetAmountInfoDAO::selectOne(const uint64_t& amountid)
{
	stringstream sql;
	sql << "SELECT money,zero_money,back_money,invoice_money FROM sal_contract WHERE contract_id = ?";
	GetAmountInfoMapper mapper;
	string sqlStr = sql.str();
	return *(sqlSession->executeQuery<PaybackInfoDO, GetAmountInfoMapper>(sqlStr, mapper,"%ull", amountid)).begin();
}

int DelPayPlan_GetAmountInfoDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `fin_rece_plan` WHERE `plan_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}
