/*
 Copyright Zero One Star. All rights reserved.

 @Author: 锋
 @Date: 2023/10/27 14:41:45

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
#include "SupplierListService.h"
#include "../../../domain/do/supplier/SupplierDO.h"
#include "../../../dao/supplier/supplierList/SupplierListDAO.h"

SupplierPageDTO::Wrapper SupplierListService::listAll(const SupplierQuery::Wrapper& query) {
	// 构建返回对象
	auto resPage = SupplierPageDTO::createShared();
	resPage->pageIndex = query->pageIndex;
	resPage->pageSize = query->pageSize;

	// 调用DAO层查询数据总条数
	SupplierListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return resPage;
	}

	// 分页查询数据
	resPage->total = count;
	resPage->calcPages();
	list<SupplierDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (SupplierDO supdo : result)
	{
		auto dto = SupplierDTO::createShared();
		
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, supdo, supplier_id, SupplierId, name, Name, area_id, AreaId, create_user_id, CreateUserId, level, Level, ecotype, Ecotype, trade, Trade, satisfy, Satisfy, credit, Credit, address, Address, linkman, Linkman, website, Website, zipcode, Zipcode, tel, Tel, fax, Fax, email, Email, intro, Intro, create_time, CreateTime, linkman_name, LinkmanName)
		auto ext = supdo.getExtFields();
		for (auto item : ext) {
			dto->ext_fields[item.first] = item.second;
		}
		resPage->addData(dto);

	}
	return resPage;
}
uint64_t SupplierListService::addData(const SupplierDTO::Wrapper& dto) {
	// 组装DO数据
	SupplierDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Ecotype, ecotype, Trade, trade, Linkman, linkman, Tel, tel, Fax, fax, Email, email, Address, address, Intro, intro)
	// 调用DAO层执行数据添加
	SupplierListDAO dao;
	return dao.insert(data);
}