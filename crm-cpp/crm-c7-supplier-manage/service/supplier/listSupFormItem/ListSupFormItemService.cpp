/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/25 16:28:07

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
#include "ListSupFormItemService.h"
#include "dao/supplier/selectSupFormItem/SelectSupFormItemDAO.h"
#include "domain/do/cstFieldExt/CstFieldExtDO.h"

SupFormItemListDTO::Wrapper ListSupFormItemService::listAll(const SupFormItemQuery::Wrapper& query)
{
	// �������ض���
	auto datas = SupFormItemListDTO::createShared();

	// ������ݱ�����Ϊ`sup_linkman`ֱ�ӷ���
	if (query->ext_table != "sup_supplier" || query->main_table != "sup_supplier")
		return datas;

	// ���ݸ�DAO, ���ò�ѯ
	SelectSupFormItemDAO dao;
	std::list<CstFieldExtDO> res = dao.selectSupFormItem(query);
	// DOתDTO
	for (CstFieldExtDO item : res)
	{
		auto dto = SupFormItemDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, item, show_name, ShowName, field_name, FieldName, field_type, FieldType, default_val, DefaultValue, is_must, IsMust);
		datas->addItem(dto);
	}
	// ���ؽ��
	return datas;
}
