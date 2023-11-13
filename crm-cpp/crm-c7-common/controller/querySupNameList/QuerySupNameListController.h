#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/28 18:27:39

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
#ifndef _QUERYSUPNAMELISTCONTROLLER_H_
#define _QUERYSUPNAMELISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/PullListJsonVO.h"
#include "domain/query/PullListQuery.h"
#include "domain/vo/supplierManage/SupplierNameVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class QuerySupNameListController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(QuerySupNameListController);
public: // 定义接口
	ENDPOINT_INFO(querySupNameList) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("supplier-manage.query-supplier-name-list.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(SupplierNameJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("common-usage.field.keywords"), "", false);
	}
	ENDPOINT(API_M_GET, COMMON(/query-supplier-name-list), querySupNameList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, PullListQuery, queryParams);
		API_HANDLER_RESP_VO(execQuerySupNameList(query, authObject->getPayload()));
	}
private: // 定义接口执行函数
	//PullListJsonVO::Wrapper execQuerySupNameList(const PullListQuery::Wrapper& query);
	SupplierNameJsonVO::Wrapper execQuerySupNameList(const PullListQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERYSUPNAMELISTCONTROLLER_H_