#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _Supplier_MAPPER_
#define _Supplier_MAPPER_

#include "Mapper.h"
#include "../../domain/do/add-pay-record/addPayRecordDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
	class SupplierMapper : public Mapper<AddPayRecordDO>
{

public:
	AddPayRecordDO mapper(ResultSet* resultSet) const override
	{
		AddPayRecordDO data;
		data.setSupplierId(resultSet->getInt64("supplier_id"));
		data.setSupplierName(resultSet->getString("supplier_name"));

		return data;
	}
};

#endif // !_SAMPLE_MAPPER_