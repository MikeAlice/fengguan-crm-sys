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
#ifndef _SERVICENOTE_MAPPER_
#define _SERVICENOTE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/service/ServiceDO.h"

/**
 * ·þÎñ¼ÇÂ¼±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ServiceNoteMapper : public Mapper<ServiceDO>
{
public:
	ServiceDO mapper(ResultSet* resultSet) const override
	{
		ServiceDO data;
		data.setService_id(resultSet->getInt(1));
		data.setServices(resultSet->getInt(2));
		data.setCustomer_id(resultSet->getInt(3));
		data.setServicesmodel(resultSet->getInt(4));
		data.setService_time(resultSet->getString(5));
		data.setTlen(resultSet->getString(6));
		data.setContent(resultSet->getString(7));
		data.setCustomer_name(resultSet->getString(8));
		return data;
	}
};
//sql << "SELECT s.services,s.customer_id,s.servicesmodel,s.service_time,s.tlen,s.content,c.name \
// s.service_id,s.services,s.customer_id,s.servicesmodel,s.service_time,s.tlen,s.content,c.name
//			FROM cst_service s LEFT JOIN cst_customer c on s.customer_id = c.customer_id";
#endif // !_SERVICENOTE_MAPPER_