#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _GETCUSTOMERDETAILS_SERVICE_
#define _GETCUSTOMERDETAILS_SERVICE_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/getcustomerdetails/GetCustomerDetailsDTO.h"
#include "domain/query/getcutomerdetails/GetCustomerDetailsQuery.h"

/**
 * ��ȡ�ͻ���ϸ��Ϣ����ʵ��
 */
class GetCustomerDetailsService
{
public:

	GetCustomerDetailsDTO::Wrapper getCustomerDetails(GetCustomerDetailsQuery::Wrapper query);


};

#endif // !_EXPORTCUSTOMER_SERVICE_