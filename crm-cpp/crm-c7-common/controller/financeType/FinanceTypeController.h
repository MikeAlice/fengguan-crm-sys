#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/03 16:00:18

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
#ifndef _FINANCETYPECONTROLLER_H_
#define _FINANCETYPECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/PullListJsonVO.h"
#include "domain/query/PullListQuery.h"
#include "domain/vo/financeType/BankAccountJsonVO.h"
#include "domain/vo/financeType/CostIncomeJsonVO.h"
#include "domain/vo/financeType/CostExpenseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class FinanceTypeController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(FinanceTypeController);
public: // ����ӿ�
	// ��ȡ�����������������б�ӿں���������
	ENDPOINT_INFO(queryCostIncome) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("finance-type.cost-income.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(CostIncomeArrayJsonVO);
	}
	ENDPOINT(API_M_GET, COMMON(/cost-income-type-name-list), queryCostIncome, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryCostIncome(authObject->getPayload()));
	}
	// ��ȡ���ÿ�֧���������б�ӿں���������
	ENDPOINT_INFO(queryCostExpense) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("finance-type.cost-expense.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(CostExpenseArrayJsonVO);
	}
	ENDPOINT(API_M_GET, COMMON(/cost-expense-type-name-list), queryCostExpense, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryCostExpense(authObject->getPayload()));
	}
	// ��ȡ�����˻��б�ӿں���������
	ENDPOINT_INFO(queryBankAccount) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("finance-type.bank-account.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(BankAccountArrayJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "keywords", ZH_WORDS_GETTER("common-usage.field.keywords"), "", false);
	}
	ENDPOINT(API_M_GET, COMMON(/bank-account-list), queryBankAccount, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, PullListQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryBankAccount(query, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	// ��ȡ�����������������б�ӿ�ִ�к���
	CostIncomeArrayJsonVO::Wrapper execQueryCostIncome(const PayloadDTO& payload);
	// ��ȡ���ÿ�֧���������б�ӿ�ִ�к���
	CostExpenseArrayJsonVO::Wrapper execQueryCostExpense(const PayloadDTO& payload);
	// ��ȡ�����˻��б�ӿ�ִ�к���
	BankAccountArrayJsonVO::Wrapper execQueryBankAccount(const PullListQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FINANCETYPECONTROLLER_H_