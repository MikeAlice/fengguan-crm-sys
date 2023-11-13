/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/21 21:50:04

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
#include "ModifySupplierController.h"
#include "service/supplier/updateSupplier/UpdateSupplierService.h"
#include "../../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper ModifySupplierController::execModifySupplier(const ModifySupplierDTO::Wrapper& dto, const PayloadDTO& payload)
{
#if 0
	auto res = Uint64JsonVO::createShared();
	return res;
#else
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->supplierId || dto->supplierId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	UpdateSupplierService service;

	// ִ�������޸�
	if (service.updateSupplierData(dto)) {
		jvo->success(dto->supplierId);
	}
	else
	{
		jvo->fail(dto->supplierId);
	}
	// ��Ӧ���
	return jvo;
#endif
}