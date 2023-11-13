#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huipaodeyu
 @Date: 2023/10/25 10:36:07

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
#ifndef _SERVICENOTE_SERVICE_
#define _SERVICENOTE_SERVICE_
#include <list>
#include "domain/dto/service/ServiceListDTO.h"
#include "domain/dto/service/ServiceBaseDTO.h"
#include "domain/dto/service/ServiceDetailDTO.h"
#include "domain//query/service/ServiceQuery.h"
/**
 * 服务实现，演示基础的示例服务实现
 */
class ServiceNoteService
{
public:
	
	// 分页查询所有数据
	ServiceNotePageDTO::Wrapper listAll(const ServiceQuery::Wrapper& query);
};

#endif // !_SERVICENOTE_SERVICE_

