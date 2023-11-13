#pragma once
#include"stdafx.h"
#include "../DoInclude.h"

class CollectionRecordDO {

	// �ؿ���
	CC_SYNTHESIZE(uint64_t, record_id, record_id);
	//�ͻ����
	CC_SYNTHESIZE(uint64_t, customer_id, customer_id);
	// �ͻ�����
	CC_SYNTHESIZE(string, customer_name, customer_name);
	// ��ͬ����
	CC_SYNTHESIZE(uint64_t, contract_id, contract_id);
	//��ͬ����
	CC_SYNTHESIZE(string, contract_name, contract_name);
	//�����˺�
	CC_SYNTHESIZE(uint64_t, bank_id, bank_id);
	//���
	CC_SYNTHESIZE(uint64_t, money, money);
	//ȥ����
	CC_SYNTHESIZE(uint64_t, zero_money, zero_money);
	//�ڴ�
	CC_SYNTHESIZE(uint64_t, stages, stages);
	//����ҵ������
	CC_SYNTHESIZE(string, bus_type, bus_type);
	//������id
	CC_SYNTHESIZE(uint64_t, create_user_id, create_user_id);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, create_time);

	CC_SYNTHESIZE(uint64_t, plan_id, plan_id);

	// �ƻ��ؿ�ʱ��
	CC_SYNTHESIZE(string, back_date, back_date);
public:
	CollectionRecordDO() {
		record_id=0;
		contract_id=0;
		contract_name="";
		plan_id=0;
		customer_id=0;
		customer_name="";
		bank_id=0;
		money=0;
		zero_money=0;
		back_date="";
		stages=0;
		bus_type="";
		create_time="";
		create_user_id=0;
	}


};