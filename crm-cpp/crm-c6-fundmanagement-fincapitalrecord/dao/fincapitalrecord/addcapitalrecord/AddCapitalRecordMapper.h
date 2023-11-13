#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/28
 @FileName: AddCapitalRecordMapper
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
#ifndef _ADD_CAPITAL_RECORD_MAPPER_
#define _ADD_CAPITAL_RECORD_MAPPER_
#include "Mapper.h"
#include "domain/do/fincapitalrecord/AddCapitalRecordDO.h"

class AddCapitalRecordMapper : public Mapper<AddCapitalRecordDO>
{
public:
	AddCapitalRecordDO mapper(ResultSet* resultSet) const override
	{
		AddCapitalRecordDO data;
		//data.setRecordId(resultSet->getUInt64(1));
		data.setTypeId(resultSet->getInt64(2));
		data.setCreateUserId(resultSet->getInt64(3));
		data.setBankId(resultSet->getInt64(4));
		data.setMoney(resultSet->getInt64(5));
		data.setIntro(resultSet->getString(6));
		data.setCreateTime(resultSet->getString(7));
		data.setHappenDate(resultSet->getString(8));

		return data;
	}
};

#endif