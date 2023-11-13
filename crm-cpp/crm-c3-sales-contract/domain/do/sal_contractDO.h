#pragma once
#ifndef _SAL_CONTRACT_DO_H
#define _SAL_CONTRACT_DO_H
#include "DoInclude.h"

class SalesContractDO
{
	//��ͬ���
	CC_SYNTHESIZE(int32_t, contract_id, Contract_id);
	// ��������
	CC_SYNTHESIZE(string, title, Title);
	// ��ͬ���
	CC_SYNTHESIZE(string, contract_no, Contract_no);
	// �ͻ�ID
	CC_SYNTHESIZE(int16_t, customer_id, Customer_id);
	// ��ϵ��ID
	CC_SYNTHESIZE(int16_t, linkman_id, Linkman_id);
	// ���ۻ���
	CC_SYNTHESIZE(int16_t, chance_id, Chance_id);
	// ������վ
	CC_SYNTHESIZE(int16_t, website_id, Website_id);
	// ��ʼʱ��
	CC_SYNTHESIZE(string, start_date, Start_date);
	// ����ʱ��
	CC_SYNTHESIZE(string, end_date, End_date);
	// �ҷ���ϵ��
	CC_SYNTHESIZE(int16_t, our_user_id, Our_user_id);
	// ��ͬ���
	CC_SYNTHESIZE(float, money, Money);
	// ��Ʒ���
	CC_SYNTHESIZE(float, goods_money, Goods_money);
	// ȥ����
	CC_SYNTHESIZE(float, zero_money, Zero_money);
	// �ؿ���
	CC_SYNTHESIZE(float, back_money, Back_money);
	// Ƿ����
	CC_SYNTHESIZE(float, owe_money, Owe_money);
	// �������
	CC_SYNTHESIZE(float, deliver_money, Deliver_money);
	// ��Ʊ���
	CC_SYNTHESIZE(float, invoice_money, Invoice_money);
	// ��������
	CC_SYNTHESIZE(string, intro, Intro);
	// ״̬
	CC_SYNTHESIZE(int8_t, status, Status);
	// �ؿ�״̬
	CC_SYNTHESIZE(int8_t, back_status, Back_status);
	// ����״̬
	CC_SYNTHESIZE(int8_t, deliver_status, Deliver_status);
	// ��Ʊ״̬
	CC_SYNTHESIZE(int8_t, invoice_status, Invoice_status);
	// ��������
	CC_SYNTHESIZE(int8_t, renew_status, Renew_status);
	// ������
	CC_SYNTHESIZE(int16_t, create_user_id, Create_user_id);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);

public:
	SalesContractDO() {
		contract_id = 0;
		title = "";
		contract_no = "";
		customer_id = 0;
		linkman_id = 0;
		chance_id = 0;
		website_id = 0;
		start_date = "";
		end_date = "";
		our_user_id = 0;
		money = 0.00;
		goods_money = 0.00;
		zero_money = 0.00;
		back_money = 0.00;
		owe_money = 0.00;
		deliver_money = 0.00;
		invoice_money = 0.00;
		intro = "";
		status = 0;
		back_status = 0;
		deliver_status = 0;
		invoice_status = 0;
		renew_status = 0;
		create_user_id = 0;
		create_time = "";
	}
};

#endif // !_SAL_CONTRACT_DO_H
