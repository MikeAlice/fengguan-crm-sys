#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/20 19:57:27

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
#ifndef _SUPFORMITEMDTO_H_
#define _SUPFORMITEMDTO_H_

#include "../../GlobalInclude.h"
#include "../ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ӧ�̱�������DTO
 * ������: Andrew
 */
class SupFormItemDTO : public oatpp::DTO
{
	DTO_INIT(SupFormItemDTO, DTO);
	// �ֶα�����
	API_DTO_FIELD_DEFAULT(String, show_name, ZH_WORDS_GETTER("supplier.query-sup-form-item.field.show-name"));
	// �ֶ�����
	API_DTO_FIELD_DEFAULT(String, field_name, ZH_WORDS_GETTER("supplier.query-sup-form-item.field.field-name"));
	// �ֶ�����
	API_DTO_FIELD_DEFAULT(String, field_type, ZH_WORDS_GETTER("supplier.query-sup-form-item.field.field-type"));
	// Ĭ��ֵ
	API_DTO_FIELD_DEFAULT(String, default_val, ZH_WORDS_GETTER("supplier.query-sup-form-item.field.default"));
	// �Ƿ����
	API_DTO_FIELD_DEFAULT(Boolean, is_must, ZH_WORDS_GETTER("supplier.query-sup-form-item.field.is-must"));
public:
	SupFormItemDTO()
	{
		show_name = u8"΢��";
		field_name = "wechat";
		field_type = "varchar";
		default_val = u8"΢�ź�";
		is_must = true;
	}
};

/**
 * ��Ӧ�̱��������б�DTO
 * ������: Andrew
 */
class SupFormItemListDTO : public ListDTO<SupFormItemDTO::Wrapper>
{
	DTO_INIT(SupFormItemListDTO, ListDTO<SupFormItemDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SUPFORMITEMDTO_H_