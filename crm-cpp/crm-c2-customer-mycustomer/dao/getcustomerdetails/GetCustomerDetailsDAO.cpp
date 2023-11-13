/*
* 负责人：老菌
*/
#include "stdafx.h"
#include <sstream>
#include "GetCustomerDetailsDAO.h"


list<CustomerDO> GetCustomerDetailsDAO::selectAll(const GetCustomerDetailsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT name,linkman,source,grade,industry,mobile,tel,address,intro,needs \
			FROM cst_customer WHERE customer_id=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "i", int, query->customer_id.getValue(0));
	GetCustomerDetailsMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CustomerDO, GetCustomerDetailsMapper>(sqlStr, mapper, params);
}
