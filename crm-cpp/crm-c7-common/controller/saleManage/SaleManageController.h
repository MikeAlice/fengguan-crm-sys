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
 * 销售管理公用接口Controller
 * 负责人: Andrew
 */
class SaleManageController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(SaleManageController);
public: // 定义接口
	// 获取销售机会名称列表接口和描述定义
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

	// 获取销售合同名称列表接口和描述定义
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
private: // 定义接口执行函数
	// 获取销售机会名称列表执行函数
	SaleOpportunityJsonVO::Wrapper execQuerySaleOpportunity(const SaleOpportunityQuery::Wrapper& query, const PayloadDTO& payload);
	// 获取销售合同名称列表执行函数
	SaleContractJsonVO::Wrapper execQuerySaleContract(const SaleContractQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SALEMANAGECONTROLLER_H_