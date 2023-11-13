/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/20 18:38:07

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
#include "stdafx.h"
#include "QuerySupFormItemController.h"
#include "domain/dto/supplier/SupFormItemDTO.h"

SupFormItemJsonVO::Wrapper QuerySupFormItemController::execQuerySupFormItem(const SupFormItemQuery::Wrapper& query)
{
	// 创建返回vo对象
	auto vo = SupFormItemJsonVO::createShared();
	// 创建ListDTO装载数据项
	auto items = SupFormItemListDTO::createShared();
	// 新建数据项
	SupFormItemDTO dto;
	items->addItem(dto.createShared());
	items->addItem(dto.createShared());
	items->addItem(dto.createShared());
	// 返回结果
	vo->success(items);
	return vo;
}
