#pragma once

#ifndef EXPENDITURESDO_H__
#define EXPENDITURESDO_H__
#include "../DoInclude.h"

class Other_income_statementDO
{
	// 单号
	CC_SYNTHESIZE(int, record_id, RecordId);
	// 收入类型
	CC_SYNTHESIZE(string, type_, TypeId);
	// 金额
	CC_SYNTHESIZE(double, money, Money);
	// 银行账号
	CC_SYNTHESIZE(string, bank, BankId);
	// 产生日期
	CC_SYNTHESIZE(string, happen_date, HappenDate);
	// 创建人
	CC_SYNTHESIZE(string, create_user, CreateUser);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// 备注
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