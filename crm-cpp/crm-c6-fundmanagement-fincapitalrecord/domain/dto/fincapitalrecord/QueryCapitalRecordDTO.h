#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/21
 @FileName: QueryCapitalRecordDTO
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
#ifndef _QUERY_CAPITAL_RECORD_DTO_
#define _QUERY_CAPITAL_RECORD_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class QueryCapitalRecordDTO : public oatpp::DTO
{
	DTO_INIT(QueryCapitalRecordDTO, DTO);
	// record_id 单号
	API_DTO_FIELD_DEFAULT(UInt64, record_id, ZH_WORDS_GETTER("fin_capital_record.field.record_id"));
	// type支出类型
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("fin_capital_record.field.type"));
	// money 金额
	API_DTO_FIELD_DEFAULT(Int64, money, ZH_WORDS_GETTER("fin_capital_record.field.money"));
	// bank_id 银行账户id
	API_DTO_FIELD_DEFAULT(UInt64, bank_id, ZH_WORDS_GETTER("fin_capital_record.field.bank_id"));
	// bank_name 开户银行名称
	API_DTO_FIELD_DEFAULT(String, bank_name, ZH_WORDS_GETTER("fin_capital_record.field.bank_name"));
	// bank_card 银行卡号
	API_DTO_FIELD_DEFAULT(String, bank_card, ZH_WORDS_GETTER("fin_capital_record.field.bank_card"));
	// happen_date 产生日期
	API_DTO_FIELD_DEFAULT(String, happen_date, ZH_WORDS_GETTER("fin_capital_record.field.happen_date"));
	// create_user 创建人
	API_DTO_FIELD_DEFAULT(String, create_user, ZH_WORDS_GETTER("fin_capital_record.field.create_user"));
	// create_time 创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("fin_capital_record.field.create_time"));
	// intro 备注
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("fin_capital_record.field.intro"));

public:

};

#include OATPP_CODEGEN_END(DTO)

#endif