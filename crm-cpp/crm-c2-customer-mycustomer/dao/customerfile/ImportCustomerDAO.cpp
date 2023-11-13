/*
* 负责人：老菌
*/
#include "stdafx.h"
#include <sstream>
#include "ImportCustomerDAO.h"
#include "dao/customerfile/ImportCustomerMapper.h"


uint64_t ImportCustomerDAO::selectUserIdByName(string user_name)
{
	stringstream sql;

	sql << "SELECT id FROM fly_sys_user";
	SqlParams params;
	sql << " WHERE name=?"; 
	SQLPARAMS_PUSH(params, "s", string, user_name); 
	
	ImportCustomerMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

uint64_t ImportCustomerDAO::insert(const CustomerDO& iObj)
{
	string sql = "INSERT INTO `cst_customer` (`name`, `create_user_id`, `owner_user_id`, \
				`create_time`, `next_time`,`conn_time`,`conn_body`) \
				VALUES (?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%i%i%s%s%s%s", \
		iObj.getName(), iObj.getCreate_User_Id(), iObj.getOwner_User_Id(), \
		iObj.getCreate_Time(), iObj.getNext_Time(), iObj.getConn_Time(), \
		iObj.getConn_Body());
}
