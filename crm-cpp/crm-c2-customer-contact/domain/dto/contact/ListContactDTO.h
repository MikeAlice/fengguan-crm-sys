#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _CONTACT_DTO_
#define _CONTACT_DTO_
#include "../../GlobalInclude.h"
#include "domain/dto/contact/BaseContactDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ϵ���б������
 */
class ListContactDTO : public oatpp::DTO
{
	DTO_INIT(ListContactDTO, DTO);
	
	// ��ϵ��ID������
	DTO_FIELD(UInt32, linkman_id);
	DTO_FIELD_INFO(linkman_id) {
		info->description = ZH_WORDS_GETTER("contact.field.linkman_id");
	}

	// �ͻ�����
	API_DTO_FIELD_DEFAULT(String, customer_name, ZH_WORDS_GETTER("customer.field.name"));

	// ��ϵ������
	DTO_FIELD(String, link_name);
	DTO_FIELD_INFO(link_name) {
		info->description = ZH_WORDS_GETTER("contact.field.name");
	}
	// ��ϵ���Ա�
	DTO_FIELD(Int16, gender);
	DTO_FIELD_INFO(gender) {
		info->description = ZH_WORDS_GETTER("contact.field.gender");
	}
	// ��ϵ��ְλ
	DTO_FIELD(String, postion);
	DTO_FIELD_INFO(postion) {
		info->description = ZH_WORDS_GETTER("contact.field.postion");
	}
	// ��ϵ������
	DTO_FIELD(String, tel);
	DTO_FIELD_INFO(tel) {
		info->description = ZH_WORDS_GETTER("contact.field.tel");
	}
	// ��ϵ���ֻ�
	DTO_FIELD(String, mobile);
	DTO_FIELD_INFO(mobile) {
		info->description = ZH_WORDS_GETTER("contact.field.mobile");
	}
	// ��ϵ��QQ
	DTO_FIELD(String, qicq);
	DTO_FIELD_INFO(qicq) {
		info->description = ZH_WORDS_GETTER("contact.field.qicq");
	}
	
};

/**
 * ��ϵ���б��ҳ�������
 */
class ListContactPageDTO : public PageDTO<ListContactDTO::Wrapper>
{
	DTO_INIT(ListContactPageDTO, PageDTO<ListContactDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CONTACT_DTO_