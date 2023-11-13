#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/06 17:41:47

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
#ifndef _DATADICTDTO_H_
#define _DATADICTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取指定字典分类对应字典列表DTO
 * 负责人: Andrew
 */
class DataDictDTO : public oatpp::DTO
{
	DTO_INIT(DataDictDTO, DTO);
	API_DTO_FIELD_DEFAULT(Int32, id, ZH_WORDS_GETTER("common-usage.field.id"));
	API_DTO_FIELD_DEFAULT(String, typeName, ZH_WORDS_GETTER("data-dict.dict-type.field.typeName"));
	API_DTO_FIELD_DEFAULT(String, typetag, ZH_WORDS_GETTER("data-dict.dict-type.field.typeTag"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DATADICTDTO_H_