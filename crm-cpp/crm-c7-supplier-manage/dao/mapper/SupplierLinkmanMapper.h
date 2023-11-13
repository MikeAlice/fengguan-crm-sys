#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/25 19:53:22

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
#ifndef _SUPPLIERLINKMANMAPPER_H_
#define _SUPPLIERLINKMANMAPPER_H_

#include "Mapper.h"
#include <map>
#include <string>
#include "domain/do/supplierLinkman/SupplierLinkmanDO.h"
#include "domain/do/cstFieldExt/CstFieldExtDO.h"

class SupplierLinkmanMapper : public Mapper<SupplierLinkmanDO>
{
	// 扩展字段列表
	std::list<std::string> ext_fields;
public:
	// 默认构造
	SupplierLinkmanMapper(const std::list<std::string>& fields = {})
	{
		ext_fields = fields;
	}
	SupplierLinkmanDO mapper(ResultSet* resultSet) const override
	{
		SupplierLinkmanDO data;
		data.setLinkmanId(resultSet->getUInt64(1));
		data.setSupplierId(resultSet->getUInt64(2));
		data.setSupplierName(resultSet->getString(3));
		data.setName(resultSet->getString(4));
		data.setGender(resultSet->getUInt64(5));
		data.setPosition(resultSet->getString(6));
		data.setTel(resultSet->getString(7));
		data.setMobile(resultSet->getString(8));
		data.setQicq(resultSet->getString(9));
		data.setEmail(resultSet->getString(10));
		data.setZipcode(resultSet->getString(11));
		data.setAddress(resultSet->getString(12));
		data.setIntro(resultSet->getString(13));
		data.setCreateTime(resultSet->getString(14));
		data.setCreateUserId(resultSet->getUInt64(15));
		// 填充扩展字段映射表
		std::map<std::string, std::string> ext;
		for (std::string item : ext_fields)
			ext[item] = resultSet->getString(item);
		data.setExtFields(ext);
		return data;
	}
};

#endif // !_SUPPLIERLINKMANMAPPER_H_