/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/01 0:13:41

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
#include "ListSupLinkmanService.h"
#include "dao/supplierLinkman/selectSupLinkman/SelectSupLinkmanDAO.h"
#include "uselib/redis/UseRedis.h"

SupplierLinkmanPageDTO::Wrapper ListSupLinkmanService::listAll(const SupplierLinkmanQuery::Wrapper& query)
{
	// 构建返回对象
	auto res = SupplierLinkmanPageDTO::createShared();
	res->pageIndex = query->pageIndex;
	res->pageSize = query->pageSize;

	// 调用数据持久化层执行查询
	SelectSupLinkmanDAO dao;
	res->total = dao.count(query);
	if (res->total.getValue({}) <= 0)
		return res;
	res->calcPages();

	// 执行查询
	// 从Redis获取扩展字段缓存
	UseRedis ur;
	auto tmp = ur.list_getter<std::string>(redis_title);
	std::list<std::string> fields;
	// 为空则查询数据库
	if (tmp.empty())
	{
		fields = dao.selectExtField();
		// 缓存Redis
		std::vector<std::string> vec(fields.begin(), fields.end());
		if (ur.list_setter<std::string>(redis_title, vec))
			std::cout << redis_title << " has being cached to Redis" << std::endl;
		else
			std::cout << "failed to cache " << redis_title << std::endl;
	}
	else
		fields = std::list<std::string>(tmp.begin(), tmp.end());
	std::list<SupplierLinkmanDO> data = dao.selectAll(query, fields);
	// DO转DTO
	for (auto item : data)
	{
		auto dto = SupplierLinkmanDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, item, linkman_id, LinkmanId, supplier_id, SupplierId, supplier_name, SupplierName, name, Name, gender, Gender, position, Position, tel, Tel, mobile, Mobile, qicq, Qicq, email, Email, zipcode, Zipcode, address, Address, intro, Intro, create_time, CreateTime, create_user_id, CreateUserId);
		// 扩展字段
		for (auto ext : item.getExtFields())
			dto->ext_fields->push_back(ext);
		res->addData(dto);
	}
	return res;
}
