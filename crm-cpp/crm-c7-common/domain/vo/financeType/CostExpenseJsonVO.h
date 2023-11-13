#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/05 23:30:28

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
#ifndef _COSTEXPENSEJSONVO_H_
#define _COSTEXPENSEJSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/financeType/CostExpenseDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取费用开支类型名称列表JsonVO
 * 负责人: Andrew
 */
class CostExpenseArrayJsonVO : public JsonVO<oatpp::List<CostExpenseDTO::Wrapper>>
{
	DTO_INIT(CostExpenseArrayJsonVO, JsonVO<oatpp::List<CostExpenseDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COSTEXPENSEJSONVO_H_