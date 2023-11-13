#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/20 20:51:14

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
#ifndef _LISTDTO_H_
#define _LISTDTO_H_

#include "../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 公用列表DTO模板
 * 负责人: Andrew
 */
template <typename T>
class ListDTO : public oatpp::DTO
{
	DTO_INIT(ListDTO, DTO);
	// 数据列表
	API_DTO_FIELD(List<T>, rows, ZH_WORDS_GETTER("common-usage.field.rows"), false, {});
public:
	// 添加一条数据
	void addItem(T item) {
		this->rows->push_back(item);
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LISTDTO_H_