#pragma once
/*
 @Author: linglan
 @Date: 2023/10/23 21:14:33

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
#ifndef _PAYMENTPLANDTO_H_
#define _PAYMENTPLANDTO_H_

#include "../../GlobalInclude.h"
#include "oatpp/web/server/api/ApiController.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个付款计划信息传输对象
 */

class PaymentPlanDTO : public oatpp::DTO
{
	DTO_INIT(PaymentPlanDTO, DTO);
	// 编号
	API_DTO_FIELD_DEFAULT(UInt64, plan_id, ZH_WORDS_GETTER("paymentplan.field.plan_id"));
	// 采购订单号
	API_DTO_FIELD_DEFAULT(UInt64, contract_id, ZH_WORDS_GETTER("paymentplan.field.contract_id"));
	// 采购合同名称
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("paymentplan.field.contract_name"));
	// 供应商号
	API_DTO_FIELD_DEFAULT(UInt64, supplier_id, ZH_WORDS_GETTER("paymentplan.field.supplier_id"));
	// 供应商名称
	API_DTO_FIELD_DEFAULT(String, supplier_name, ZH_WORDS_GETTER("paymentplan.field.supplier_name"));
	// 关联银行帐号
	API_DTO_FIELD_DEFAULT(UInt64, bank_id, ZH_WORDS_GETTER("paymentplan.field.bank_id"));
	// 金额
	API_DTO_FIELD_DEFAULT(UInt64, money, ZH_WORDS_GETTER("paymentplan.field.money"));
	// 计划付款日期
	API_DTO_FIELD_DEFAULT(String, plan_date, ZH_WORDS_GETTER("paymentplan.field.plan_date"));
	// 期次
	API_DTO_FIELD_DEFAULT(UInt64, stages, ZH_WORDS_GETTER("paymentplan.field.stages"));
	// 是否付款
	API_DTO_FIELD_DEFAULT(String, ifpay, ZH_WORDS_GETTER("paymentplan.field.ifpay"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("paymentplan.field.intro"));
	// 创建人id
	API_DTO_FIELD_DEFAULT(UInt64, create_user_id, ZH_WORDS_GETTER("paymentplan.field.create_user_id"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("paymentplan.field.create_time"));

};

/**
 * 定义一个付款计划信息列表分页传输对象
 */
class PaymentPlanPageDTO : public PageDTO<PaymentPlanDTO::Wrapper>
{
	DTO_INIT(PaymentPlanPageDTO, PageDTO<PaymentPlanDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAYMENTPLANDTO_H_
