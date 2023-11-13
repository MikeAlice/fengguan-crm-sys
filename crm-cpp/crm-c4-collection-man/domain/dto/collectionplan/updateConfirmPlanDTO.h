#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hf
 @Date: 2023/10/21 21:17:38

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
#ifndef _UPDATECONFIRMPLAN_DTO_
#define _UPDATECONFIRMPLAN_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 修改回款计划传输数据对象
 */
class updateConfirmPlanDTO : public oatpp::DTO
{
	DTO_INIT(updateConfirmPlanDTO, DTO);

	// 客户名称
	API_DTO_FIELD_DEFAULT(String, clientName, ZH_WORDS_GETTER("collectionplan.field.clientName"));

	// 销售合同
	API_DTO_FIELD_DEFAULT(String, saleContract, ZH_WORDS_GETTER("collectionplan.field.saleContract"));

	// 客户名称编号
	API_DTO_FIELD_DEFAULT(Int64, clientNameId, ZH_WORDS_GETTER("collectionplan.field.clientNameId"));

	// 销售合同编号
	API_DTO_FIELD_DEFAULT(Int64, saleContractId, ZH_WORDS_GETTER("collectionplan.field.saleContractId"));

	// 总金额
	API_DTO_FIELD_DEFAULT(Float32, totalAmount, ZH_WORDS_GETTER("collectionplan.field.totalAmount"));

	// 去零金额
	API_DTO_FIELD_DEFAULT(Float32, noZeroAmount, ZH_WORDS_GETTER("collectionplan.field.noZeroAmount"));

	// 已付金额
	API_DTO_FIELD_DEFAULT(Float32, havePayAmount, ZH_WORDS_GETTER("collectionplan.field.havePayAmount"));

	// 已开发票金额
	API_DTO_FIELD_DEFAULT(Float32, invoiceAmount, ZH_WORDS_GETTER("collectionplan.field.invoiceAmount"));

	// 计划回款日期
	API_DTO_FIELD_DEFAULT(String, planBackDate, ZH_WORDS_GETTER("collectionplan.field.planBackDate"));

	// 期次
	API_DTO_FIELD_DEFAULT(Int32, period, ZH_WORDS_GETTER("collectionplan.field.period"));

	// 回款金额
	API_DTO_FIELD_DEFAULT(Float32, payAmount, ZH_WORDS_GETTER("collectionplan.field.payAmount"));

	// 回款账户
	API_DTO_FIELD_DEFAULT(String, payAccount, ZH_WORDS_GETTER("collectionplan.field.payAccount"));

	// 计划回款编号
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("collectionplan.field.id"));

};


#include OATPP_CODEGEN_END(DTO)
#endif // 