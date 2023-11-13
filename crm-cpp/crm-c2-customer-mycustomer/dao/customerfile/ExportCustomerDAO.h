#pragma once
/*
* 负责人：老菌
*/
#ifndef _EXPORTCUSTOMER_DAO_
#define _EXPORTCUSTOMER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/customer/CustomerDO.h"
#include "../../domain/query/customerfile/ExportCustomerQuery.h"
#include "dao/customerfile/ExportCustomerMapper.h"

/**
 * 导出客户数据表操作实现
 */
class ExportCustomerDAO : public BaseDAO
{
public:
	
	// 根据创建人和归属人查询所有客户信息
	list<CustomerDO> selectAll(const ExportCustomerQuery::Wrapper& query);

};
#endif // !_EXPORTCUSTOMER_DAO_
