#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/21
 @FileName: CapitalRecordQuery
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
#ifndef _CAPITAL_RECORD_QUERY_
#define _CAPITAL_RECORD_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * �ʽ�ע���ȡ��ѯ����
 */
class CapitalRecordQuery : public oatpp::DTO
{
	DTO_INIT(CapitalRecordQuery, DTO);
	// record_id ����
	API_DTO_FIELD_DEFAULT(UInt64, record_id, ZH_WORDS_GETTER("fin_capital_record.field.record_id"));
	// type ֧������
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("fin_capital_record.field.type"));
	// create_user ������
	API_DTO_FIELD_DEFAULT(String, create_user, ZH_WORDS_GETTER("fin_capital_record.field.create_user"));
	// bank_id �����˻�id
	API_DTO_FIELD_DEFAULT(Int64, bank_id, ZH_WORDS_GETTER("fin_capital_record.field.bank_id"));
	// bank_name ������������
	API_DTO_FIELD_DEFAULT(String, bank_name, ZH_WORDS_GETTER("fin_capital_record.field.bank_name"));
	// bank_card ���п���
	API_DTO_FIELD_DEFAULT(String, bank_card, ZH_WORDS_GETTER("fin_capital_record.field.bank_card"));
	// money ���
	API_DTO_FIELD_DEFAULT(Int64, money, ZH_WORDS_GETTER("fin_capital_record.field.money"));
	// intro ��ע
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("fin_capital_record.field.intro"));
	// create_time ����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("fin_capital_record.field.create_time"));
	// happen_date ��������
	API_DTO_FIELD_DEFAULT(String, happen_date, ZH_WORDS_GETTER("fin_capital_record.field.happen_date"));
	// latest_happen_date
	API_DTO_FIELD_DEFAULT(String, latest_happen_date, ZH_WORDS_GETTER("fin_capital_record.field.latest_happen_date"))
	// latest_create_time
	API_DTO_FIELD_DEFAULT(String, latest_create_time, ZH_WORDS_GETTER("fin_capital_record.field.latest_create_time"))

public:
	
};

#include OATPP_CODEGEN_END(DTO)
#endif