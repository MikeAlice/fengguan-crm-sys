#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/23 21:36:07

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
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/service/ServiceDO.h"
#include "../../domain/query/service/ServiceQuery.h"
/**
 * 服务记录表数据库操作实现
 */
class ServiceDAO : public BaseDAO
{
public:

	// 插入数据
	uint64_t insert(const ServiceDO& iObj);
	// 修改数据
	int update(const ServiceDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);


};
#endif // !_SAMPLE_DAO_