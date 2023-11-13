#pragma once
/*
 Copyright sashuishui. All rights reserved.

 @Author: sashuishui
 @Date: 2023/10/21 12:59:38

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
#ifndef _INCOME_DTO_
#define _INCOME_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Income传输对象
 */
class IncomeDTO : public oatpp::DTO
{
	DTO_INIT(IncomeDTO, DTO);

	// record_id
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.record_id");
	}
	// type_id
	DTO_FIELD(UInt64, type_id);
	DTO_FIELD_INFO(type_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.type_id");
	}
	// bank_id
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.bank_id");
	}
	// money
	DTO_FIELD(Float32, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.money");
	}
	// intro
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.intro");
	}
	// happen_date
	DTO_FIELD(String, happen_date);
	DTO_FIELD_INFO(happen_date) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.happen_date");
	}
	// create_user_id
	DTO_FIELD(UInt64, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.create_user_id");
	}
	// create_time
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.create_time");
	}
};

//示例分页传输对象
 
class IncomePageDTO : public PageDTO<IncomeDTO::Wrapper>
{
	DTO_INIT(IncomePageDTO, PageDTO<IncomeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
