#pragma once
#ifndef _ADDSALESCONTRACTDO_H_
#define _ADDSALESCONTRACTDO_H_
#include "../DoInclude.h"

/**
* 原味的原味包
* 插入到数据库中的数据
* 合同编号	contract_no
* 标题		title
* 客户名称	customer_name
* 联系人	linkman_name
* 销售机会	chance_name
* 起始日期	start_date
* 结束日期	end_date
* 合同金额	money
* 介绍		intro
*/
class AddSalesContractDO
{
	CC_SYNTHESIZE(string, contract_no, ContractNo);
	CC_SYNTHESIZE(string, title, Title);
	CC_SYNTHESIZE(string, customer_name, CustomerName);
	CC_SYNTHESIZE(string, linkman_name, LinkmanName);
	CC_SYNTHESIZE(string, chance_name, ChanceName);
	CC_SYNTHESIZE(string, start_date, StartDate);
	CC_SYNTHESIZE(string, end_date, EndDate);
	CC_SYNTHESIZE(double_t, money, Money);
	CC_SYNTHESIZE(string, intro, Intro);
	CC_SYNTHESIZE(string, our_user_name, OurUserName);

public:
	AddSalesContractDO() {
		contract_no = "";
		title = "";
		customer_name = "";
		linkman_name = "";
		chance_name = "";
		start_date = "";
		end_date = "";
		money = 0.0;
		intro = "";
		our_user_name = "";
	}
};

/**
* 原味的原味包
* 用于存储获取客户ID、联系人ID等的临时DO
* 客户名称	customer_id
* 联系人	linkman_id
* 销售机会	chance_id
* 我方代表	our_user_id
*/
class AddSalesContractTempDO
{
	CC_SYNTHESIZE(uint64_t, customer_id, CustomerID);
	CC_SYNTHESIZE(uint64_t, linkman_id, LinkmanID);
	CC_SYNTHESIZE(uint64_t, chance_id, ChanceID);
	CC_SYNTHESIZE(uint64_t, our_user_id, OurUserID);

public:
	AddSalesContractTempDO() {}
};


#endif