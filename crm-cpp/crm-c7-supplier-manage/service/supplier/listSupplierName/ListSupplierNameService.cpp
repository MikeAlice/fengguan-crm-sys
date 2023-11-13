/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/26 20:28:07

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
#include "ListSupplierNameService.h"
#include "dao/supplier/selectSupplierName/SelectSupplierNameDAO.h"
#include "domain/do/cstFieldExt/CstFieldExtDO.h"

SupplierNameListDTO::Wrapper ListSupplierNameService::listAll(const SupplierNameQuery::Wrapper& query)
{
	// �������ض���
	auto datas = SupplierNameListDTO::createShared();

	// ���ݸ�DAO, ���ò�ѯ
	SelectSupplierNameDAO dao;
	list<SupplierDO> result = dao.selectSupplierName(query);

	// ��DOת����DTO
	for (SupplierDO sub : result)
	{
		auto dto = SupplierNameDTO::createShared();
		// 		dto->name = sub.getSupplierName();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, supplierName, Name, supplierId, SupplierId)
		datas->addItem(dto);
	}

	// ���ؽ��
	return datas;

#if 0
	// �������ض���
	auto pages = SamplePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	SampleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<SampleDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (SampleDO sub : result)
	{
		auto dto = SampleDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
			pages->addData(dto);

	}
	return pages;
#endif
}
