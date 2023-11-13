#pragma once
#ifndef _OUT_BOUND_DO_
#define _OUT_BOUND_DO_
#include "../DoInclude.h"

/**
 * 出库单数据库实体类
 */
class Out_boundDO
{
	// 出库单id
	CC_SYNTHESIZE(uint16_t, out_id, Out_id);
	// 仓库编号
	CC_SYNTHESIZE(uint16_t, store_id, Store_id);
	// 销售合同编号
	CC_SYNTHESIZE(uint16_t, contract_id, Contract_id);
	// 订单主题
	CC_SYNTHESIZE(string, title, Title);
	// 金额
	CC_SYNTHESIZE(double, money, Money);
	// 数量
	CC_SYNTHESIZE(uint16_t, number, Number);
	// 订单介绍
	CC_SYNTHESIZE(string, intro, Intro);
	// 出库状态：1=已出库，0=未出库
	CC_SYNTHESIZE(uint16_t, status, Status);
	// 出库管理员
	CC_SYNTHESIZE(uint16_t, out_user_id, Out_user_id);
	// 出库时间
	CC_SYNTHESIZE(string, out_time, Out_time);
	// 出库类型
	CC_SYNTHESIZE(string, out_type, Out_type);
	// 创建人
	CC_SYNTHESIZE(uint16_t, create_user_id, Create_user_id);
	// 创建时间
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