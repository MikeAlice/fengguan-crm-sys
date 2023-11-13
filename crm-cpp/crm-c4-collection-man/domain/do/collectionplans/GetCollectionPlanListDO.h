#pragma once
#ifndef _GETCOLLECTIONPLAN_DO_
#define _GETCOLLECTIONPLAN_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class GetCollectionPlanListDO
{//一共13个
	// 计划编号（主键）
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_id);
	// 合同订单号
	CC_SYNTHESIZE(int32_t, contract_id, Contract_id);
	// 合同名称
	CC_SYNTHESIZE(string, contract_name, Contract_name);
	// 客户号
	CC_SYNTHESIZE(int32_t, customer_id, Customer_id);
	// 客户名称
	CC_SYNTHESIZE(string, customer_name, Customer_name);
	// 关联帐号
	CC_SYNTHESIZE(int32_t, bank_id, Bank_id);
	// money
	CC_SYNTHESIZE(int32_t, money, Money);
	// 计划回款时间
	CC_SYNTHESIZE(string, plan_date, Plan_date);
	// 期次
	CC_SYNTHESIZE(int32_t, stages, Stages);
	// 创建人ID
	CC_SYNTHESIZE(int32_t, create_user_id, Create_user_id);
	// 是否回款'NO=未付 YES=已经付'
	CC_SYNTHESIZE(string, ifpay, Ifpay);
	// intro
	CC_SYNTHESIZE(string, intro, Intro);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
public:
	GetCollectionPlanListDO() {
		plan_id = 0;
		contract_id = 0;
		contract_name = "";
		customer_id = 0;
		customer_name = "";
		bank_id = 0;
		money = 0;
		plan_date = "";
		stages = 0;
		create_user_id = 0;
		ifpay = "NO";
		intro = "";
		create_time = "";
	}
};

#endif // !_GETCOLLECTIONPLAN_DO_