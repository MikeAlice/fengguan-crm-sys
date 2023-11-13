#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/10/27

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _SALCONTRACTBASICINFODO_H_
#define _SALCONTRACTBASICINFODO_H_

#include "../DoInclude.h"

/**
 * 销售合同基础信息数据库实体类
 */

class SalContractBasicInfoDO
{
	// 合同ID
	CC_SYNTHESIZE(int, contract_id, ContractID);
	//// 合同编号
	//CC_SYNTHESIZE(string, contract_no, ContractNO);
	// 订单主题
	CC_SYNTHESIZE(string, title, Title);
	// 客户ID
	CC_SYNTHESIZE(int, customer_id, CustomerID);
	// 联系人ID
	CC_SYNTHESIZE(int, linkman_id, LinkmanID);
	// 开始时间
	CC_SYNTHESIZE(string, start_date, StartDate);
	// 结束时间
	CC_SYNTHESIZE(string, end_date, EndDate);
	// 合同金额
	CC_SYNTHESIZE(float, money, Money);
	// 订单介绍
	CC_SYNTHESIZE(string, intro, Intro);
	// 我方联系人
	CC_SYNTHESIZE(int, our_user_id, OurUserID);
public:
	SalContractBasicInfoDO()
	{
		contract_id = 1;
		/*contract_no = "1";*/
		title = "订单主题";
		customer_id = 1;
		linkman_id = 1;
		start_date = "2021-06-02";
		end_date = "2023-01-01";
		money = 2000.00;
		intro = "订单介绍";
		our_user_id = 1;
	}
};

#endif // !_SALCONTRACTBASICINFODO_H_