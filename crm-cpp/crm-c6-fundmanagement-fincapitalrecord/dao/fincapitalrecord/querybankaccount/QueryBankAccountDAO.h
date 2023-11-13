#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/11/09
 @FileName: QueryBankAccountDAO
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
#ifndef _QUERY_BANK_ACCOUNT_DAO_
#define _QUERY_BANK_ACCOUNT_DAO_
#include "BaseDAO.h"
#include "domain/do/fincapitalrecord/BankAccountDO.h"
#include "domain/query/fincapitalrecord/BankAccountPageQuery.h"

//查询资金注入抽取信息(分页) 负责人：超能
class QueryBankAccountDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const BankAccountPageQuery::Wrapper& query);
	// 分页查询数据
	list<BankAccountDO> selectWithPage(const BankAccountPageQuery::Wrapper& query);
};
#endif