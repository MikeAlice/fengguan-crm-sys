/*
 Copyright ruodi. All rights reserved.

 @Author: ruodi
 @Date: 2023/10/21
 @FileName:InventoryListController.h
 @version:1.0

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

#ifndef INVENTORTLISTCONTROLLER_H__
#define INVENTORTLISTCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/inventorylist/InventoryListPageJsonVO.h"
#include "domain/query/inventorylist/InventoryListQuery.h"
#include "domain/dto/inventorylist/InventorylistDTO.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * inventorylist控制器：获取库存列表
 */
class InventoryListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(InventoryListController);
	// 3 定义接口
public:
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/inventory-manager/query-inventory-list", queryinventoryList, InventoryListPageQuery, execQueryInventoryList(query, authObject->getPayload()));
	// 分页查询单据 负责人：弱弟
	ENDPOINT_INFO(queryinventoryList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("inventorylist.controller.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(InventoryListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "goods_id", ZH_WORDS_GETTER("inventorylist.field.goods_id"), 14, false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "sku_id", ZH_WORDS_GETTER("inventorylist.field.sku_id"), 28, false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("inventorylist.field.goods_name"), String(ZH_WORDS_GETTER("inventorylist.example.goods_name")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "sku_name", ZH_WORDS_GETTER("inventorylist.field.sku_name"), String(ZH_WORDS_GETTER("inventorylist.example.sku_name")), false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "number", ZH_WORDS_GETTER("inventorylist.field.number"), 5, false);
		API_DEF_ADD_QUERY_PARAMS(String, "category_name", ZH_WORDS_GETTER("inventorylist.field.category_name"), String(ZH_WORDS_GETTER("inventorylist.example.category_name")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "store_name", ZH_WORDS_GETTER("inventorylist.field.store_name"), String(ZH_WORDS_GETTER("inventorylist.example.store_name")), false);

		API_DEF_ADD_QUERY_PARAMS(Float32, "sale_price", ZH_WORDS_GETTER("inventorylist.field.sale_price"), 88.88, false);
		API_DEF_ADD_QUERY_PARAMS(Float32, "cost_price", ZH_WORDS_GETTER("inventorylist.field.cost_price"), 66.66, false);
		API_DEF_ADD_QUERY_PARAMS(Float32, "anticipated_profit", ZH_WORDS_GETTER("inventorylist.field.anticipated_profit"), 99.98, false);
		API_DEF_ADD_QUERY_PARAMS(String, "Original_code", ZH_WORDS_GETTER("inventorylist.field.Original_code"), String(ZH_WORDS_GETTER("inventorylist.example.Original_code")), false);
		//存在问题 报错

	}

	// 导出单据 负责人：弱弟
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/inventory-manager/export-inventory-list", exportInventoryList, BODY_DTO(List<ExportInventoryList::Wrapper>, dto), execExportInventoryList(dto, authObject->getPayload()));
	ENDPOINT_INFO(exportInventoryList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("inventorylist.controller.export.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

	}
private:
	// 在此添加定义
	InventoryListPageJsonVO::Wrapper execQueryInventoryList(const InventoryListPageQuery::Wrapper& inventorylistQuery, const PayloadDTO& payload);		// 分页获取库存列表 负责人：弱弟
	StringJsonVO::Wrapper execExportInventoryList(const List<ExportInventoryList::Wrapper>& inventorylistExport, const PayloadDTO& payload);		// 导出库存列表		负责人：弱弟
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // STORAGEDETAILSCONTROLLER_H__

