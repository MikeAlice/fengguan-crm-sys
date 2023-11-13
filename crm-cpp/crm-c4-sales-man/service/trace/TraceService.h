#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _TRACE_SERVICE_
#define _TRACE_SERVICE_
#include "domain/vo/trace/GetPageVO.h"
#include "domain/query/trace/TraceQuery.h"
#include "domain/dto/trace/TraceDTO.h"
#include "domain/dto/trace/AddTraceDTO.h"
#include "domain/dto/trace/ModifyTraceDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class TraceService
{
public:
	// 分页查询所有数据
	TracePageDTO::Wrapper listAll(const TraceQuery::Wrapper& query);
	// 保存数据
	bool saveData(const AddTraceDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const ModifyTraceDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t trace_id);
	// 导出跟踪记录文件
	//oatpp::String exportTracefile(const TraceDTO::Wrapper& dto);
	oatpp::String exportTracefile();
};

#endif // !_SAMPLE_SERVICE_

