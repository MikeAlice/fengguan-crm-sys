#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ��
 @Date: 2023/10/21 0:27:04

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
#ifndef _SUPPLIER_DTO_
#define _SUPPLIER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ��Ӧ�̴������
 * ������: ��
 */
class SupplierDTO : public oatpp::DTO
{
	DTO_INIT(SupplierDTO, DTO);

	// ��Ӧ��ID
	DTO_FIELD(UInt64, supplier_id);
	DTO_FIELD_INFO(supplier_id) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.supplierId");
	}
	// ��Ӧ������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.name");
	}
	// ���ڵ���
	DTO_FIELD(UInt64, area_id);
	DTO_FIELD_INFO(area_id) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.areaId");
	}
	// �����û�ID
	DTO_FIELD(UInt64, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.create_user_id");
	}
	// �û��ȼ�
	DTO_FIELD(UInt64, level);
	DTO_FIELD_INFO(level) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.level");
	}
	// ��������
	DTO_FIELD(UInt64, ecotype);
	DTO_FIELD_INFO(ecotype) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.ecotype");
	}
	// ��ҵ����
	DTO_FIELD(UInt64, trade);
	DTO_FIELD_INFO(trade) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.trade");
	}
	// �����
	DTO_FIELD(UInt8, satisfy);
	DTO_FIELD_INFO(satisfy) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.satisfy");
	}
	// ���ö�
	DTO_FIELD(UInt8, credit);
	DTO_FIELD_INFO(credit) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.credit");
	}
	// ��ϵ��
	DTO_FIELD(UInt64, linkman);
	DTO_FIELD_INFO(linkman) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.linkman");
	}
	// ��ϵ������
	DTO_FIELD(String, linkman_name);
	DTO_FIELD_INFO(linkman_name) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.linkman_name");
	}
	// ��վ
	DTO_FIELD(UInt64, website);
	DTO_FIELD_INFO(website) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.website");
	}
	// �ʱ�
	DTO_FIELD(String, zipcode);
	DTO_FIELD_INFO(zipcode) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.zipcode");
	}
	//�绰
	DTO_FIELD(String, tel);
	DTO_FIELD_INFO(tel) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.telephone");
	}
	//����
	DTO_FIELD(String, fax);
	DTO_FIELD_INFO(fax) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.fax");
	}
	//����
	DTO_FIELD(String, email);
	DTO_FIELD_INFO(email) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.telephone");
	}
	//ͨ�ŵ�ַ
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.address");
	}
	//����
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.intro");
	}
	// ����ʱ��
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("supplier.getSupList.create_time");
	}
	// ��չ�ֶ�
	API_DTO_FIELD(Fields<String>, ext_fields, ZH_WORDS_GETTER("supplier.getSupList.extend"), false,
		Fields<String>::createShared());

public:
	SupplierDTO() {}
};

/**
 * ��ȡ��Ӧ�̷�ҳ�������
 * ������: ��
 */
class SupplierPageDTO : public PageDTO<SupplierDTO::Wrapper>
{
	DTO_INIT(SupplierPageDTO, PageDTO<SupplierDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_