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
#include "domain/do/fin_invoice_rece/FinCapitalRecordDO.h"

class ExportCapitalRecordMapper : public Mapper<FinCapitalRecordDO>
{
public:
	FinCapitalRecordDO mapper(ResultSet* resultSet) const override
	{
		FinCapitalRecordDO data;
		/*data.setRecordId(resultSet->getUInt64(1));
		data.setTypeId(resultSet->getInt64(2));
		data.setCreateUserId(resultSet->getInt64(3));
		data.setBankId(resultSet->getUInt64(4));
		data.setMoney(resultSet->getInt64(5));
		data.setIntro(resultSet->getString(6));
		data.setCreateTime(resultSet->getString(7));
		data.setHappenDate(resultSet->getString(8));*/
		data.setRecordId(resultSet->getUInt64(1));
		data.setContractId(resultSet->getUInt64(2));
		data.setSupplierId(resultSet->getUInt64(3));
		data.setContractName(resultSet->getString(4));
		data.setSupplierName(resultSet->getString(5));
		data.setMoney(resultSet->getInt64(6));
		data.setReceDate(resultSet->getString(7));
		data.setStages(resultSet->getInt64(8));
		data.setName(resultSet->getString(9));
		data.setInvoiceNo(resultSet->getUInt64(10));
		data.setIntro(resultSet->getString(11));
		data.setCreateTime(resultSet->getString(12));
		data.setCreateUserId(resultSet->getUInt64(13));

		return data;
	}
};

#endif