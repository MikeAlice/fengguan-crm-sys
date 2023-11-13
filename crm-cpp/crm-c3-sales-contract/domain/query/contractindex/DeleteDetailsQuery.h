#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _DELETEDETAILS_QUERY_
#define _DELETEDETAILS_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class DeleteDetailsQuery : public PageQuery
{
	DTO_INIT(DeleteDetailsQuery, PageQuery);
	// 订单项ID
	DTO_FIELD(UInt64, list_id);
	DTO_FIELD_INFO(list_id) {
		info->description = ZH_WORDS_GETTER("contractindex.field.list_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETEDETAILS_QUERY_