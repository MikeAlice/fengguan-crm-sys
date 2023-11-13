#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 锋
 @Date: 2023/10/21 0:27:04

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
#ifndef _SUPPLIER_CONTROLLER_
#define _SUPPLIER_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/supplier/SupplierQuery.h"
#include "domain/dto/supplier/SupplierDTO.h"
#include "domain/vo/supplier/SupplierVO.h"
#include "Macros.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 获取供应商列表&添加供应商Controller
 * 负责人: 峰
 */
class SupplierController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SupplierController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(querySupplier) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier.getSupList.summary"));
		API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SupplierPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("supplier.getSupList.name"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "telephone", ZH_WORDS_GETTER("supplier.getSupList.telephone"), "000-000", false);
		API_DEF_ADD_QUERY_PARAMS(String, "mobile", ZH_WORDS_GETTER("supplier.getSupList.mobile"), "000-000", false);
		API_DEF_ADD_QUERY_PARAMS(String, "address", ZH_WORDS_GETTER("supplier.getSupList.address"), "BeiJing", false);
	}

	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, SUP(/get-supplier), querySupplier, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, SupplierQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySupplier(userQuery));
	}

	//3.1定义添加接口描述
	ENDPOINT_INFO(addSupplier) {
		// 定义凭证校验
		API_DEF_ADD_AUTH();
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier.addSupplier.summary"));
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, SUP(/add-supplier), addSupplier, BODY_DTO(SupplierDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddSupplier(dto, authObject->getPayload()));
	}
	
private:
	// 3.3 分页查询数据
	SupplierPageJsonVO::Wrapper execQuerySupplier(const SupplierQuery::Wrapper& query);
	// 3.3 新增数据
	Uint64JsonVO::Wrapper execAddSupplier (const SupplierDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_