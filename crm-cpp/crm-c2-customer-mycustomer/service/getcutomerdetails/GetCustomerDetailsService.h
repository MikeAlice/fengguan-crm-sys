#pragma once
/*
* 负责人：老菌
*/
#ifndef _GETCUSTOMERDETAILS_SERVICE_
#define _GETCUSTOMERDETAILS_SERVICE_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/getcustomerdetails/GetCustomerDetailsDTO.h"
#include "domain/query/getcutomerdetails/GetCustomerDetailsQuery.h"

/**
 * 获取客户详细信息服务实现
 */
class GetCustomerDetailsService
{
public:

	GetCustomerDetailsDTO::Wrapper getCustomerDetails(GetCustomerDetailsQuery::Wrapper query);


};

#endif // !_EXPORTCUSTOMER_SERVICE_