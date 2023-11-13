#pragma once
/*
 @Author: linglan
 @Date: 2022/12/03 11:01:02

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
#ifndef _PAYMENTPLANQUERY_H_
#define _PAYMENTPLANQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询用户信息的数据传输模型
 */
class PaymentPlanQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(PaymentPlanQuery, PageQuery);

	// 编号
	API_DTO_FIELD_DEFAULT(UInt64, plan_id, ZH_WORDS_GETTER("paymentplan.field.plan_id"));
	// 采购合同名称
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("paymentplan.field.contract_name"));
	// 供应商号
	API_DTO_FIELD_DEFAULT(UInt64, supplier_id, ZH_WORDS_GETTER("paymentplan.field.supplier_id"));
	// 供应商名称
	API_DTO_FIELD_DEFAULT(String, supplier_name, ZH_WORDS_GETTER("paymentplan.field.supplier_name"));
	// 金额
	API_DTO_FIELD_DEFAULT(UInt64, money, ZH_WORDS_GETTER("paymentplan.field.money"));
	// 计划付款日期
	API_DTO_FIELD_DEFAULT(String, plan_date, ZH_WORDS_GETTER("paymentplan.field.plan_date"));
	// 是否付款
	API_DTO_FIELD_DEFAULT(String, ifpay, ZH_WORDS_GETTER("paymentplan.field.ifpay"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("paymentplan.field.create_time"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PAYMENTPLANQUERY_H_