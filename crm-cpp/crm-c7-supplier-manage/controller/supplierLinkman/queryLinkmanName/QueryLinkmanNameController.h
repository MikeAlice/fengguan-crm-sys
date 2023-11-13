#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/24 3:20:31

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
#ifndef _QUERYLINKMANNAMECONTROLLER_H_
#define _QUERYLINKMANNAMECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/supplierLinkman/LinkmanNameQuery.h"
#include "domain/vo/supplierLinkman/LinkmanNameJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class QueryLinkmanNameController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(QueryLinkmanNameController);
public: // 定义接口
	ENDPOINT_INFO(queryLinkmanName) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("supplier-linkman.query-linkman-name.summary"), LinkmanNameJsonVO::Wrapper);
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("supplier-linkman.query-linkman-name.field.keywords"), "linkman", false);
	}
	ENDPOINT(API_M_GET, SUP_LINKMAN(/query-name-pull-list), queryLinkmanName, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, LinkmanNameQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryLinkmanName(query));
	}
private: // 定义接口执行函数
	LinkmanNameJsonVO::Wrapper execQueryLinkmanName(const LinkmanNameQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERYLINKMANNAMECONTROLLER_H_