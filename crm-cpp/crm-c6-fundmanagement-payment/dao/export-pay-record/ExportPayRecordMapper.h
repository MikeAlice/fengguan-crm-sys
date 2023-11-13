#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/27 19:47:46

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
#ifndef _EXPORTPAYRECORDMAPPER_H_
#define _EXPORTPAYRECORDMAPPER_H_

#include "Mapper.h"
#include "domain/do/export-pay-record/ExportPayRecordDO.h"


class ExportPayRecordMapper : public Mapper<ExportPayRecordDO>
{
public:
	ExportPayRecordDO mapper(ResultSet* resultSet) const override
	{
		ExportPayRecordDO data;

		data.setRecordId(resultSet->getUInt64(1));
		data.setSupplierName(resultSet->getString(2));
		data.setContractnName(resultSet->getString(3));
		data.setPayDate(resultSet->getString(4));
		data.setStages(resultSet->getUInt64(5));
		data.setMoney(resultSet->getUInt64(6));
		data.setZeroMoney(resultSet->getUInt64(7));
		//data.setCreateUserId(resultSet->getUInt64(8));
		data.setCreateUser(resultSet->getString(8));
		data.setCreateTime(resultSet->getString(9));
		data.setIntro(resultSet->getString(10));

		return data;
	}
};

#endif // !_EXPORTPAYRECORDMAPPER_H_