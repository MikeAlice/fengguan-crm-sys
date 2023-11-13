/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/21 21:58:42

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
#include "QuerySupplierNameController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "service/supplier/listSupplierName/ListSupplierNameService.h"

SupplierNameJsonVO::Wrapper SupplierNameController::execQuerySupplierName(const SupplierNameQuery::Wrapper& query)
{
#if 0
	// ��Ӧ���
	auto res = SupplierNameJsonVO::createShared();
	auto data = SupplierNameListDTO::createShared();
	SupplierNameDTO dto;
	data->addItem(dto.createShared());
	res->success(data);
	return res;
#else
	// ��������vo����
	auto jvo = SupplierNameJsonVO::createShared();
	// ����У��
	// �ǿ�У��
#if 0
	if (!query->name)
	{
		jvo->init({}, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (query->name->empty())
	{
		jvo->init({}, RS_PARAMS_INVALID);
		return jvo;
	}
#endif

	// ����serviceִ��ҵ��
	ListSupplierNameService service;
	auto res = service.listAll(query);

	// ���ؽ��
	jvo->success(res);
	return jvo;
#endif
}



