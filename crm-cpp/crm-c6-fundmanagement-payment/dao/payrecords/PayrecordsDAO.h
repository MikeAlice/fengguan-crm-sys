#pragma once
#ifndef _PAYRECORDS_DAO_
#define _PAYRECORDS_DAO_

#include "BaseDAO.h"
#include "domain/query/payrecords/PayrecordsQuery.h"
#include "domain/do/payrecords/PayrecordsDO.h"

class PayrecordsDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const PayrecordsQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<PayrecordsDO> selectWithPage(const PayrecordsQuery::Wrapper& query);
	// ͨ������ʱ���ѯ����
	list<PayrecordsDO> selectByPay_date(const string& pay_date);
	// ͨ������ʱ���ѯ����
	list<PayrecordsDO> selectByCreate_time(const string& create_time);
	// ͨ���ɹ���ͬ���Ʋ�ѯ����
	list<PayrecordsDO> selectByContract_name(const string& contract_name);
	// ͨ����Ӧ�����Ʋ�ѯ����
	list<PayrecordsDO> selectBySupplier_name(const string& supplier_name);
	// ͨ���������ѯ����
	list<PayrecordsDO> selectByMoney(const uint64_t money);
};

#endif // !_PAYRECORDS_H_