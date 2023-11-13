#pragma once
#ifndef _GETCOLLECTIONPLAN_DO_
#define _GETCOLLECTIONPLAN_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class GetCollectionPlanListDO
{//һ��13��
	// �ƻ���ţ�������
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_id);
	// ��ͬ������
	CC_SYNTHESIZE(int32_t, contract_id, Contract_id);
	// ��ͬ����
	CC_SYNTHESIZE(string, contract_name, Contract_name);
	// �ͻ���
	CC_SYNTHESIZE(int32_t, customer_id, Customer_id);
	// �ͻ�����
	CC_SYNTHESIZE(string, customer_name, Customer_name);
	// �����ʺ�
	CC_SYNTHESIZE(int32_t, bank_id, Bank_id);
	// money
	CC_SYNTHESIZE(int32_t, money, Money);
	// �ƻ��ؿ�ʱ��
	CC_SYNTHESIZE(string, plan_date, Plan_date);
	// �ڴ�
	CC_SYNTHESIZE(int32_t, stages, Stages);
	// ������ID
	CC_SYNTHESIZE(int32_t, create_user_id, Create_user_id);
	// �Ƿ�ؿ�'NO=δ�� YES=�Ѿ���'
	CC_SYNTHESIZE(string, ifpay, Ifpay);
	// intro
	CC_SYNTHESIZE(string, intro, Intro);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
public:
	GetCollectionPlanListDO() {
		plan_id = 0;
		contract_id = 0;
		contract_name = "";
		customer_id = 0;
		customer_name = "";
		bank_id = 0;
		money = 0;
		plan_date = "";
		stages = 0;
		create_user_id = 0;
		ifpay = "NO";
		intro = "";
		create_time = "";
	}
};

#endif // !_GETCOLLECTIONPLAN_DO_