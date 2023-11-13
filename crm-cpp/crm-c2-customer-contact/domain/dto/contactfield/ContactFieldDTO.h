#pragma once
#ifndef _CONTACTFIELD_DTO_
#define _CONTACTFIELD_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加联系人传输对象
 */
class ContactFieldDTO : public oatpp::DTO
{
	DTO_INIT(ContactFieldDTO, DTO);
	// 客户ID
	DTO_FIELD(UInt32, customer_id);
	DTO_FIELD_INFO(customer_id) {
		info->description = ZH_WORDS_GETTER("contact.field.customer_id");
	}

	// 联系人名称
	DTO_FIELD(String, link_name);
	DTO_FIELD_INFO(link_name) {
		info->description = ZH_WORDS_GETTER("contact.field.name");
	}
	// 联系人性别
	DTO_FIELD(UInt32, gender);
	DTO_FIELD_INFO(gender) {
		info->description = ZH_WORDS_GETTER("contact.field.gender");
	}
	// 联系人职位
	DTO_FIELD(String, postion);
	DTO_FIELD_INFO(postion) {
		info->description = ZH_WORDS_GETTER("contact.field.postion");
	}
	// 联系人座机
	DTO_FIELD(String, tel);
	DTO_FIELD_INFO(tel) {
		info->description = ZH_WORDS_GETTER("contact.field.tel");
	}
	// 联系人手机
	DTO_FIELD(String, mobile);
	DTO_FIELD_INFO(mobile) {
		info->description = ZH_WORDS_GETTER("contact.field.mobile");
	}
	// 联系人QQ
	DTO_FIELD(String, qicq);
	DTO_FIELD_INFO(qicq) {
		info->description = ZH_WORDS_GETTER("contact.field.qicq");
	}
	// 联系人邮箱
	DTO_FIELD(String, email);
	DTO_FIELD_INFO(email) {
		info->description = ZH_WORDS_GETTER("contact.field.email");
	}

	// 联系人地址
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("contact.field.address");
	}
	/*
	// 客户姓名
	DTO_FIELD(String, customer_name);
	DTO_FIELD_INFO(customer_name) {
		info->description = ZH_WORDS_GETTER("contact.field.customer_name");
	}*/
};

#include OATPP_CODEGEN_END(DTO)
#endif // _CONTACTFIELD_DTO_