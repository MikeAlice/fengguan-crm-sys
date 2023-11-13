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
#ifndef _DELETEDETAILSDTO_H_
#define _DELETEDETAILSDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeleteDetailsDTO : public oatpp::DTO
{
	DTO_INIT(DeleteDetailsDTO, DTO);
	// 合同明细表，订单项id
	DTO_FIELD(UInt64, list_id);
	DTO_FIELD_INFO(list_id) {
		info->description = ZH_WORDS_GETTER("contractindex.field.list_id");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DELETEDETAILSDTO_H_
