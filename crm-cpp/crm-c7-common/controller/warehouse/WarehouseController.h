#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2023/10/31 17:56:05

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
#ifndef _WAREHOUSE_H_
#define _WAREHOUSE_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "../../domain/dto/warehouse/WarehouseDTO.h"
#include "../../domain/vo/warehouse/WarehouseJsonVO.h"
#include "../../domain/query/PullListQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 获取仓库名称列表
 * 负责人：。好
 */
class WarehouseController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(WarehouseController)
public: // 定义接口
	
	ENDPOINT_INFO(queryWarehouse) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("common-usage.warehouse.summary"));
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(WarehouseJsonVO);
		// 定义参数字段
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("common-usage.field.keywords"), "", false);
		// 定义授权支持
		API_DEF_ADD_AUTH();
	}

	ENDPOINT(API_M_GET, COMMON(/warehouse), queryWarehouse, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 定义解析query参数
		API_HANDLER_QUERY_PARAM(query, PullListQuery, queryParams);
		// 定义呼叫执行函数
		API_HANDLER_RESP_VO(execQueryWarehouse(query, authObject->getPayload()));
	}

private: // 定义接口执行函数
	WarehouseJsonVO::Wrapper execQueryWarehouse(const PullListQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_WAREHOUSE_H_