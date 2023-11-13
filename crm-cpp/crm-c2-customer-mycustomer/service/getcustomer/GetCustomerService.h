#ifndef _GETCUSTOMER_SERVICE_
#define _GETCUSTOMER_SERVICE_
#include <list>
#include "domain/vo/getcustomer/GetCustomerVO.h"
#include "domain/query/getcustomer/GetCustomerQuery.h"
#include "domain/dto/getcustomer/GetCustomerDTO.h"
#include "dao/getcustomer/GetCustomerDAO.h"

/**
 * 获取客户列表服务实现
 */
class GetCustomerService
{
public:
	// 查询所有客户
	GetCustomerPageDTO::Wrapper getCustomer(const GetCustomerQuery::Wrapper& query);
};

#endif // !_GETCUSTOMER_SERVICE_

