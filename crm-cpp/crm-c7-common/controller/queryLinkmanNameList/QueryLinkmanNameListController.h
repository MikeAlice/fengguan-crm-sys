#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/29 12:27:39

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
#ifndef _QUERY_LINKMAN_NAME_LIST_CONTROLLER_
#define _QUERY_LINKMAN_NAME_LIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/supplierLinkmanManage/LinkmanNameJsonVO.h"
#include "domain/query/PullListQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class QueryLinkmanNameListController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(QueryLinkmanNameListController);
public: // 定义接口
	ENDPOINT_INFO(queryLinkmanNameList) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier-linkman.query-linkman-name-list.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(LinkmanNameJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("linkman-manage.query-linkman-name-list.field.keywords"), "", false);
	}
	ENDPOINT(API_M_GET, COMMON(/query-linkman-name-list), queryLinkmanNameList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, PullListQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryLinkmanNameList(query, authObject->getPayload()));
	}
private: // 定义接口执行函数
	LinkmanNameJsonVO::Wrapper execQueryLinkmanNameList(const PullListQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERY_LINKMAN_NAME_LIST_CONTROLLER_
