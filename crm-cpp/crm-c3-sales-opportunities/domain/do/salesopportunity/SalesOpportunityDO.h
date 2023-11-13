#pragma once
#ifndef _SALES_OPPORTUNITY_DO_
#define _SALES_OPPORTUNITY_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class SalesOpportunityDO
{
	// 销售机会id
	CC_SYNTHESIZE(uint64_t, chance_id, ChanceId);
	// 客户id
	CC_SYNTHESIZE(uint64_t, customer_id, CustomerId);
	// 联系人id
	CC_SYNTHESIZE(string, linkman_id, LinkmanId);
	// 发现时间
	CC_SYNTHESIZE(string, find_date, FindDate);
	// 预计签单时间
	CC_SYNTHESIZE(string, bill_date, BillDate);
	// 谈判状态
	CC_SYNTHESIZE(int32_t, salestage, Salestage);
	// 预计金额
	CC_SYNTHESIZE(double, money, Money);
	// 预计可能性成功率
	CC_SYNTHESIZE(int32_t, success_rate, SuccessRate);
	// 用户id
	CC_SYNTHESIZE(uint64_t, userID, UserId);
	// 主题
	CC_SYNTHESIZE(string, name, Name);
	// 简介
	CC_SYNTHESIZE(string, intro, Intro);
	// 状态
	CC_SYNTHESIZE(int32_t, status, Status);
	// 创建用户id
	CC_SYNTHESIZE(uint64_t, create_user_id, CreateUserId);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);

public:
	SalesOpportunityDO() {
		chance_id = 0;
		customer_id = 0;
		linkman_id = "";
		find_date = "";
		bill_date = "";
		salestage = 0;
		money = 0.0;
		success_rate = 0;
		userID = 0;
		name = "";
		intro = "";
		status = 0;
		create_user_id = 0;
		create_time = "";
	}
};

#endif // !_SALES_OPPORTUNITY_DO_
