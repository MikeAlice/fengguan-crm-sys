#pragma once

#ifndef EXPENDITURESDO_H__
#define EXPENDITURESDO_H__
#include "../DoInclude.h"

class Other_income_statementDO
{
	// ����
	CC_SYNTHESIZE(int, record_id, RecordId);
	// ��������
	CC_SYNTHESIZE(string, type_, TypeId);
	// ���
	CC_SYNTHESIZE(double, money, Money);
	// �����˺�
	CC_SYNTHESIZE(string, bank, BankId);
	// ��������
	CC_SYNTHESIZE(string, happen_date, HappenDate);
	// ������
	CC_SYNTHESIZE(string, create_user, CreateUser);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// ��ע
	CC_SYNTHESIZE(string, intro, Intro);
public:
	Other_income_statementDO() {
		record_id = 1;
		type_ = "";
		money = 10.50;
		bank = "";
		happen_date = "";
		create_user = "";
		create_time = "";
		intro = "";
	}
};


#endif // EXPENDITURESDO_H__