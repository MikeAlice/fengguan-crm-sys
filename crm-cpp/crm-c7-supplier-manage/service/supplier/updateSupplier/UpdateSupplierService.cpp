/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/25 18:13:11

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
#include "UpdateSupplierService.h"
#include "dao/supplier/updateSupplier/UpdateSupplierDAO.h"
#include "domain/do/supplier/SupplierDO.h"


bool UpdateSupplierService::updateSupplierData(const ModifySupplierDTO::Wrapper& dto)
{
	// 组装DO数据
	SupplierDO data;
#if 0
	data.setSupplierId(dto->supplierId.getValue(0));
	data.setName(dto->supplierName.getValue(""));
	data.setAreaId(dto->areaId.getValue(0));
	data.setLevel(dto->level.getValue(0));
	data.setEcotype(dto->ecoType.getValue(0));
	data.setTrade(dto->trade.getValue(0));
	data.setSatisfy(dto->satisfy.getValue(3));
	data.setCredit(dto->credit.getValue(3));
	data.setWebsite(dto->website.getValue(""));
	data.setAddress(dto->address.getValue(""));
	data.setLinkman(dto->linkman.getValue(""));
	data.setZipcode(dto->zipcode.getValue(""));
	data.setTel(dto->telephone.getValue(""));
	data.setFax(dto->fax.getValue(""));
	data.setEmail(dto->email.getValue(""));
#else
	//静态字段
	//前一个是DO中的set/get方法名，后一个是DTO中字段名
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, 
		SupplierId, supplierId,
		Name, supplierName,
		Ecotype, ecoType,
		Trade, trade,
		Address, address,
		Linkman, linkman,
		Tel, telephone,
		Fax, fax,
		Email, email,
		Intro, intro
	)
#endif
	//扩展字段
	map<string, string> ext;
#if 0
	for (int i = 0; (dto->ext_fields)[i].first != "" && (dto->ext_fields)[i].second != ""; ++i)
	{
		ext.insert((dto->ext_fields)[i]);
	}
#else
	for (size_t i = 0; i < (dto->ext_fields)->size(); ++i)
	{
		ext.insert((dto->ext_fields)[i]);
	}
#endif
	data.setExtFields(ext);
	
	// 执行数据修改
	UpdateSupplierDAO dao;
	return dao.updateSupplierExtFields(data, dto) == 1;
}