#include "stdafx.h"
#include "AddAndModifyCustomerDAO.h"
#include "AddAndModifyCustomerMapper.h"
#include <sstream>
uint64_t AddAndModifyCustomerDAO::insert(const CustomerDO& iObj)
{
	string sql = "INSERT INTO `cst_customer` (`name`, `source`, `grade`,`industry`, `mobile`,`tel`,`address`,`intro`, `needs` ,`owner_user_id`,`create_user_id`,`create_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s%i%i%s", iObj.getName(), iObj.getSource(), iObj.getGrade(), iObj.getIndustry(),iObj.getMobile(),iObj.getTel(),iObj.getAddress(),iObj.getIntro(),iObj.getNeeds(),iObj.getOwner_User_Id(), iObj.getCreate_User_Id(), iObj.getCreate_Time());
}
int AddAndModifyCustomerDAO::update(const CustomerDO& uObj)
{
	string sql = "UPDATE `cst_customer` SET `name`=?, `source`=?, `grade`=?, `industry`=?, `mobile`=?,`tel`=?,`address`=?,`intro`=?, `needs`=?  where `customer_id` = ?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%i", uObj.getName(), uObj.getSource(), uObj.getGrade(), uObj.getIndustry(), uObj.getMobile(), uObj.getTel(), uObj.getAddress(), uObj.getIntro(), uObj.getNeeds(), uObj.getCustomer_Id());
}