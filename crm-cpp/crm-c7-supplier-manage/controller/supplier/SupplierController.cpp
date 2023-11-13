/*
 Copyright Zero One Star. All rights reserved.

 @Author: 锋
 @Date: 2023/10/21 10:58:42

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
#include "SupplierController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/supplier/supplierList/SupplierListService.h"

// 执行查询供应商
SupplierPageJsonVO::Wrapper SupplierController::execQuerySupplier(const SupplierQuery::Wrapper& query)
{
	// 创建返回的JsonVO对象
	auto resJVO = SupplierPageJsonVO::createShared();
	// 数据校验,查询字段允许为空,page信息非空
	if (!query->pageIndex || !query->pageSize) {
		resJVO->init({}, RS_PARAMS_INVALID);
		return resJVO;
	}
	

	// 调用service执行业务
	SupplierListService service;
	auto data = service.listAll(query);

	// 返回结果
	resJVO->success(data);
	return resJVO;
}


// 执行添加供应商
Uint64JsonVO::Wrapper SupplierController::execAddSupplier(const SupplierDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回对象
	auto res = Uint64JsonVO::createShared();

	// 参数校验
	// 1.非空校验
	if (!dto->trade) {
		res->init(UInt64(-1), RS_PARAMS_INVALID);
		return res;
	}

	// 调用service
	SupplierListService service;
	UInt64 id = service.addData(dto);
	if (id > 0) {
		res->success(id);
	}
	else {
		res->fail(id);
	}

	return res;
}




