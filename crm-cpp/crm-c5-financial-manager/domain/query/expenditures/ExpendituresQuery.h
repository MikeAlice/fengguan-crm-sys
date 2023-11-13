/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/20
 @FileName:ExpendituresQuery
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

#ifndef EXPENDITURESQUERY_H__
#define EXPENDITURESQUERY_H__
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * expenditures查询对象
 */
class ExpendituresQuery : public oatpp::DTO
{
	DTO_INIT(ExpendituresQuery, DTO);
	// type_
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("expenditures.field.type");
	}
	// money
	DTO_FIELD(Int32, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("expenditures.field.money");
	}
	// bank
	DTO_FIELD(String, bank);
	DTO_FIELD_INFO(bank) {
		info->description = ZH_WORDS_GETTER("expenditures.field.bank");
	}
	// latest_happen_date
	DTO_FIELD(String, latest_happen_date);
	DTO_FIELD_INFO(latest_happen_date) {
		info->description = ZH_WORDS_GETTER("expenditures.field.latest_happen_date");
	}
	// create_user
	DTO_FIELD(String, create_user);
	DTO_FIELD_INFO(create_user) {
		info->description = ZH_WORDS_GETTER("expenditures.field.create_user");
	}
	// latest_create_time
	DTO_FIELD(String, latest_create_time);
	DTO_FIELD_INFO(latest_create_time) {
		info->description = ZH_WORDS_GETTER("expenditures.field.latest_create_time");
	}
	// intro
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("expenditures.field.intro");
	}
};

/**
 * expendituresPage查询对象
 */
class ExpendituresPageQuery :public PageQuery 
{
	DTO_INIT(ExpendituresPageQuery, PageQuery);

	// type_
	DTO_FIELD(Int32, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("expenditures.field.type");
	}
	// money
	DTO_FIELD(Int32, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("expenditures.field.money");
	}
	// bank
	DTO_FIELD(String, bank);
	DTO_FIELD_INFO(bank) {
		info->description = ZH_WORDS_GETTER("expenditures.field.bank");
	}
	// latest_happen_date
	DTO_FIELD(Int32, latest_happen_date);
	DTO_FIELD_INFO(latest_happen_date) {
		info->description = ZH_WORDS_GETTER("expenditures.field.latest_happen_date");
	}
	// create_user
	DTO_FIELD(String, create_user);
	DTO_FIELD_INFO(create_user) {
		info->description = ZH_WORDS_GETTER("expenditures.field.create_user");
	}
	// latest_create_time
	DTO_FIELD(Int32, latest_create_time);
	DTO_FIELD_INFO(latest_create_time) {
		info->description = ZH_WORDS_GETTER("expenditures.field.latest_create_time");
	}
	// intro
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("expenditures.field.intro");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // EXPENDITURESQUERY_H__