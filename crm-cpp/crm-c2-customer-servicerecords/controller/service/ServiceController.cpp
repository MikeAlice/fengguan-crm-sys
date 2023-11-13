/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/24 13:44:08

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
#include "ServiceController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/service/ServiceService.h"


//添加服务记录
Uint64JsonVO::Wrapper ServiceAddRemoveModifyController::execAddServices(const ServiceBaseDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->customer_id || !dto->linkman_id || !dto->services || 
		!dto->servicesmodel|| !dto->price || !dto->status ||
		!dto->tlen )
	{
		jvo->init(UInt64(-1), RS_PARAMS_EMPTY);
		return jvo;
	}
	
	//cout << dto->tlen->empty() << !dto->status << endl;
	// 有效值校验
	if (dto->services < 0 || (dto->status < 1 || dto->status > 4))
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	ServiceService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}
//批量删除服务记录
Uint64JsonVO::Wrapper ServiceAddRemoveModifyController::execRemoveServices(const ServiceIdListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	ServiceService service;
	auto jvo = Uint64JsonVO::createShared();
	Vector<UInt64> arr = dto->service_id_s;
	for (int i = 0; i < arr->size(); i++) {
		// 定义返回数据对象
		
		// 参数校验
		if (!arr[i] || arr[i] <= 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		
		// 执行数据删除
		if (service.removeData(arr[i].getValue(0))) {
			jvo->success(arr[i]);
		}
		else
		{
			jvo->fail(arr[i]);
			return jvo;
		}
		// 响应结果
	}
	
	return jvo;
}
//修改服务记录
Uint64JsonVO::Wrapper ServiceAddRemoveModifyController::execModifyServices(const ServiceModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->service_id || dto->service_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//对传入参数进行有效性验证
	if (dto->services && dto->services < 0) {
		jvo->init(UInt64(-1), RS_PARAMS_SELECTABLE_ERROR);
		return jvo;
	}
	if (dto->status && (dto->status < 1 || dto->status > 4)) {
		jvo->init(UInt64(-1), RS_PARAMS_SELECTABLE_ERROR);
		return jvo;
	}
	// 定义一个Service
	ServiceService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->service_id);
	}
	else
	{
		jvo->fail(dto->service_id);
	}
	// 响应结果
	return jvo;
}

