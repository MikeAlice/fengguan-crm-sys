#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/11/09
 @FileName: QueryBankAccountMapper
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
#ifndef _QUERY_BANK_ACCOUNT_MAPPER_
#define _QUERY_BANK_ACCOUNT_MAPPER_
#include "Mapper.h"
#include "domain/do/fincapitalrecord/BankAccountDO.h"

class QueryBankAccountMapper : public Mapper<BankAccountDO>
{
public:
	BankAccountDO mapper(ResultSet* resultSet) const override
	{
		BankAccountDO data;
		data.setName(resultSet->getString(1));
		data.setCard(resultSet->getString(2));

		return data;
	}
};
#endif