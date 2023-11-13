/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/20
 @FileName:StorageDetailsController
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

#ifndef STORAGEDETAILSCONTROLLER_H__
#define STORAGEDETAILSCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/storagedetails/StorageDetailsPageJsonVO.h"
#include "domain/query/storagedetails/StorageDetailsQuery.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * StorageDetails控制器：操作入库明细
 */
class StorageDetailsController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(StorageDetailsController);
	// 3 定义接口
public:
	// 分页查询单据 负责人：云隐
	ENDPOINT_INFO(queryStorageDetails) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("storagedetails.controller.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StorageDetailsPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "goods_id", ZH_WORDS_GETTER("storagedetails.field.goods_id"), 14, false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "sku_id", ZH_WORDS_GETTER("storagedetails.field.sku_id"), 28, false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("storagedetails.field.goods_name"), String(ZH_WORDS_GETTER("storagedetails.example.goods_name")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "sku_name", ZH_WORDS_GETTER("storagedetails.field.sku_name"), String(ZH_WORDS_GETTER("storagedetails.example.sku_name")), false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "number", ZH_WORDS_GETTER("storagedetails.field.number"), 5, false);
		API_DEF_ADD_QUERY_PARAMS(String, "category_name", ZH_WORDS_GETTER("storagedetails.field.category_name"), String(ZH_WORDS_GETTER("storagedetails.example.category_name")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "store_name", ZH_WORDS_GETTER("storagedetails.field.store_name"), String(ZH_WORDS_GETTER("storagedetails.example.store_name")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "into_intro", ZH_WORDS_GETTER("storagedetails.field.into_intro"), String(ZH_WORDS_GETTER("storagedetails.example.into_intro")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "into_time", ZH_WORDS_GETTER("storagedetails.field.into_time"), String(ZH_WORDS_GETTER("storagedetails.example.into_time")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "remarks", ZH_WORDS_GETTER("storagedetails.field.remarks"), String(ZH_WORDS_GETTER("storagedetails.example.remarks")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("storagedetails.field.supplier_name"), String(ZH_WORDS_GETTER("storagedetails.example.supplier_name")), false);

		
	}
	ENDPOINT(API_M_GET, "/inventory-manager/query-storage-details", queryStorageDetails, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(storagedetailsQuery, StorageDetailsQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryStorageDetails(storagedetailsQuery, authObject->getPayload()));
	}

	// 导出单据 负责人：云隐
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/inventory-manager/export-storage-details", exportStorageDetails, BODY_DTO(List<ExportStorageDetailsDTO::Wrapper>, dto), execExportStorageDetails(dto, authObject->getPayload()));
	ENDPOINT_INFO(exportStorageDetails) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("storagedetails.controller.export.summary"));	//目录名.controller.方法名.summary
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		
	}
private:
	// 在此添加定义
	StorageDetailsPageJsonVO::Wrapper execQueryStorageDetails(const StorageDetailsQuery::Wrapper storagedetailsQuery, const PayloadDTO& payload);		// 分页查询入库明细 负责人：云隐
	StringJsonVO::Wrapper execExportStorageDetails(const List<ExportStorageDetailsDTO::Wrapper> storagedetailsQuery, const PayloadDTO& payload);		// 导出入库明细		负责人：云隐
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // STORAGEDETAILSCONTROLLER_H__