#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/21 21:50:04

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
#ifndef _SUPPLIER_NAME_CONTROLLER_
#define _SUPPLIER_NAME_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/supplier/SupplierNameQuery.h"
#include "domain/dto/supplier/SupplierNameDTO.h"
#include "domain/vo/supplier/SupplierNameVO.h"
#include "Macros.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class SupplierNameController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SupplierNameController);
	// 3 定义接口
public:
	// 3.1 定义供应商名称列表查询接口描述
	ENDPOINT_INFO(querySupplierName) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier.getSupList.nameList"));
		API_DEF_ADD_AUTH();
		//定义相应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SupplierNameJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("supplier.getSupList.name"), "li ming", false);
	}

	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, SUP(/query-supplier-name), querySupplierName, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, SupplierNameQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySupplierName(userQuery));
	}

private:
	// 3.3 列表查询供应商名称数据
	SupplierNameJsonVO::Wrapper execQuerySupplierName(const SupplierNameQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SUPPLIER_NAME_CONTROLLER_
