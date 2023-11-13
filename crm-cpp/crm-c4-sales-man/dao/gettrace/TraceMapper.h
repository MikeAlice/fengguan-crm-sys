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
#ifndef _TRACE_MAPPER_
#define _TRACE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/trace/AllDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class TraceMapper : public Mapper<AllDO>
{
public:
	AllDO mapper(ResultSet* resultSet) const override
	{
		AllDO data;
		data.setCusId(resultSet->getInt(1));
		data.setLinkid(resultSet->getInt(2));
		data.setChanceid(resultSet->getInt(3));
		data.setStage(resultSet->getInt(4));
		data.setSmode(resultSet->getInt(5));

		data.setCtime(resultSet->getString(6));
		data.setIcontent(resultSet->getString(7));
		data.setNtime(resultSet->getString(8));
		data.setCName(resultSet->getString(9));
		data.setNName(resultSet->getString(10));
		data.setConName(resultSet->getString(11));


		return data;
	}
};

#endif // !_TRACE_MAPPER_