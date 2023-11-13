#pragma once
#ifndef _SAL_CONTRACT_DO_H
#define _SAL_CONTRACT_DO_H
#include "DoInclude.h"

class SalesContractDO
{
	//合同编号
	CC_SYNTHESIZE(int32_t, contract_id, Contract_id);
	// 订单主题
	CC_SYNTHESIZE(string, title, Title);
	// 合同编号
	CC_SYNTHESIZE(string, contract_no, Contract_no);
	// 客户ID
	CC_SYNTHESIZE(int16_t, customer_id, Customer_id);
	// 联系人ID
	CC_SYNTHESIZE(int16_t, linkman_id, Linkman_id);
	// 销售机会
	CC_SYNTHESIZE(int16_t, chance_id, Chance_id);
	// 关联网站
	CC_SYNTHESIZE(int16_t, website_id, Website_id);
	// 开始时间
	CC_SYNTHESIZE(string, start_date, Start_date);
	// 结束时间
	CC_SYNTHESIZE(string, end_date, End_date);
	// 我方联系人
	CC_SYNTHESIZE(int16_t, our_user_id, Our_user_id);
	// 合同金额
	CC_SYNTHESIZE(float, money, Money);
	// 商品金额
	CC_SYNTHESIZE(float, goods_money, Goods_money);
	// 去零金额
	CC_SYNTHESIZE(float, zero_money, Zero_money);
	// 回款金额
	CC_SYNTHESIZE(float, back_money, Back_money);
	// 欠款金额
	CC_SYNTHESIZE(float, owe_money, Owe_money);
	// 交付金额
	CC_SYNTHESIZE(float, deliver_money, Deliver_money);
	// 开票金额
	CC_SYNTHESIZE(float, invoice_money, Invoice_money);
	// 订单介绍
	CC_SYNTHESIZE(string, intro, Intro);
	// 状态
	CC_SYNTHESIZE(int8_t, status, Status);
	// 回款状态
	CC_SYNTHESIZE(int8_t, back_status, Back_status);
	// 交付状态
	CC_SYNTHESIZE(int8_t, deliver_status, Deliver_status);
	// 开票状态
	CC_SYNTHESIZE(int8_t, invoice_status, Invoice_status);
	// 订单类型
	CC_SYNTHESIZE(int8_t, renew_status, Renew_status);
	// 创建者
	CC_SYNTHESIZE(int16_t, create_user_id, Create_user_id);
	// 创建时间
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
