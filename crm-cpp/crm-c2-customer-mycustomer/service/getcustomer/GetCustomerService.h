#ifndef _GETCUSTOMER_SERVICE_
#define _GETCUSTOMER_SERVICE_
#include <list>
#include "domain/vo/getcustomer/GetCustomerVO.h"
#include "domain/query/getcustomer/GetCustomerQuery.h"
#include "domain/dto/getcustomer/GetCustomerDTO.h"
#include "dao/getcustomer/GetCustomerDAO.h"

/**
 * ��ȡ�ͻ��б����ʵ��
 */
class GetCustomerService
{
public:
	// ��ѯ���пͻ�
	GetCustomerPageDTO::Wrapper getCustomer(const GetCustomerQuery::Wrapper& query);
};

#endif // !_GETCUSTOMER_SERVICE_

