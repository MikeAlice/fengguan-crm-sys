#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/29 13:50:05

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
#ifndef _PAYPLANDTO_H_
#define _PAYPLANDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PayPlanDTO : public oatpp::DTO
{
	DTO_INIT(PayPlanDTO, DTO);
	// 采购订单号
	API_DTO_FIELD(UInt64, contract_id, ZH_WORDS_GETTER("payplan.field.contract_id"), true, 123)
	// 采购合同名称
	API_DTO_FIELD(String, contract_name, ZH_WORDS_GETTER("payplan.field.contract_name"), true, "123")
	// 供应商号
	API_DTO_FIELD(UInt64, suplier_id, ZH_WORDS_GETTER("payplan.field.suplier_id"), true, 123)
	// 供应商名称
	API_DTO_FIELD(String, suplier_name, ZH_WORDS_GETTER("payplan.field.suplier_id"), true, "123")
	// 日期
	API_DTO_FIELD(String, datee, ZH_WORDS_GETTER("payplan.field.date"), true, "2023-01-01")
	// 期次
	API_DTO_FIELD(UInt64, stage, ZH_WORDS_GETTER("payplan.field.stages"), true, 123)
	// 金额
	API_DTO_FIELD(UInt64, money, ZH_WORDS_GETTER("payplan.field.money"), true, 123)
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAYPLANDTO_H_