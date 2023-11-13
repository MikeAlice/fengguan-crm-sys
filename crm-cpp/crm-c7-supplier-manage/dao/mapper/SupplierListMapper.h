#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 锋
 @Date: 2023/10/27 21:13:43

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
#ifndef _SUPPLIERLISTMAPPER_H_
#define _SUPPLIERLISTMAPPER_H_

#include "Mapper.h"
#include <map>
#include <string>
#include "../../domain/do/supplier/SupplierDO.h"
#include "domain/do/cstFieldExt/CstFieldExtDO.h"

class SupplierListMapper : public Mapper<SupplierDO>
{
	// 扩展字段列表
	std::list<std::string> ext_fields;
public:
	// 默认构造
	SupplierListMapper(const std::list<std::string>& fields = {})
	{
		ext_fields = fields;
	}
	SupplierDO mapper(ResultSet* resultSet) const override
	{
		SupplierDO data;
		data.setSupplierId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setAreaId(resultSet->getUInt64(3));
		data.setCreateUserId(resultSet->getUInt64(4));
		data.setLevel(resultSet->getUInt64(5));
		data.setEcotype(resultSet->getUInt64(6));
		data.setTrade(resultSet->getUInt64(7));
		data.setSatisfy(resultSet->getUInt(8));
		data.setCredit(resultSet->getUInt(9));
		data.setAddress(resultSet->getString(10));
		data.setLinkman(resultSet->getUInt64(11));
		data.setWebsite(resultSet->getUInt64(12));
		data.setZipcode(resultSet->getString(13));
		data.setTel(resultSet->getString(14));
		data.setFax(resultSet->getString(15));
		data.setEmail(resultSet->getString(16));
		data.setIntro(resultSet->getString(17));
		data.setCreateTime(resultSet->getString(18));
		data.setLinkmanName(resultSet->getString(19));
		// 填充扩展字段映射表
		std::map<std::string, std::string> ext;
		for (std::string item : ext_fields)
			ext[item] = resultSet->getString(item);
		data.setExtFields(ext);
		return data;
	}

};

#endif // !_SUPPLIERLISTMAPPER_H_