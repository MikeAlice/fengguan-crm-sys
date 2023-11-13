/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/19
 @FileName:ExpendituresDTO
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

#ifndef EXPENDITURESDTO_H__
#define EXPENDITURESDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Expenditures传输对象
 */
class ExpendituresDTO : public oatpp::DTO
{
	DTO_INIT(ExpendituresDTO, DTO);
	// record_id
	DTO_FIELD(Int32, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("expenditures.field.record_id");
	}
	// type_
	DTO_FIELD(String, type_);
	DTO_FIELD_INFO(type_) {
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
	// happen_date
	DTO_FIELD(String, happen_date);
	DTO_FIELD_INFO(happen_date) {
		info->description = ZH_WORDS_GETTER("expenditures.field.happen_date");
	}
	// create_user
	DTO_FIELD(String, create_user);
	DTO_FIELD_INFO(create_user) {
		info->description = ZH_WORDS_GETTER("expenditures.field.create_user");
	}
	// create_time
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("expenditures.field.create_time");
	}
	// intro
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("expenditures.field.intro");
	}
};

/**
 * DelExpenditures传输对象
 */
class DelExpendituresDTO : public oatpp::DTO
{
	DTO_INIT(DelExpendituresDTO, DTO);
	// record_id
	DTO_FIELD(Int32, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("expenditures.field.record_id");
	}
};

/**
 * ExportExpenditures传输对象
 */
class ExportExpenditures : public oatpp::DTO
{
	DTO_INIT(ExportExpenditures, DTO);
	// record_id
	DTO_FIELD(Int32, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("expenditures.field.record_id");
	}
};
/**
 * AddExpenditures传输对象
 */
class AddExpendituresDTO : public oatpp::DTO
{
	DTO_INIT(AddExpendituresDTO, DTO);
		// record_id
	DTO_FIELD(Int32, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("expenditures.field.record_id");
	}
	// type_
	DTO_FIELD(Int32, type_);
	DTO_FIELD_INFO(type_) {
		info->description = ZH_WORDS_GETTER("expenditures.field.type");
	}
	// happen_date
	DTO_FIELD(String, happen_date);
	DTO_FIELD_INFO(happen_date) {
		info->description = ZH_WORDS_GETTER("expenditures.field.happen_date");
	}
	// money
	DTO_FIELD(Int32, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("expenditures.field.money");
	}
	// bank
	DTO_FIELD(Int32, bank);
	DTO_FIELD_INFO(bank) {
		info->description = ZH_WORDS_GETTER("expenditures.field.bank");
	}
	// intro
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("expenditures.field.intro");
	}
	// 创建者
	DTO_FIELD(Int32, create_user);
	DTO_FIELD_INFO(create_user) {
		info->description = ZH_WORDS_GETTER("expenditures.field.create_user");
	}
	// create_time
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("expenditures.field.create_time");
	}

};
/**
 * ExpendituresPgae传输对象
 */
class ExpendituresPageDTO : public PageDTO<ExpendituresDTO::Wrapper>
{
	DTO_INIT(ExpendituresPageDTO, PageDTO<ExpendituresDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // EXPENDITURESDTO_H__