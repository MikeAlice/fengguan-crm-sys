#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/08 20:34:58

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
#ifndef _SALEMANAGECONTROLLER_H_
#define _SALEMANAGECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/saleManage/SaleOpportunityQuery.h"
#include "domain/vo/saleManage/SaleOpportunityJsonVO.h"
#include "domain/query/saleManage/SaleContractQuery.h"
#include "domain/vo/saleManage/SaleContractJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ���۹����ýӿ�Controller
 * ������: Andrew
 */
class SaleManageController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(SaleManageController);
public: // ����ӿ�
	// ��ȡ���ۻ��������б�ӿں���������
	ENDPOINT_INFO(querySaleOpportunity) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sale-manage.sale-opportunity.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(SaleOpportunityJsonVO);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "customer_id", ZH_WORDS_GETTER("sale-manage.sale-oppotunity.field.customer_id"), { 1 }, true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sale-manage.sale-oppotunity.field.name"), "", false);
	}
	ENDPOINT(API_M_GET, COMMON(/sale-opportunity-name-list), querySaleOpportunity, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, SaleOpportunityQuery, queryParams);
		API_HANDLER_RESP_VO(execQuerySaleOpportunity(query, authObject->getPayload()));
	}

	// ��ȡ���ۺ�ͬ�����б�ӿں���������
	ENDPOINT_INFO(querySaleContract) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sale-manage.sale-contract.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(SaleContractJsonVO);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "customer_id", ZH_WORDS_GETTER("sale-manage.sale-contract.field.customer_id"), { 1 }, true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sale-manage.sale-contract.field.name"), "", false);
	}
	ENDPOINT(API_M_GET, COMMON(/sale-contract-name-list), querySaleContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, SaleContractQuery, queryParams);
		API_HANDLER_RESP_VO(execQuerySaleContract(query, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	// ��ȡ���ۻ��������б�ִ�к���
	SaleOpportunityJsonVO::Wrapper execQuerySaleOpportunity(const SaleOpportunityQuery::Wrapper& query, const PayloadDTO& payload);
	// ��ȡ���ۺ�ͬ�����б�ִ�к���
	SaleContractJsonVO::Wrapper execQuerySaleContract(const SaleContractQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SALEMANAGECONTROLLER_H_