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
	// 构建返回对象
	auto datas = SupplierNameListDTO::createShared();

	// 传递给DAO, 调用查询
	SelectSupplierNameDAO dao;
	list<SupplierDO> result = dao.selectSupplierName(query);

	// 将DO转换成DTO
	for (SupplierDO sub : result)
	{
		auto dto = SupplierNameDTO::createShared();
		// 		dto->name = sub.getSupplierName();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, supplierName, Name, supplierId, SupplierId)
		datas->addItem(dto);
	}

	// 返回结果
	return datas;

#if 0
	// 构建返回对象
	auto pages = SamplePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	SampleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<SampleDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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
