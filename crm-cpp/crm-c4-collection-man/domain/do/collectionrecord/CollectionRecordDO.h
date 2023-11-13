#pragma once
#include"stdafx.h"
#include "../DoInclude.h"

class CollectionRecordDO {

	// 回款编号
	CC_SYNTHESIZE(uint64_t, record_id, record_id);
	//客户编号
	CC_SYNTHESIZE(uint64_t, customer_id, customer_id);
	// 客户名称
	CC_SYNTHESIZE(string, customer_name, customer_name);
	// 合同订单
	CC_SYNTHESIZE(uint64_t, contract_id, contract_id);
	//合同名称
	CC_SYNTHESIZE(string, contract_name, contract_name);
	//关联账号
	CC_SYNTHESIZE(uint64_t, bank_id, bank_id);
	//金额
	CC_SYNTHESIZE(uint64_t, money, money);
	//去零金额
	CC_SYNTHESIZE(uint64_t, zero_money, zero_money);
	//期次
	CC_SYNTHESIZE(uint64_t, stages, stages);
	//关联业务类型
	CC_SYNTHESIZE(string, bus_type, bus_type);
	//创建人id
	CC_SYNTHESIZE(uint64_t, create_user_id, create_user_id);
	//创建时间
	CC_SYNTHESIZE(string, create_time, create_time);

	CC_SYNTHESIZE(uint64_t, plan_id, plan_id);

	// 计划回款时间
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