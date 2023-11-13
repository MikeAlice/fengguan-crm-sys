#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: handeng
 @Date: 2022/10/26

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
#ifndef _OTHER_INCOME_STATEMENT_DTO_
#define _OTHER_INCOME_STATEMENT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class Other_income_statementDTO : public oatpp::DTO
{
	DTO_INIT(Other_income_statementDTO, DTO);
	// ����
	DTO_FIELD(Int32, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.record_id");
	}

	// ��������
	DTO_FIELD(String, type_id);
	DTO_FIELD_INFO(type_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.type_id");
	}

	// ���
	DTO_FIELD(Int32, money);
	DTO_FIELD_INFO(money) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.money");
	}

	// �����˺�
	DTO_FIELD(String, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.bank_id");
	}

	// ��������
	DTO_FIELD(String, happen_date);
	DTO_FIELD_INFO(happen_date) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.happen_date");
	}

	// ������
	DTO_FIELD(String, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.create_user_id");
	}

	// ����ʱ��
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.create_time");
	}
};


/**
 * ɾ���������id
 */
class DelOisDTO : public oatpp::DTO    // OIS ���� other_income_statement����˼����д��һ��
{
	DTO_INIT(DelOisDTO, DTO);
	// record_id
	DTO_FIELD(Int32, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.record_id");
	}
};

/**
 * �����������id
 */
class ExpOisDTO : public oatpp::DTO    // OIS ���� other_income_statement����˼����д��һ��
{
	DTO_INIT(ExpOisDTO, DTO);
	// record_id
	DTO_FIELD(Int32, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("other_income_statement.field.record_id");
	}
};

///**
// * ʾ����ҳ�������
// */
//class Other_income_statementsDTO : public PageDTO<Other_income_statementDTO::Wrapper>
//{
//	DTO_INIT(Other_income_statementsDTO, PageDTO<Other_income_statementDTO::Wrapper>);
//};
//
//#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_