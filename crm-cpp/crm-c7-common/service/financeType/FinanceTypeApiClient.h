#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/11/03 16:11:11

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
#ifndef _FINANCETYPEAPICLIENT_H_
#define _FINANCETYPEAPICLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"

class FinanceTypeApiClient : public oatpp::web::client::ApiClient
{
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 初始化定义
	API_CLIENT_INIT(FinanceTypeApiClient);

	// 使用API_CALL或API_CALL_ASYNC声明调用服务接口
	// 获取费用收入类型名称列表
	API_CALL(API_M_GET, "feeincome/query-all-feeincome", queryCostIncome, API_HANDLER_AUTN_HEADER);
	// 获取费用开支类型名称列表
	API_CALL(API_M_GET, "expensetype/query-all-expensetype", queryCostExpense, API_HANDLER_AUTN_HEADER);
	// 获取银行账户列表
	API_CALL(API_M_GET, "financial-management/bankaccount/get-bankaccountlist", queryBankAccount, API_HANDLER_AUTN_HEADER, QUERY(String, name));
#include OATPP_CODEGEN_END(ApiClient)
};

#endif // !_FINANCETYPEAPICLIENT_H_