#pragma once
#ifndef ADDANDUPDATECONTACTDTO_H__
#define ADDANDUPDATECONTACTDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����ϵ�˴������
 */
class AddContactDTO : public oatpp::DTO
{
	DTO_INIT(AddContactDTO, DTO);
	// �ͻ�ID
	DTO_FIELD(UInt32, customer_id);
	DTO_FIELD_INFO(customer_id) {
		info->description = ZH_WORDS_GETTER("contact.field.customer_id");
	}

	// ��ϵ������
	DTO_FIELD(String, linkman_name);
	DTO_FIELD_INFO(linkman_name) {
		info->description = ZH_WORDS_GETTER("contact.field.name");
	}

	// ��ϵ���Ա�
	DTO_FIELD(UInt32, gender);
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
	// ��ϵ������
	DTO_FIELD(String, email);
	DTO_FIELD_INFO(email) {
		info->description = ZH_WORDS_GETTER("contact.field.email");
	}
	// ��ϵ����������
	DTO_FIELD(String, zipcode);
	DTO_FIELD_INFO(zipcode) {
		info->description = ZH_WORDS_GETTER("contact.field.zipcode");
	}
	// ��ϵ�˵�ַ
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("contact.field.address");
	}
	// ��ϵ�˼��
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("contact.field.intro");
	}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // ADDANDUPDATECONTACTDTO_H__