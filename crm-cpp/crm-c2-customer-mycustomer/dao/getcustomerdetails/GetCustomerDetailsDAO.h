#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _GETCUSTOMERDETAILS_DAO_
#define _GETCUSTOMERDETAILS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/customer/CustomerDO.h"
#include "domain/query/getcutomerdetails/GetCustomerDetailsQuery.h"
#include "dao/getcustomerdetails/GetCustomerDetailsMapper.h"

/**
 * �����ͻ����ݱ����ʵ��
 */
class GetCustomerDetailsDAO : public BaseDAO
{
public:

	// ���ݴ����˺͹����˲�ѯ���пͻ���Ϣ
	list<CustomerDO> selectAll(const GetCustomerDetailsQuery::Wrapper& query);

};
#endif // !_GETCUSTOMERDETAILS_DAO_