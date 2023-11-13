#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: telephone
 @Date: 2023/10/23 18:20:31

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
#ifndef _SUPPLIER_LINK_MAN_DTO_
#define _SUPPLIER_LINK_MAN_DTO_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ӹ�Ӧ����ϵ�˴������
 * ������: telephone
 */
class AddSupplierLinkmanDTO : public oatpp::DTO
{
	DTO_INIT(AddSupplierLinkmanDTO, DTO);
	// ��Ӧ����ϵ������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("supplier-linkman.query-page.field.name"));
	// ��Ӧ��ID
	API_DTO_FIELD_DEFAULT(UInt64, supplier_id, ZH_WORDS_GETTER("supplier-linkman.query-page.field.supplier-id"));
	// �Ա�
	API_DTO_FIELD_DEFAULT(UInt64, gender, ZH_WORDS_GETTER("supplier-linkman.query-page.field.supplier-gender"));
	// ְλ
	API_DTO_FIELD_DEFAULT(String, position, ZH_WORDS_GETTER("supplier-linkman.query-page.field.supplier-position"));
	// ����
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("supplier-linkman.query-page.field.tel"));
	// �ֻ���
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("supplier-linkman.query-page.field.mobile"));
	// QQ
	API_DTO_FIELD_DEFAULT(String, qicq, ZH_WORDS_GETTER("supplier-linkman.query-page.field.qq"));
	// ����
	API_DTO_FIELD_DEFAULT(String, email, ZH_WORDS_GETTER("supplier-linkman.query-page.field.email"));
	// ͨ�ŵ�ַ
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("supplier-linkman.query-page.field.address"));
	// ����
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("supplier-linkman.query-page.field.intro"));
	// ��չ�ֶ�
	API_DTO_FIELD(Fields<String>, ext_fields, ZH_WORDS_GETTER("supplier-linkman.query-page.field.ext-fields"), false, Fields<String>::createShared());
};

class ModifySupplierLinkmanDTO : public AddSupplierLinkmanDTO
{
	DTO_INIT(ModifySupplierLinkmanDTO, AddSupplierLinkmanDTO);
	// ��Ӧ����ϵ��ID
	API_DTO_FIELD_DEFAULT(UInt64, linkman_id, ZH_WORDS_GETTER("supplier-linkman.query-page.field.id"));
};

/**
 * ��Ӧ����ϵ�˴������
 * ������: telephone
 */
class SupplierLinkmanDTO : public ModifySupplierLinkmanDTO
{
	DTO_INIT(SupplierLinkmanDTO, ModifySupplierLinkmanDTO);
	// ��Ӧ������
	API_DTO_FIELD_DEFAULT(String, supplier_name, ZH_WORDS_GETTER("supplier-linkman.query-page.field.supplier-name"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, zipcode, ZH_WORDS_GETTER("supplier-linkman.query-page.field.zipcode"));
	// �����û�ID
	API_DTO_FIELD_DEFAULT(UInt64, create_user_id, ZH_WORDS_GETTER("supplier-linkman.query-page.field.create-user-id"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("supplier-linkman.query-page.field.create-time"));
};

/**
 * ��Ӧ����ϵ�˷�ҳ�������
 * ������: telephone
 */
class SupplierLinkmanPageDTO : public PageDTO<SupplierLinkmanDTO::Wrapper>
{
	DTO_INIT(SupplierLinkmanPageDTO, PageDTO<SupplierLinkmanDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
