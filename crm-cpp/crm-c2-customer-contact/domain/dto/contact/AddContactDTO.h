#pragma once
#ifndef ADDANDUPDATECONTACTDTO_H__
#define ADDANDUPDATECONTACTDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加联系人传输对象
 */
class AddContactDTO : public oatpp::DTO
{
	DTO_INIT(AddContactDTO, DTO);
	// 客户ID
	DTO_FIELD(UInt32, customer_id);
	DTO_FIELD_INFO(customer_id) {
		info->description = ZH_WORDS_GETTER("contact.field.customer_id");
	}

	// 联系人名称
	DTO_FIELD(String, linkman_name);
	DTO_FIELD_INFO(linkman_name) {
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
	// 联系人邮政编码
	DTO_FIELD(String, zipcode);
	DTO_FIELD_INFO(zipcode) {
		info->description = ZH_WORDS_GETTER("contact.field.zipcode");
	}
	// 联系人地址
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("contact.field.address");
	}
	// 联系人简介
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("contact.field.intro");
	}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // ADDANDUPDATECONTACTDTO_H__