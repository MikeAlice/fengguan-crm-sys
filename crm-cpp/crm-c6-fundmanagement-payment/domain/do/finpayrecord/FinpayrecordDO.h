#pragma once
#ifndef _FINPAYRECORD_DO_
#define _FINPAYRECORD_DO_

#include "../DoInclude.h"

class FinpayrecordDO {
	CC_SYNTHESIZE(int, record_id, Record_id);
	CC_SYNTHESIZE(int, plan_id, Plan_id);
	CC_SYNTHESIZE(int, contract_id, Contract_id);
	CC_SYNTHESIZE(string, contract_name, Contract_name);
	CC_SYNTHESIZE(int, supplier_id, Supplier_id);
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	CC_SYNTHESIZE(int, bank_id, Bank_id);
	CC_SYNTHESIZE(string, pay_date, Pay_date);
	CC_SYNTHESIZE(double, money, Money);
	CC_SYNTHESIZE(double, zero_money, Zero_money);
	CC_SYNTHESIZE(int, stages, Stages);
	CC_SYNTHESIZE(string, intro, Intro);
	CC_SYNTHESIZE(string, create_time, Create_time);
	CC_SYNTHESIZE(int, create_user_id, Create_user_id);
public:
	FinpayrecordDO() {
		record_id = 0;
		plan_id = 0;
		contract_id = 0;
		contract_name = "";
		supplier_id = 0;
		supplier_name = "";
		bank_id = 0;
		pay_date = "";
		money = 0;
		zero_money = 0;
		stages = 0;
		intro = "";
		create_time = "0";
		create_user_id = 0;
	}
};

#endif // !_FINPAYRECORD_DO_
