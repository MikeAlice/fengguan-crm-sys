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
#ifndef _TRACE_QUERY_
#define _TRACE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class TraceQuery : public PageQuery
{
	DTO_INIT(TraceQuery, PageQuery);

	// 客户名称
	DTO_FIELD(String, AC);
	DTO_FIELD_INFO(AC) {
		info->description = ZH_WORDS_GETTER("trace.field.AC");
	}
	// 联系内容
	DTO_FIELD(String, CContent);
	DTO_FIELD_INFO(CContent) {
		info->description = ZH_WORDS_GETTER("trace.field.CContent");
	}
	// 当前阶段
	DTO_FIELD(Int32, CS);
	DTO_FIELD_INFO(CS) {
		info->description = ZH_WORDS_GETTER("trace.field.CS");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_