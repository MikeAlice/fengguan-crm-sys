#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/25 16:28:07

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
#ifndef _LISTSUPFORMITEMSERVICE_H_
#define _LISTSUPFORMITEMSERVICE_H_

#include <list>
#include "domain/dto/supplier/SupFormItemDTO.h"
#include "domain/query/supplier/SupFormItemQuery.h"

/**
 * 获取供应商基础信息表单数据项Service
 * 负责人: Andrew
 */
class ListSupFormItemService
{
public:
	SupFormItemListDTO::Wrapper listAll(const SupFormItemQuery::Wrapper& query);
};

#endif // !_LISTSUPFORMITEMSERVICE_H_