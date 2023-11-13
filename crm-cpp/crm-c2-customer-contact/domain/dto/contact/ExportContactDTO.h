#pragma once
#ifndef EXPORTCONTACTDTO_H__
#define EXPORTCONTACTDTO_H__
#include "../../GlobalInclude.h"
#include "AddContactDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ExportContact传输对象
 */
class ExportContactDTO : public AddContactDTO
{
	DTO_INIT(ExportContactDTO, AddContactDTO);

	// 客户姓名
	DTO_FIELD(String, customer_name);
	DTO_FIELD_INFO(customer_name) {
		info->description = ZH_WORDS_GETTER("contact.field.customer_name");
	}
	// 归属人姓名
	DTO_FIELD(String, owner_user_name);
	DTO_FIELD_INFO(owner_user_name) {
		info->description = ZH_WORDS_GETTER("contact.field.owner_user_name");
	}
	
	// 创建时间
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("contact.field.create_time");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // EXPORTCONTACTDTO_H__