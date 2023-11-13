#pragma once
/*
 Copyright sashuishui. All rights reserved.

 @Author: sashuishui
 @Date: 2023/10/24 11:52:21

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
#ifndef _INCOME_MAPPER_
#define _INCOME_MAPPER_

#include "Mapper.h"
#include "../../domain/do/other_income_statement/IncomeDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class IncomeMapper : public Mapper<IncomeDO>
{
public:
	IncomeDO mapper(ResultSet* resultSet) const override
	{
		IncomeDO data;
		data.setRecordId(resultSet->getUInt64(1));
		data.setTypeId(resultSet->getUInt64(2));
		data.setBankId(resultSet->getUInt64(3));
		data.setMoney(resultSet->getDouble(4));
		data.setIntro(resultSet->getString(5));
		data.setHappenDate(resultSet->getString(6));
		data.setCreateUserId(resultSet->getUInt64(7));
		data.setCreateTime(resultSet->getString(8));
		return data;
	}
};

#endif // !_INCOME_MAPPER_