#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _EXPORTCUSTOMER_DAO_
#define _EXPORTCUSTOMER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/customer/CustomerDO.h"
#include "../../domain/query/customerfile/ExportCustomerQuery.h"
#include "dao/customerfile/ExportCustomerMapper.h"

/**
 * �����ͻ����ݱ����ʵ��
 */
class ExportCustomerDAO : public BaseDAO
{
public:
	
	// ���ݴ����˺͹����˲�ѯ���пͻ���Ϣ
	list<CustomerDO> selectAll(const ExportCustomerQuery::Wrapper& query);

};
#endif // !_EXPORTCUSTOMER_DAO_
