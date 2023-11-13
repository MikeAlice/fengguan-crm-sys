#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2023/10/24 11:08:56

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
#ifndef _INVENTORTLIST_SERVICE_
#define _INVENTORTLIST_SERVICE_
#include <list>
#include "domain/vo/inventorylist/InventoryListPageJsonVO.h"
#include "domain/query/inventorylist/InventoryListQuery.h"
#pragma once
#include "domain/dto/inventorylist/InventorylistDTO.h"

/**
 * ����ʵ�֣���ʾ������ʾ������ʵ��
 */
class InventoryListService
{
public:
	// ��ҳ��ѯ��������
	InventoryListPageDTO::Wrapper listAll(const InventoryListPageQuery::Wrapper& query);
	////�����������			�����ˣ�����
	//uint64_t addInvoice(const AddInventoryListDTO::Wrapper& dto);
	////ɾ���������			�����ˣ�����
	//uint64_t removeData(const oatpp::List<DelInventoryListDTO::Wrapper>& dto);
	//�����������		�����ˣ�����
	std::string exportData(const oatpp::List<ExportInventoryList::Wrapper>& dto);
	// ��ȡ����			�����ˣ�����
	vector<string> getTitles();
	// ��ȡexcel�ļ���	�����ˣ�����
	std::string getExcelFileName();
};

#endif // !_INVENTORTLIST_SERVICE_


