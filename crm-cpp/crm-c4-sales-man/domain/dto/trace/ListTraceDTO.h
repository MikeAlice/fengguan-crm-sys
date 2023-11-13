#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _LISTTRACEDTO_H_
#define _LISTTRACEDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个追踪记录的数据传输模型
 */
class ListTraceDTO : public oatpp::DTO
{
	DTO_INIT(ListTraceDTO, DTO);
	// 编号
	API_DTO_FIELD_DEFAULT(Vector<UInt64>, listtrace_id, ZH_WORDS_GETTER("trace.field.list_id"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_LISTTRACEDTO_H_