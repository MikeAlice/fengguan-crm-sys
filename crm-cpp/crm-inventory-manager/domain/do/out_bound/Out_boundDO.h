#pragma once
#ifndef _OUT_BOUND_DO_
#define _OUT_BOUND_DO_
#include "../DoInclude.h"

/**
 * ���ⵥ���ݿ�ʵ����
 */
class Out_boundDO
{
	// ���ⵥid
	CC_SYNTHESIZE(uint16_t, out_id, Out_id);
	// �ֿ���
	CC_SYNTHESIZE(uint16_t, store_id, Store_id);
	// ���ۺ�ͬ���
	CC_SYNTHESIZE(uint16_t, contract_id, Contract_id);
	// ��������
	CC_SYNTHESIZE(string, title, Title);
	// ���
	CC_SYNTHESIZE(double, money, Money);
	// ����
	CC_SYNTHESIZE(uint16_t, number, Number);
	// ��������
	CC_SYNTHESIZE(string, intro, Intro);
	// ����״̬��1=�ѳ��⣬0=δ����
	CC_SYNTHESIZE(uint16_t, status, Status);
	// �������Ա
	CC_SYNTHESIZE(uint16_t, out_user_id, Out_user_id);
	// ����ʱ��
	CC_SYNTHESIZE(string, out_time, Out_time);
	// ��������
	CC_SYNTHESIZE(string, out_type, Out_type);
	// ������
	CC_SYNTHESIZE(uint16_t, create_user_id, Create_user_id);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);


public:
	Out_boundDO() {
		out_id = 0;
		store_id = 0;
		contract_id = 0;
		title = "";
		money = 0.00;
		number = 0;
		intro = "";
		status = -1;
		out_user_id = 0;
		out_time = "";
		out_type = "";
		create_user_id = 0;
		create_time = "";
	}
};

#endif // !_OUT_BOUND_DO_