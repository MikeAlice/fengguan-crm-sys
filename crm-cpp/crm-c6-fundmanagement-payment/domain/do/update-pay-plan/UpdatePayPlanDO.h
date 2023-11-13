#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _ADD_PAY_RECORD_
#define _ADD_PAY_RECORD_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class UpdatePayPlanDO
{
	// 记录编号
//	CC_SYNTHESIZE(uint64_t, record_id, RecordId);
	// 计划编号
	CC_SYNTHESIZE(uint64_t, plan_id, PlanId);
	// 合同编号
	CC_SYNTHESIZE(uint64_t, contract_id, ContractId);
	// 合同名称
	CC_SYNTHESIZE(string, contract_name, ContractName);
	// 供应商编号
	CC_SYNTHESIZE(uint64_t, supplier_id, SupplierId);
	// 供应商名称
	CC_SYNTHESIZE(string, supplier_name, SupplierName);
	// 银行编号
	CC_SYNTHESIZE(uint64_t, band_id, BankId);
	// 计划付款日期
	CC_SYNTHESIZE(string, plan_date, PlanDate);
	// 付款金额
	CC_SYNTHESIZE(string, money, Money);
	//是否付款
	CC_SYNTHESIZE(string, ifpay, IfPay);
	// 期次
	CC_SYNTHESIZE(uint64_t, stages, Stages);
	// 备注
	CC_SYNTHESIZE(string, intro, Intro);
	// 创建记录时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// 创建的用户id
	CC_SYNTHESIZE(uint64_t, create_user_id, CreateUserId);

public:
	std::string ContracttoString() const {
		std::string result = contract_name + "";
		return result;
	}
	std::string SuppliertoString() const {
		std::string result = supplier_name + "";
		return result;
	}
	UpdatePayPlanDO() {
		//		record_id = 0;
		plan_id = 0;
		contract_id = 0;
		contract_name = "";
		supplier_id = 0;
		supplier_name = "";
		band_id = 0;
		money = -1;
		stages = 0;
		intro = "";
		create_time = "";
		create_user_id = 0;
	}
};

#endif // !_SAMPLE_DO_
