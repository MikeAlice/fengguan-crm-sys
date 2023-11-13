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
#include "stdafx.h"
#include "FinanceTypeController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "URIUtil.h"

CostIncomeArrayJsonVO::Wrapper FinanceTypeController::execQueryCostIncome(const PayloadDTO& payload)
{
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, FinanceTypeApiClient, "finance-type-api");
	// 生成凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 返回查询结果
	return ac->queryCostIncome(token)->readBodyToDto<CostIncomeArrayJsonVO::Wrapper>(om);
}

CostExpenseArrayJsonVO::Wrapper FinanceTypeController::execQueryCostExpense(const PayloadDTO& payload)
{
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, FinanceTypeApiClient, "finance-type-api");
	// 生成凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 返回查询结果
	return ac->queryCostExpense(token)->readBodyToDto<CostExpenseArrayJsonVO::Wrapper>(om);
}

BankAccountArrayJsonVO::Wrapper FinanceTypeController::execQueryBankAccount(const PullListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, FinanceTypeApiClient, "finance-type-api");
	// 生成凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 返回查询结果
	return ac->queryBankAccount(token, URIUtil::urlEncode(query->keywords))->readBodyToDto<BankAccountArrayJsonVO::Wrapper>(om);
}
