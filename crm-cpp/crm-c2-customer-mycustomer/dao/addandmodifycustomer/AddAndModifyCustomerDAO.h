#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/customer/CustomerDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class AddAndModifyCustomerDAO : public BaseDAO
{
public:
	// ��ӿͻ�
	uint64_t insert(const CustomerDO& iObj);
	// �޸Ŀͻ���Ϣ
	int update(const CustomerDO& uObj);
	
};
#endif // !_SAMPLE_DAO_
