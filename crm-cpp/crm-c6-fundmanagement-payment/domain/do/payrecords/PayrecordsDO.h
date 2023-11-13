#pragma once
#ifndef _PAYRECORDS_DO_
#define _PAYRECORDS_DO_
#include "../DoInclude.h"

class PayrecordsDO
{
	// 付款记录id
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	// 付款计划id
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_id);
	// 合同id
	CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);
	// 采购合同名称
	CC_SYNTHESIZE(string, contract_name, Contract_name);
	// 供应商id
	CC_SYNTHESIZE(uint64_t, supplier_id, Supplier_id);
	// 供应商名称
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	// 银行id
	CC_SYNTHESIZE(uint64_t, bank_id, Bank_id);
	// 付款日期
	CC_SYNTHESIZE(string, pay_date, Pay_date);
	// 金额
	CC_SYNTHESIZE(uint64_t, money, Money);
	// 去零
	CC_SYNTHESIZE(uint64_t, zero_money, Zero_money);
	// 期次
	CC_SYNTHESIZE(uint64_t, stages, Stages);
	// 备注
	CC_SYNTHESIZE(string, intro, Intro);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 创建人id
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