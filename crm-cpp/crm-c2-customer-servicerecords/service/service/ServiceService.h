#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/23 22:37:13

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
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/dto/service/ServiceBaseDTO.h"
#include "domain/dto/service/ServiceDetailDTO.h"
#include "domain//query/service/ServiceQuery.h"
#include "SimpleDateTimeFormat.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ServiceService
{
public:
	// 保存数据
	uint64_t saveData(const ServiceBaseDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改数据
	bool updateData(const ServiceModifyDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
	// 设定创建者id和创建时间
	bool updateCreater(string time, int id);


};

#endif // !_SAMPLE_SERVICE_