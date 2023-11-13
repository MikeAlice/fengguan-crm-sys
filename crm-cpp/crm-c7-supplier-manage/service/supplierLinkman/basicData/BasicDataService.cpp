/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2023/10/25 14:00:18

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
#include "BasicDataService.h"
#include "dao/supplierLinkman/basicData/BasicDataDAO.h"

BasicDataListDTO::Wrapper BasicDataService::listAll()
{
	// 构建返回对象
	auto result = BasicDataListDTO::createShared();

	// 调用DAO层
	BasicDataDAO dao;
	list<CstFieldExtDO> listDO = dao.selectAll();

	// 将DO转换为DTO
	for (CstFieldExtDO DO : listDO)
	{
		auto dto = BasicDataDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, DO, show_name, ShowName, field_name, FieldName, field_type, FieldType, default_value, DefaultValue, is_must, IsMust);
		result->addItem(dto);
	}
	return result;
}