#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/23 21:56:28

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
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/service/ServiceDO.h"

/**
 * ·þÎñ¼ÇÂ¼±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ServiceMapper : public Mapper<ServiceDO>
{
public:
	ServiceDO mapper(ResultSet* resultSet) const override
	{
		ServiceDO data;
		data.setService_id(resultSet->getUInt64(1));
		data.setCustomer_id(resultSet->getInt(2));
		data.setLinkman_id(resultSet->getInt(3));
		data.setServices(resultSet->getInt(4));
		data.setServicesmodel(resultSet->getInt(5));
		data.setPrice(resultSet->getInt(6));
		data.setStatus(resultSet->getInt(7));
		data.setService_time(resultSet->getString(8));
		data.setTlen(resultSet->getString(9));
		data.setContent(resultSet->getString(10));
		data.setIntro(resultSet->getString(11));
		data.setCreate_user_id(resultSet->getInt(12));
		data.setCreate_time(resultSet->getString(13));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_