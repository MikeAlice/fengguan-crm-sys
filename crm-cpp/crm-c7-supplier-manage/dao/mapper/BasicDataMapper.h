#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2023/10/25 14:27:32

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
#ifndef _BASICDATAMAPPER_H_
#define _BASICDATAMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/cstFieldExt/CstFieldExtDO.h"

/**
 * BasicData字段映射
 * 负责人：。好
 */
class BasicDataMapper : public Mapper<CstFieldExtDO>
{
public:
	CstFieldExtDO mapper(ResultSet* resultSet) const override
	{
		CstFieldExtDO data;
		data.setShowName(resultSet->getString(1));
		data.setFieldName(resultSet->getString(2));
		data.setFieldType(resultSet->getString(3));
		data.setDefaultValue(resultSet->getString(4));
		data.setIsMust(resultSet->getUInt(5));
		return data;
	}
};

#endif // !_BASICDATAMAPPER_H_