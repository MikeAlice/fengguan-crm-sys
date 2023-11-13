/*
 Copyright Zero One Star. All rights reserved.

 @Author: danshuidoge
 @Date: 2023/10/23 22:40:13

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
#include "ServiceService.h"
#include "../../dao/service/ServiceDAO.h"



uint64_t ServiceService::saveData(const ServiceBaseDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	ServiceDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Customer_id, customer_id, Linkman_id, linkman_id, Services, services,
		Servicesmodel, servicesmodel, Price, price, Status, status,
		Service_time, service_time, Tlen, tlen, Content, content)
		data.setIntro(dto->intro.getValue({}));
	data.setCreate_user_id(atoi(payload.getId().c_str()));
	data.setCreate_time(SimpleDateTimeFormat::format());
	// 执行数据添加
	ServiceDAO dao;
	return dao.insert(data);
}

bool ServiceService::updateData(const ServiceModifyDTO::Wrapper& dto)
{
	// 组装DO数据
	ServiceDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Customer_id, customer_id, Linkman_id, linkman_id, Services, services,
		Servicesmodel, servicesmodel, Price, price, Status, status,
		Service_time, service_time, Tlen, tlen, Content, content)
		ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Intro, intro, Service_id, service_id)
		// 执行数据添加
		// 执行数据修改
		ServiceDAO dao;
	return dao.update(data) == 1;
}

bool ServiceService::removeData(uint64_t id)
{
	ServiceDAO dao;
	return dao.deleteById(id) == 1;
}