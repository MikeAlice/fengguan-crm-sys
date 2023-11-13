/*
 Copyright Zero One Star. All rights reserved.

 @Author: telephone
 @Date: 2023/10/23 18:20:31

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
#include "SupplierLinkmanController.h"
#include "service/supplierLinkman/saveSupLinkman/SaveSupLinkmanService.h"
#include "service/supplierLinkman/listSupLinkman/ListSupLinkmanService.h"

SupplierLinkmanPageJsonVO::Wrapper SupplierLinkmanController::execQuerySupplierLinkman(const SupplierLinkmanQuery::Wrapper& query)
{
	// 构建返回对象
	auto result = SupplierLinkmanPageJsonVO::createShared();
	
	// 参数校验
	// 非空校验
	if (!query->pageIndex || !query->pageSize)
	{
		result->init({}, RS_PARAMS_INVALID);
		return result;
	}
	// 有效值校验
	if (query->pageIndex <= 0 || query->pageSize <= 0)
	{
		result->init({}, RS_PARAMS_INVALID);
		return result;
	}

	// 调用业务逻辑层执行查询
	ListSupLinkmanService service;
	auto data = service.listAll(query);

	// 返回结果
	result->success(data);
	return result;
}

Uint64JsonVO::Wrapper SupplierLinkmanController::execAddSupplierLinkman(const AddSupplierLinkmanDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 构建返回对象
	auto jvo = Uint64JsonVO::createShared();

	// 数据校验
	// 非空校验
	if (!dto->name || !dto->supplier_id || !dto->gender)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->gender.getValue({}) != 0 && dto->gender.getValue({}) != 1 || dto->supplier_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	SaveSupLinkmanService service;
	uint64_t res = service.saveSupLinkman(dto, payload);

	if (res > 0)
		jvo->success(res);
	else
		jvo->fail(-1);
	return jvo;
}