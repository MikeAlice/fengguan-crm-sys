#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/10/22

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
#ifndef _MODIFYSALCONTRACTBASICINFODTO_H_
#define _MODIFYSALCONTRACTBASICINFODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 修改销售合同基础信息传输数据
 */
class ModifySalContractBasicInfoDTO : public oatpp::DTO
{
	DTO_INIT(ModifySalContractBasicInfoDTO, DTO);
	// 合同ID
	API_DTO_FIELD_DEFAULT(Int32, contract_id, ZH_WORDS_GETTER("sal-contract.field.contract-id"));
	//// 合同编号
	//API_DTO_FIELD_DEFAULT(String, contract_no, ZH_WORDS_GETTER("sal-contract.field.contract-no"));
	// 订单主题
	API_DTO_FIELD_DEFAULT(String, title, ZH_WORDS_GETTER("sal-contract.field.title"));
	// 客户ID
	API_DTO_FIELD_DEFAULT(Int32, customer_id, ZH_WORDS_GETTER("sal-contract.field.customer-id"));
	// 联系人ID
	API_DTO_FIELD_DEFAULT(Int32, linkman_id, ZH_WORDS_GETTER("sal-contract.field.linkman-id"));
	// 开始时间
	API_DTO_FIELD_DEFAULT(String, start_date, ZH_WORDS_GETTER("sal-contract.field.start-date"));
	// 结束时间
	API_DTO_FIELD_DEFAULT(String, end_date, ZH_WORDS_GETTER("sal-contract.field.end-date"));
	// 合同金额
	API_DTO_FIELD_DEFAULT(Float32, money, ZH_WORDS_GETTER("sal-contract.field.money"));
	// 订单介绍
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("sal-contract.field.intro"));
	// 我方联系人
	API_DTO_FIELD_DEFAULT(Int32, our_user_id, ZH_WORDS_GETTER("sal-contract.field.our-user-id"));


};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MODIFYSALCONTRACTBASICINFODTO_H_