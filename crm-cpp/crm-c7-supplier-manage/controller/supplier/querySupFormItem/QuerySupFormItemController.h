#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/20 18:38:07

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
#ifndef _QUERYSUPFORMITEM_H_
#define _QUERYSUPFORMITEM_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/supplier/SupFormItemQuery.h"
#include "domain/vo/supplier/SupFormItemJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 供应商列表-获取供应商基础信息表单数据项
 * 负责人：Andrew
 */
class QuerySupFormItemController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(QuerySupFormItemController);
public: // 定义接口
	// 定义端点描述
	ENDPOINT_INFO(querySupFormItem) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier.query-sup-form-item.summary"));
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SupFormItemJsonVO);
		// 定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "main_table", ZH_WORDS_GETTER("supplier.query-sup-form-item.field.main-table"), "sup_supplier", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ext_table", ZH_WORDS_GETTER("supplier.query-sup-form-item.field.ext-table"), "sup_supplier", false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, SUP(/query-sup-form-item), querySupFormItem, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数queryParams为SupFormItemQuery类型
		API_HANDLER_QUERY_PARAM(query, SupFormItemQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySupFormItem(query));
	}
private: // 定义接口执行函数
	SupFormItemJsonVO::Wrapper execQuerySupFormItem(const SupFormItemQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERYSUPFORMITEM_H_