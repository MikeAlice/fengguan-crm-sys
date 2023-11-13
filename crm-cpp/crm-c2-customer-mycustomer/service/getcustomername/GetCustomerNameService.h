#ifndef _GETCUSTOMERNAME_SERVICE_
#define _GETCUSTOMERNAME_SERVICE_
#include <list>
#include "domain/vo/getcustomername/GetCustomerNameVO.h"
#include "domain/dto/getcustomername/GetCustomerNameDTO.h"
#include "dao/getcustomername/GetCustomerNameDAO.h"
#include "domain/query/getcustomername/GetCustomerNameQuery.h"

/**
 * 获取客户名称列表服务实现
 */
class GetCustomerNameService
{
public:
	// 查询客户名称
	GetCustomerNameJsonVO::Wrapper getName(const GetCustomerNameQuery::Wrapper& query);
};

#endif // !_GETCUSTOMERNAME_SERVICE_
