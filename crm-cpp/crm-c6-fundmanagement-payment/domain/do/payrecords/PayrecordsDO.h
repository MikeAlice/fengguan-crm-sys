#pragma once
#ifndef _PAYRECORDS_DO_
#define _PAYRECORDS_DO_
#include "../DoInclude.h"

class PayrecordsDO
{
	// �����¼id
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	// ����ƻ�id
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_id);
	// ��ͬid
	CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);
	// �ɹ���ͬ����
	CC_SYNTHESIZE(string, contract_name, Contract_name);
	// ��Ӧ��id
	CC_SYNTHESIZE(uint64_t, supplier_id, Supplier_id);
	// ��Ӧ������
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	// ����id
	CC_SYNTHESIZE(uint64_t, bank_id, Bank_id);
	// ��������
	CC_SYNTHESIZE(string, pay_date, Pay_date);
	// ���
	CC_SYNTHESIZE(uint64_t, money, Money);
	// ȥ��
	CC_SYNTHESIZE(uint64_t, zero_money, Zero_money);
	// �ڴ�
	CC_SYNTHESIZE(uint64_t, stages, Stages);
	// ��ע
	CC_SYNTHESIZE(string, intro, Intro);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// ������id
	CC_SYNTHESIZE(uint64_t, create_user_id, Create_user_id);

public:
	PayrecordsDO() {
		contract_name = "";	
		supplier_name = "";
		money = 0;
		zero_money = 0;
		pay_date = "";
		stages = 0;
		intro = "";
		create_user_id = 0;
		create_time = "";
		record_id = 0;
		plan_id = 0;
		contract_id = 0;
		supplier_id = 0;
		bank_id = 0;
	}
};

#endif // !_PAYRECORDSDO_H_