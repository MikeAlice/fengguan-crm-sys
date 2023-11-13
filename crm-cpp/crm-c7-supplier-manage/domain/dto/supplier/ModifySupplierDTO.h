#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/21 21:50:04

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
#ifndef _MODIFY_SUPPLIER_DTO_
#define _MODIFY_SUPPLIER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �޸Ĺ�Ӧ�̽ӿڴ������
 * ������: Juno
 */
class ModifySupplierDTO : public oatpp::DTO
{
	DTO_INIT(ModifySupplierDTO, DTO);
	// ��Ӧ��ID
	DTO_FIELD(UInt64, supplierId);
	DTO_FIELD_INFO(supplierId) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.supplierId");
	}
	// ��Ӧ������
	DTO_FIELD(String, supplierName);
	DTO_FIELD_INFO(supplierName) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.supplierName");
	}
	// ��������
	DTO_FIELD(Int64, ecoType);
	DTO_FIELD_INFO(ecoType) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.ecotype");
	}
	// ��ҵ����
	DTO_FIELD(Int64, trade);
	DTO_FIELD_INFO(trade) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.trade");
	}
	// ��ϵ��ַ
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.address");
	}
	// ��ϵ��id
	DTO_FIELD(UInt64, linkman);
	DTO_FIELD_INFO(linkman) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.linkman");
	}
	// �绰
	DTO_FIELD(String, telephone);
	DTO_FIELD_INFO(telephone) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.telephone");
	}
	// ����
	DTO_FIELD(String, fax);
	DTO_FIELD_INFO(fax) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.fax");
	}
	// ����
	DTO_FIELD(String, email);
	DTO_FIELD_INFO(email) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.email");
	}
	// ����
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.intro");
	}
	//��չ�ֶ�
	API_DTO_FIELD(Fields<String>, ext_fields, ZH_WORDS_GETTER("supplier.getSupList.extend"), false, Fields<String>::createShared());

public:
	ModifySupplierDTO()
	{

	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MODIFY_SUPPLIER_DTO_
