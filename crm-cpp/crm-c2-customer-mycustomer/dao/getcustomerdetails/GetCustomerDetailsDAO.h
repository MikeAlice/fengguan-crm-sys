#pragma once
/*
* 负责人：老菌
*/
#ifndef _GETCUSTOMERDETAILS_DAO_
#define _GETCUSTOMERDETAILS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/customer/CustomerDO.h"
#include "domain/query/getcutomerdetails/GetCustomerDetailsQuery.h"
#include "dao/getcustomerdetails/GetCustomerDetailsMapper.h"

/**
 * 导出客户数据表操作实现
 */
class GetCustomerDetailsDAO : public BaseDAO
{
public:

	// 根据创建人和归属人查询所有客户信息
	list<CustomerDO> selectAll(const GetCustomerDetailsQuery::Wrapper& query);

};
#endif // !_GETCUSTOMERDETAILS_DAO_