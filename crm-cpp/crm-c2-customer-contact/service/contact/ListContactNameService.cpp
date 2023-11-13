/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/30 11:00:32

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
#include "ListContactNameService.h"



NameContactJsonVO::Wrapper ListContactNameService::getName(const ListContactNameQuery::Wrapper& query)
{
	std::string name = "";
	if (query->name) {
		name = query->name;
	}
	// 构建返回对象
	auto vo = NameContactJsonVO::createShared();

	SelectContactNameDAO dao;
	// 通过name查询数据
	list<ContactListDO> result = dao.selectByName(name,query);
	// 将DO转换成DTO
	for (ContactListDO sub : result)
	{
		auto dto = GetContactNameDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, linkman_name, Name, linkman_id, Linkman_id)
			vo->data->push_back(dto);
	}
#ifndef LINUX
	if (vo->data->size() == 0) {
		vo->message = u8"查询结果为空";
	}
	else {
		vo->message = u8"查询结果不为空";
	}
#else
	if (vo->data->size() == 0) {
		vo->message = "The query result is empty";
	}
	else {
		vo->message = "The query result is not empty";
	}
#endif

	
	return vo;
}