#pragma once
#ifndef INSTORAGEDO_H_
#define INSTORAGEDO_H_

#include "../DoInclude.h"

class InStorageDO3 {
public:
	// 数量
	CC_SYNTHESIZE(string, number, Number);
	//商品id
	CC_SYNTHESIZE(uint64_t, goods_id, Goods_id);
public:
	InStorageDO3() {
		number = "";
		goods_id = 0;
	}
};

class InStorageDO2 {
public:
	// 单号
	CC_SYNTHESIZE(uint64_t, id, Id);
	//// 入库人
	CC_SYNTHESIZE(string, into_user_id, Into_user_id);
public:
	InStorageDO2() {
		id = 0;
		into_user_id = "";
	}
};

class InStorageDO {
public:
	// 入库状态
	CC_SYNTHESIZE(uint64_t, status, STatus);
	// 单号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 合同编号
	CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);
	// 主题
	CC_SYNTHESIZE(string, title, Title);
	// 仓库编号
	CC_SYNTHESIZE(uint64_t, store_id, Store_id);
	// 入库人
	CC_SYNTHESIZE(string, into_user_name, Into_user_name);
	// 入库人编号
	CC_SYNTHESIZE(uint64_t, into_user_id, Into_user_id);
	// 创建人
	CC_SYNTHESIZE(string, create_user_name, Create_user_name);
	// 创建人编号
	CC_SYNTHESIZE(uint64_t, create_user_id, Create_user_id);
	// 备注
	CC_SYNTHESIZE(string, intro, Intro);
	// 数量
	CC_SYNTHESIZE(uint64_t, number, Number);
	// 金额
	CC_SYNTHESIZE(double, money, Money);
	// 入库时间
	CC_SYNTHESIZE(string, into_time, Into_time);
	// 入库类型
	CC_SYNTHESIZE(string, into_type, Into_type);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
public:
	InStorageDO() {
		id = 0;
		contract_id = 0;
		title = "";
		store_id = 0;
		into_user_id = 0;
		create_user_id = 0;
		intro = "";
		status = -1;
		number = 0;
		money = 0;
		into_time = "1000-01-01 00:00:00";
		into_type = "";
		create_time = "1000-01-01 00:00:00";
	}
};

#endif // !INSTORAGEDO_H_
