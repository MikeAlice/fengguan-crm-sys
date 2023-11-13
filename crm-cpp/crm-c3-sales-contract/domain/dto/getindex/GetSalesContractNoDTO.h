#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _GETSALESCONTRACTNODTO_H_
#define _GETSALESCONTRACTNODTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取销售合同唯一编号 示例传输对象
 */
class GetSalesContractNoDTO : public oatpp::DTO
{
	DTO_INIT(GetSalesContractNoDTO, DTO);
	// 销售合同唯一编号
	DTO_FIELD(String, contract_no);
	DTO_FIELD_INFO(contract_no) {
		info->description = ZH_WORDS_GETTER("getindex.field.contract_no");
	}
	//// 销售合同id
	//DTO_FIELD(Int32, contract_id);
	//DTO_FIELD_INFO(contract_id) {
	//	info->description = ZH_WORDS_GETTER("getindex.field.contract_id");
	//}
	//// 订单主题
	//DTO_FIELD(String, title);
	//DTO_FIELD_INFO(title) {
	//	info->description = ZH_WORDS_GETTER("salescontract.get-salescontract.salescontracttitle");
	//}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_GETSALESCONTRACTNODTO_H_