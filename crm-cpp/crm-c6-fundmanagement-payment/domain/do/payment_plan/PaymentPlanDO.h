#pragma once
/*
 @Author: linglan
 @Date: 2023/10/24 17:51:51

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
#ifndef _PAYMENTPLANDO_H_
#define _PAYMENTPLANDO_H_
#include "../DoInclude.h"

class PaymentPlanDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_id);
	// 采购订单号
	CC_SYNTHESIZE(uint64_t, contract_id, Contract_id);
	// 采购合同名称
	CC_SYNTHESIZE(string, contract_name, Contract_name);
	// 供应商号
	CC_SYNTHESIZE(uint64_t, supplier_id, Supplier_id);
	// 供应商名称
	CC_SYNTHESIZE(string, supplier_name, Supplier_name);
	// 关联银行帐号
	CC_SYNTHESIZE(uint64_t, bank_id, Bank_id);
	// 金额
	CC_SYNTHESIZE(uint64_t, money, Money);
	// 计划付款日期
	CC_SYNTHESIZE(string, plan_date, Plan_date);
	// 期次
	CC_SYNTHESIZE(uint64_t, stages, Stages);
	// 是否付款
	CC_SYNTHESIZE(string, ifpay, Ifpay);
	// 备注
	CC_SYNTHESIZE(string, intro, Intro);
	// 创建人id
	CC_SYNTHESIZE(uint64_t, create_user_id, Create_user_id);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
public:
	PaymentPlanDO() {
		plan_id = 0;
		contract_id = 0;
		contract_name = "";
		supplier_id = 0;
		supplier_name = "";
		bank_id = 0;
		money = 0;
		plan_date = "";
		stages = 0;
		ifpay = "-1";
		intro = "";
		create_user_id = 0;
		create_time = "";
	}
};

#endif // !_PAYMENTPLANDO_H_
