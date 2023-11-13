#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _EXPORTCUSTOMER_DAO_
#define _EXPORTCUSTOMER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/systemuser/SystemUserDO.h"
#include "dao/customerfile/ImportCustomerMapper.h"

/**
 * ����ͻ����ݱ����ʵ��
 */
class ImportCustomerDAO : public BaseDAO
{
public:

	// ���ݹ�����������ѯ������ID
	uint64_t selectUserIdByName(string user_name);

	// ������Ŀͻ���Ϣ����ͻ���
	uint64_t insert(const CustomerDO& iObj);

};
#endif // !_EXPORTCUSTOMER_DAO_