#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Juno
 @Date: 2023/10/21 22:27:04

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
#ifndef _SUPPLIER_NAME_QUERY_
#define _SUPPLIER_NAME_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取供应商名称列表接口Query
 * 负责人: Juno
 */
class SupplierNameQuery : public oatpp::DTO
{
	DTO_INIT(SupplierNameQuery, DTO);
	// 供应商名称关键字
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_