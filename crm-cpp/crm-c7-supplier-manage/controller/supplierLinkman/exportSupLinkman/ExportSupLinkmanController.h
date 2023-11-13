#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/20 23:50:53

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
#ifndef _EXPORTSUPLINKMAN_H_
#define _EXPORTSUPLINKMAN_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/supplierLinkman/ExportSupLinkmanQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 导出供应商联系人Controller
 * 负责人: Andrew
 */
class ExportSupLinkmanController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ExportSupLinkmanController);
public: // 定义接口
	// 定义接口描述
	ENDPOINT_INFO(exportLinkman) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier-linkman.export-sup-linkman.summary"));
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("supplier-linkman.export-sup-linkman.field.keywords"), {}, false);
		API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("supplier-linkman.export-sup-linkman.field.supplier-name"), {}, false);
		API_DEF_ADD_QUERY_PARAMS(String, "address", ZH_WORDS_GETTER("supplier-linkman.export-sup-linkman.field.address"), {}, false);
	}
	// 定义接口处理
	ENDPOINT(API_M_GET, SUP_LINKMAN(/export-linkman), exportLinkman, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数queryParams为ExportSupLinkmanQuery类型
		API_HANDLER_QUERY_PARAM(query, ExportSupLinkmanQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execExportSupLinkman(query));
	}
private: // 定义接口执行函数
	StringJsonVO::Wrapper execExportSupLinkman(const ExportSupLinkmanQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPORTSUPLINKMAN_H_