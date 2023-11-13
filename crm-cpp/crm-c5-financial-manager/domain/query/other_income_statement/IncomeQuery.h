/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/22
 @FileName:IncomeQuery
 @version:1.0
 
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

#ifndef INCOMEQUERY_H__
#define INCOMEQUERY_H__
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Income
 */
class IncomePageQuery : public PageQuery
{
	DTO_INIT(IncomePageQuery, PageQuery);
	
	// record_id
	DTO_FIELD(Int16, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.record_id");
	}
	// type_id
	DTO_FIELD(Int16, type_id);
	DTO_FIELD_INFO(type_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.type_id");
	}
	// bank_id
	DTO_FIELD(Int16, bank_id);
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
	DTO_FIELD(Int16, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.create_user_id");
	}
	// create_time
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.create_time");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // INCOMEQUERY_H__