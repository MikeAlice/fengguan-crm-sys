#pragma once
#ifndef ADDANDUPDATECONTACTDTO_H__
#define ADDANDUPDATECONTACTDTO_H__
#include "../../GlobalInclude.h"
#include "ListContactDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ӻ��޸���ϵ�˴������
 */
class AddAndUpdateContactDTO : public ListContactDTO
{
	DTO_INIT(AddAndUpdateContactDTO, ListContactDTO);

	// ��ϵ���Ա�
	DTO_FIELD(UInt32, gender);
	DTO_FIELD_INFO(gender) {
		info->description = ZH_WORDS_GETTER("contact.field.gender");
	}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // ADDANDUPDATECONTACTDTO_H__