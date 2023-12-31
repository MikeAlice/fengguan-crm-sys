#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/30 10:27:38

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
#ifndef _GETCUSTOMERNAME_SERVICE_
#define _GETCUSTOMERNAME_SERVICE_
#include <list>
#include "domain/vo/contact/NameContactVO.h"
#include "domain/query/contact/ListContectNameQuery.h"
#include "domain/dto/contact/NameContactDTO.h"
#include "dao/selectcontactname/SelectContactNameDAO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ListContactNameService
{
public:
	// 分页查询所有数据
	NameContactJsonVO::Wrapper getName(const ListContactNameQuery::Wrapper& query);

};

#endif // !_GETCUSTOMERNAME_SERVICE_
