#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/25
 @FileName: ExportCapitalRecordMapper
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
#ifndef _EXPORT_CAPITAL_RECORD_MAPPER_
#define _EXPORT_CAPITAL_RECORD_MAPPER_
#include "Mapper.h"
#include "domain/do/fincapitalrecord/ExportCapitalRecordDO.h"

class ExportCapitalRecordMapper : public Mapper<ExportCapitalRecordDO>
{
public:
	ExportCapitalRecordDO mapper(ResultSet* resultSet) const override
	{
		ExportCapitalRecordDO data;
		data.setRecordId(resultSet->getInt(1));
		data.setType(resultSet->getString(2));
		data.setMoney(resultSet->getInt(3));
		data.setBankId(resultSet->getInt(4));
		data.setBankName(resultSet->getString(5));
		data.setBankCard(resultSet->getString(6));
		data.setHappenDate(resultSet->getString(7));
		data.setCreateUser(resultSet->getString(8));
		data.setCreateTime(resultSet->getString(9));
		data.setIntro(resultSet->getString(10));

		return data;
	}

};

#endif