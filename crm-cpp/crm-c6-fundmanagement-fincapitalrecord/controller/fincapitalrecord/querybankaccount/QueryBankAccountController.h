#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/11/09
 @FileName: QueryBankAccountController
 @version: 1.0

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
#ifndef _QUERY_BANK_ACCOUNT_CONTROLLER_H_
#define _QUERY_BANK_ACCOUNT_CONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/fincapitalrecord/BankAccountPageQuery.h"
#include "domain/vo/fincapitalrecord/BankAccountPageJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class QueryBankAccountController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(QueryBankAccountController);
public:// ����ӿ�
	// ��ȡ�����˺��б����� �����ˣ�����
	ENDPOINT_INFO(queryBankAccount) {
		// �ö˵��������Ϣ
		info->summary = ZH_WORDS_GETTER("fin_bank_account.controller.query.summary");
		// ��Ӱ�ȫ��֤
		API_DEF_ADD_AUTH();
	}

	ENDPOINT(API_M_GET, "/fin-capital-record/query-bank-account", queryBankAccount, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(bankAccountQuery, BankAccountPageQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryBankAccount(bankAccountQuery, authObject->getPayload()));
	}
private:
	// ��ȡ�����˺��б����� �����ˣ�����
	BankAccountPageJsonVO::Wrapper execQueryBankAccount(const BankAccountPageQuery::Wrapper& query, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController)
#endif
