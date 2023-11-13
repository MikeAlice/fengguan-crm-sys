#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huipaodeyu
 @Date: 2023/10/25 10:36:07

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
#ifndef _EXPORTSERVICENOTE_MAPPER_
#define _EXPORTSERVICENOTE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/service/ServiceDO.h"

/**
 * ·þÎñ¼ÇÂ¼±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ExportServiceNoteMapper : public Mapper<ServiceDO>
{
public:
	ServiceDO mapper(ResultSet* resultSet) const override
	{
		ServiceDO data;
		//data.setService_id(resultSet->getUInt64(1));
		data.setCustomer_id(resultSet->getInt(1));
		data.setServices(resultSet->getInt(2));
		data.setServicesmodel(resultSet->getInt(3));
		data.setService_time(resultSet->getString(4));
		data.setTlen(resultSet->getString(5));
		data.setContent(resultSet->getString(6));
		data.setCustomer_name(resultSet->getString(7));
		return data;
	}
};

#endif // !_EXPORTSERVICENOTE_MAPPER_