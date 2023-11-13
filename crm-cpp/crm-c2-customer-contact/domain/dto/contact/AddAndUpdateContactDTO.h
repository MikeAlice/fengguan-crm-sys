#pragma once
#ifndef ADDANDUPDATECONTACTDTO_H__
#define ADDANDUPDATECONTACTDTO_H__
#include "../../GlobalInclude.h"
#include "ListContactDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加和修改联系人传输对象
 */
class AddAndUpdateContactDTO : public ListContactDTO
{
	DTO_INIT(AddAndUpdateContactDTO, ListContactDTO);

	// 联系人性别
	DTO_FIELD(UInt32, gender);
	DTO_FIELD_INFO(gender) {
		info->description = ZH_WORDS_GETTER("contact.field.gender");
	}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // ADDANDUPDATECONTACTDTO_H__