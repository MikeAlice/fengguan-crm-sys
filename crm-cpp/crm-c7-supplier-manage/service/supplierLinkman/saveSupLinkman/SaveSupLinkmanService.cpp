/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/27 22:50:56

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
#include "Macros.h"
#include <map>
#include "SaveSupLinkmanService.h"
#include "domain/do/supplierLinkman/SupplierLinkmanDO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "dao/supplierLinkman/insertSupLinkman/InsertSupLinkmanDAO.h"

uint64_t SaveSupLinkmanService::saveSupLinkman(const AddSupplierLinkmanDTO::Wrapper& dto, const PayloadDTO& payload)
{
#ifdef _USEDO_
	// ��װDO����
	SupplierLinkmanDO data;
	// ѩ���㷨����ID
	//SnowFlake sf(1, 1);
	//data.setLinkmanId(sf.nextId());
	// ����ϵͳ�ֶ�
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, SupplierId, supplier_id, Name, name, Gender, gender, Position, position, Tel, tel, Mobile, mobile, Qicq, qq, Email, email, Address, address, Intro, intro);
	// ���ô����û�ID�ʹ���ʱ��
	data.setCreateUserId(std::stoull(payload.getId()));
	data.setCreateTime(SimpleDateTimeFormat::format());
	// ������չ�ֶ�
	std::map<std::string, std::string> tmp;
	for (auto i = dto->ext_fields->begin(); i != dto->ext_fields->end(); i ++)
		tmp[i->first] = i->second;
	data.setExtFields(tmp);

	// ����DAO��������, ���ز���Ĺ�Ӧ����ϵ��ID
	InsertSupLinkmanDAO dao;
	return dao.insert(data);
#endif
	// ����DAO��������, ���ز���Ĺ�Ӧ����ϵ��ID
	InsertSupLinkmanDAO dao;
	return dao.insert(dto, payload);
}

