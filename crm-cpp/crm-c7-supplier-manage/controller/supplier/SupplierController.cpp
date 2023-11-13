/*
 Copyright Zero One Star. All rights reserved.

 @Author: ��
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

// ִ�в�ѯ��Ӧ��
SupplierPageJsonVO::Wrapper SupplierController::execQuerySupplier(const SupplierQuery::Wrapper& query)
{
	// �������ص�JsonVO����
	auto resJVO = SupplierPageJsonVO::createShared();
	// ����У��,��ѯ�ֶ�����Ϊ��,page��Ϣ�ǿ�
	if (!query->pageIndex || !query->pageSize) {
		resJVO->init({}, RS_PARAMS_INVALID);
		return resJVO;
	}
	

	// ����serviceִ��ҵ��
	SupplierListService service;
	auto data = service.listAll(query);

	// ���ؽ��
	resJVO->success(data);
	return resJVO;
}


// ִ����ӹ�Ӧ��
Uint64JsonVO::Wrapper SupplierController::execAddSupplier(const SupplierDTO::Wrapper& dto, const PayloadDTO& payload) {
	// ���巵�ض���
	auto res = Uint64JsonVO::createShared();

	// ����У��
	// 1.�ǿ�У��
	if (!dto->trade) {
		res->init(UInt64(-1), RS_PARAMS_INVALID);
		return res;
	}

	// ����service
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




