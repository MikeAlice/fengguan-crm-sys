#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/02 18:34:37

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
#ifndef _CLIENTMANGECONTROLLER_H_
#define _CLIENTMANGECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/PullListQuery.h"
#include "domain/vo/clientManage/ClientNameJsonVO.h"
#include "domain/vo/PullListJsonVO.h"
#include "domain/query/clientManage/ContactNameQuery.h"
#include "domain/vo/clientManage/ContactNameJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 客户管理模块公用接口
 * 负责人: Andrew & tapioca
 */
class ClientManageController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ClientManageController);
public: // 定义接口
	// 获取客户名称列表接口和描述定义
	// 负责人: Andrew
	ENDPOINT_INFO(queryClientName) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("client-manage.my-client.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(ClientNameArrayJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("common-usage.field.keywords"), "", false);
	}
	ENDPOINT(API_M_GET, COMMON(/client-name-list), queryClientName, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, PullListQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryClientName(query, authObject->getPayload()));
	}
	// 获取联系人名称列表接口和描述定义
	// 负责人: tapioca
	ENDPOINT_INFO(queryContactName) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("client-manage.contact.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(ContactNameArrayJsonVO);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "customer_id", ZH_WORDS_GETTER("client-manage.contact.field.id"), {1}, true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("client-manage.contact.field.name"), "", false);
	}
	ENDPOINT(API_M_GET, COMMON(/query-contact-name), queryContactName, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, ContactNameQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryContactName(query, authObject->getPayload()));
	}
private: // 定义接口执行函数
	// 获取客户名称列表接口执行函数
	// 负责人: Andrew
	ClientNameArrayJsonVO::Wrapper execQueryClientName(const PullListQuery::Wrapper& query, const PayloadDTO& payload);
	// 获取联系人名称列表接口执行函数
	// 负责人: tapioca
	ContactNameArrayJsonVO::Wrapper execQueryContactName(const ContactNameQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_CLIENTMANGECONTROLLER_H_