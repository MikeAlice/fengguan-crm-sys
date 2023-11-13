#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2023/10/23 17:20:26

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
#ifndef _BASICDATADTO_H_
#define _BASICDATADTO_H_

#include "../../GlobalInclude.h"
#include "../ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class BasicDataDTO : public oatpp::DTO
{
	DTO_INIT(BasicDataDTO, DTO)
	// 字段表单名称
	API_DTO_FIELD_DEFAULT(String, show_name, ZH_WORDS_GETTER("supplier-linkman.basic-data.field.show-name"))
	// 字段名称
	API_DTO_FIELD_DEFAULT(String, field_name, ZH_WORDS_GETTER("supplier-linkman.basic-data.field.field-name"))
	// 字段类型
	API_DTO_FIELD_DEFAULT(String, field_type, ZH_WORDS_GETTER("supplier-linkman.basic-data.field.field-type"))
	// 默认值
	API_DTO_FIELD_DEFAULT(String, default_value, ZH_WORDS_GETTER("supplier-linkman.basic-data.field.default"))
	// 是否必填
	API_DTO_FIELD_DEFAULT(Boolean, is_must, ZH_WORDS_GETTER("supplier-linkman.basic-data.field.is-must"))
public:
	BasicDataDTO()
	{
		show_name = "qq";
		field_name = u8"企鹅";
		field_type = "varchar";
		default_value = u8"qq号码";
		is_must = true;
	}
};

class BasicDataListDTO : public ListDTO<BasicDataDTO::Wrapper>
{
	DTO_INIT(BasicDataListDTO, ListDTO<BasicDataDTO::Wrapper>)
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_BASICDATADTO_H_