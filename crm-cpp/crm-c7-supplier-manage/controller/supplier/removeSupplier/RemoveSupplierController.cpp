/*
 Copyright Zero One Star. All rights reserved.

 @Author: y
 @Date: 2023/10/24 16:26:29

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
#include "RemoveSupplierController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include <list>
#include <service/supplier/removeSupplier/RemoveSupplierService.h>



Uint64JsonVO::Wrapper RemoveSupplierController::execRemoveSupplier(const RemoveSupplierDTO::Wrapper& dto, const PayloadDTO& payload)
{
#if 0
	auto res = Uint64JsonVO::createShared();
	return res;
#else
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	for (oatpp::UInt64 item : *(dto->rows))
	{
		if (!item || item <= 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	// 定义一个Service
	RemoveSupplierService service;
	// 执行数据删除
	if (service.removeSupplierData(dto)) {

		jvo->success(1);
	}
	else
	{
		jvo->fail(2);
	}
	// 响应结果
	return jvo;
#endif
}

