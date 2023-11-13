#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: telephone
 @Date: 2023/10/23 18:20:31

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
#ifndef SUPPLIER_LINK_MAN
#define SUPPLIER_LINK_MAN

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/supplierLinkman/SupplierLinkmanVO.h"
#include "domain/dto/supplierLinkman/SupplierLinkmanDTO.h"
#include "domain/query/supplierLinkman/SupplierLinkmanQuery.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 获取供应商联系人列表&添加供应商联系人controller
 * 负责人: telephone
 */
class SupplierLinkmanController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SupplierLinkmanController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(querySupplierLinkman) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier-linkman.query-page.summary"));
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SupplierLinkmanPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("supplier-linkman.query-page.field.keywords"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("supplier-linkman.query-page.field.supplier-name"), "hao", false);
		API_DEF_ADD_QUERY_PARAMS(String, "address", ZH_WORDS_GETTER("supplier-linkman.query-page.field.address"), "", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, SUP_LINKMAN(/query-linkman-page), querySupplierLinkman, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, SupplierLinkmanQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySupplierLinkman(userQuery));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addSupplierLinkman) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier-linkman.add-linkman.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, SUP_LINKMAN(/add-linkman), addSupplierLinkman, BODY_DTO(AddSupplierLinkmanDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddSupplierLinkman(dto, authObject->getPayload()));
	}

	
private:
	// 3.3 演示分页查询数据
	SupplierLinkmanPageJsonVO::Wrapper execQuerySupplierLinkman(const SupplierLinkmanQuery::Wrapper& query);
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddSupplierLinkman(const AddSupplierLinkmanDTO::Wrapper& dto, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif
