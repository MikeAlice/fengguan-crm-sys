#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/01 21:59:53

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
#ifndef _QUERYDEPARTMENTNAMECONTROLLER_H_
#define _QUERYDEPARTMENTNAMECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/PullListQuery.h"
#include "domain/vo/PullListJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��֯�ṹ���ýӿ�����ʽ����Controller
 * ������: Andrew
 */
class OrgStructureController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(OrgStructureController);
public: // ����ӿ�
	// ��ȡ���������б�ӿں���������
	ENDPOINT_INFO(queryDepartmentName) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("org-structure.department-manage.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListArrayJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("common-usage.field.keywords"), "", false);
	}
	ENDPOINT(API_M_GET, COMMON(/department-name-list), queryDepartmentName, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, PullListQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryDepartmentName(query, authObject->getPayload()));
	}
	// ��ȡ��λ�����б�ӿں���������
	ENDPOINT_INFO(queryPositionName) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("org-structure.position-manage.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListArrayJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("common-usage.field.keywords"), "", false);
	}
	ENDPOINT(API_M_GET, COMMON(/position-name-list), queryPositionName, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, PullListQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryPositionName(query, authObject->getPayload()));
	}
	// ��ȡ��ɫ�����б�ӿں���������
	ENDPOINT_INFO(queryRoleName) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("org-structure.role-manage.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListArrayJsonVO);
	}
	ENDPOINT(API_M_GET, COMMON(/role-name-list), queryRoleName, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryRoleName(authObject->getPayload()));
	}
	// ��ȡ��λ�����б�ӿں���������
	ENDPOINT_INFO(querySysUserName) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("org-structure.user-manage.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListArrayJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("common-usage.field.keywords"), "", false);
	}
	ENDPOINT(API_M_GET, COMMON(/sys-user-name-list), querySysUserName, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, PullListQuery, queryParams);
		API_HANDLER_RESP_VO(execQuerySysUserName(query, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	// ��ȡ���������б�ӿ�ִ�к���
	PullListArrayJsonVO::Wrapper execQueryDepartmentName(const PullListQuery::Wrapper& query, const PayloadDTO& payload);
	// ��ȡ��λ�����б�ӿ�ִ�к���
	PullListArrayJsonVO::Wrapper execQueryPositionName(const PullListQuery::Wrapper& query, const PayloadDTO& payload);
	// ��ȡ��ɫ�����б�ӿ�ִ�к���
	PullListArrayJsonVO::Wrapper execQueryRoleName(const PayloadDTO& payload);
	// ϵͳ�û������б�ӿ�ִ�к���
	PullListArrayJsonVO::Wrapper execQuerySysUserName(const PullListQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERYDEPARTMENTNAMECONTROLLER_H_