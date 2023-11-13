#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/26 21:21:55

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
#ifndef _SUPPLIER_NAME_MAPPER_
#define _SUPPLIER_NAME_MAPPER_

#include "Mapper.h"
#include "domain/do/supplier/SupplierDO.h"

/**
 * ��Ӧ�������ֶ�ƥ��ӳ��
 */
class SupplierNameMapper : public Mapper<SupplierDO>
{
public:
	SupplierDO mapper(ResultSet* resultSet) const override
	{
		SupplierDO data;
		data.setSupplierId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

#endif // !_SUPPLIER_NAME_MAPPER_
