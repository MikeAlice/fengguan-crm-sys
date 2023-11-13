#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/25
 @FileName: ExportCapitalRecordQuery
 @version: 1.0

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
#ifndef _EXPORT_CAPITAL_RECORD_QUERY_
#define _EXPORT_CAPITAL_RECORD_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 导出数据对象
*/
class ExportCapitalRecordQuery : public PageQuery
{
	DTO_INIT(ExportCapitalRecordQuery, PageQuery);
	// type_id 支出类型
	API_DTO_FIELD_DEFAULT(Int64, type_id, ZH_WORDS_GETTER("payment.field.type_id"));
	// create_user_id 创建人
	API_DTO_FIELD_DEFAULT(Int64, create_user_id, ZH_WORDS_GETTER("payment.field.create_user_id"));
	// bank 银行账号
	API_DTO_FIELD_DEFAULT(UInt64, bank_id, ZH_WORDS_GETTER("payment.field.bank_id"));
	// money 金额
	API_DTO_FIELD_DEFAULT(Int64, money, ZH_WORDS_GETTER("payment.field.money"));
	// intro 备注
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("payment.field.intro"));
	// create_time 创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("payment.field.create_time"));
	// happen_date 产生日期
	API_DTO_FIELD_DEFAULT(String, happen_date, ZH_WORDS_GETTER("payment.field.happen_date"));

public:
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORT_CAPITAL_RECORD_QUERY_

