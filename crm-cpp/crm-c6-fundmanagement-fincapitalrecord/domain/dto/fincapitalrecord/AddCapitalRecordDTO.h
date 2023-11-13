#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/21
 @FileName: AddCapitalRecordDTO
 @version: 1.2

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
#ifndef _ADD_CAPITAL_RECORD_DTO_
#define _ADD_CAPITAL_RECORD_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddCapitalRecordDTO : public oatpp::DTO
{
	DTO_INIT(AddCapitalRecordDTO, DTO);
	// type_id 支出类型
	API_DTO_FIELD(UInt64, type_id, ZH_WORDS_GETTER("fin_capital_record.field.type_id"), true, 1);
	// bank 银行账号
	API_DTO_FIELD(UInt64, bank_id, ZH_WORDS_GETTER("fin_capital_record.field.bank_id"), true, 0.0);
	// create_user_id 创建人
	API_DTO_FIELD(Int64, create_user_id, ZH_WORDS_GETTER("fin_capital_record.field.create_user_id"), true, 0.0);
	// money 金额
	API_DTO_FIELD(Int64, money, ZH_WORDS_GETTER("fin_capital_record.field.money"), true, 0.0);
	// happen_date 产生日期
	API_DTO_FIELD(String, happen_date, ZH_WORDS_GETTER("fin_capital_record.field.happen_date"),true, "");
	// intro 备注
	API_DTO_FIELD(String, intro, ZH_WORDS_GETTER("fin_capital_record.field.intro"), true, "");
	
public:

};

#include OATPP_CODEGEN_END(DTO)
#endif