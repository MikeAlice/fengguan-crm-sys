#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/08 23:09:54

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
#ifndef _COSTEXPENSEDTO_H_
#define _COSTEXPENSEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CostExpenseDTO : public oatpp::DTO
{
	DTO_INIT(CostExpenseDTO, DTO);
	API_DTO_FIELD_DEFAULT(UInt32, id, ZH_WORDS_GETTER("finance-type.cost-expense.field.id"));
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("finance-type.cost-expense.field.name"));
	API_DTO_FIELD_DEFAULT(UInt32, parentid, ZH_WORDS_GETTER("finance-type.cost-expense.field.parent-id"));
	API_DTO_FIELD_DEFAULT(UInt32, sort, ZH_WORDS_GETTER("finance-type.cost-expense.field.sort"));
	API_DTO_FIELD_DEFAULT(UInt32, visible, ZH_WORDS_GETTER("finance-type.cost-expense.field.visible"));
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("finance-type.cost-expense.field.intro"));
	API_DTO_FIELD(List<CostExpenseDTO::Wrapper>, children, ZH_WORDS_GETTER("finance-type.cost-expense.field.children"), false, List<CostExpenseDTO::Wrapper>::createShared());
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COSTEXPENSEDTO_H_