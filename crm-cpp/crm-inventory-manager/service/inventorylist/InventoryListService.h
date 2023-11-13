#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 弱弟
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
 * 服务实现，演示基础的示例服务实现
 */
class InventoryListService
{
public:
	// 分页查询所有数据
	InventoryListPageDTO::Wrapper listAll(const InventoryListPageQuery::Wrapper& query);
	////新增库存数据			负责人：弱弟
	//uint64_t addInvoice(const AddInventoryListDTO::Wrapper& dto);
	////删除库存数据			负责人：弱弟
	//uint64_t removeData(const oatpp::List<DelInventoryListDTO::Wrapper>& dto);
	//导出库存数据		负责人：弱弟
	std::string exportData(const oatpp::List<ExportInventoryList::Wrapper>& dto);
	// 获取标题			负责人：弱弟
	vector<string> getTitles();
	// 获取excel文件名	负责人：弱弟
	std::string getExcelFileName();
};

#endif // !_INVENTORTLIST_SERVICE_


