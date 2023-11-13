#include "stdafx.h"
#include "updatePayPlanDAO.h"
#include "updatePayPlanMapper.h"
#include <sstream>

// 修改回款计划
int updatePayPlanDAO::update(const updatePayPlanDO& uObj)
{
	// 修改fin_rece_plan表的数据并且显示sale_contract中的金额字段
	string sql = "UPDATE `fin_rece_plan` SET `plan_date`=?, `stages`=?, `money`=?, `customer_name`=?, `contract_name`=?, `contract_id`=?, `customer_id`=? WHERE `plan_id`=?";
	return sqlSession->executeUpdate(sql, "%s%i%d%s%s%i%i%i",
		uObj.getPlanBackDate(), uObj.getPeriod(), uObj.getPlanBackAmount(), uObj.getClientName(), uObj.getSaleContract(), uObj.getSaleContractId(), uObj.getClientNameId(), uObj.getId());
}

// 确认回款
int updateConfirmPlanDAO::update(const updateConfirmPlanDO& uObj)
{
	// 修改fin_rece_plan表中的一些字段值
	string sql = "UPDATE `fin_rece_plan` SET `plan_date`=?, `ifpay`='YES', `customer_name`=?, `contract_name`=?, `contract_id`=?, `customer_id`=? WHERE `plan_id`=? ";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%i%i",
		uObj.getPlanBackDate(), uObj.getClientName(), uObj.getSaleContract(), uObj.getSaleContractId(), uObj.getClientNameId(), uObj.getId());
}
