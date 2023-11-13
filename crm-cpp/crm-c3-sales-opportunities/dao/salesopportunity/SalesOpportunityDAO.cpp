#include "stdafx.h"
#include "SalesOpportunityDAO.h"

int SalesOpportunityDAO::update(const SalesOpportunityDO& uObj)
{
    string sql = "UPDATE `cst_chance` SET `customer_id`=?, `linkman_id`=?, `find_date`=?, `bill_date`=?, `salestage`=?, `money`=?, `success_rate`=?, `userID`=?, `name`=?, `intro`=?, `status`=?, `create_user_id`=?, `create_time`=? WHERE `chance_id`=?";
	return sqlSession->executeUpdate(sql, "%ull%s%s%s%i%d%i%ull%s%s%i%ull%s%ull", uObj.getCustomerId(), uObj.getLinkmanId(), uObj.getFindDate(), uObj.getBillDate(), uObj.getSalestage(), uObj.getMoney(), uObj.getSuccessRate(), uObj.getUserId(), uObj.getName(), uObj.getIntro(), uObj.getStatus(), uObj.getCreateUserId(), uObj.getCreateTime(), uObj.getChanceId());
}

int SalesOpportunityDAO::deleteById(uint64_t id)
{
    string sql = "DELETE FROM `cst_chance` WHERE `chance_id`=?";
    return sqlSession->executeUpdate(sql, "%ull", id);
}

int SalesOpportunityDAO::insert(const SalesOpportunityDO& uObj)
{
	string sql = "INSERT INTO `cst_chance` (`customer_id`, `linkman_id`, `find_date`, `bill_date`, `salestage`, `money`, `success_rate`, `userID`, `name`, `intro`, `status`, `create_user_id`, `create_time`) VALUE (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    return sqlSession->executeInsert(sql, "%ull%s%s%s%i%d%i%ull%s%s%i%ull%s", uObj.getCustomerId(), uObj.getLinkmanId(), uObj.getFindDate(), uObj.getBillDate(), uObj.getSalestage(), uObj.getMoney(), uObj.getSuccessRate(), uObj.getUserId(), uObj.getName(), uObj.getIntro(), uObj.getStatus(), uObj.getCreateUserId(), uObj.getCreateTime());
}