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
#include "stdafx.h"
#include "ServiceNoteService.h"
#include "../../dao/servicenote/ServiceNoteDAO.h"

ServiceNotePageDTO::Wrapper ServiceNoteService::listAll(const ServiceQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ServiceNotePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ServiceNoteDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ServiceDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ServiceDO sub : result)
	{
		auto dto = ServiceListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, customer_id, Customer_id,service_id, Service_id,services, Services, servicesmodel, Servicesmodel, service_time, Service_time,
			tlen, Tlen, content, Content,customer_name, Customer_name);
			pages->addData(dto);

	}
	return pages;
}





