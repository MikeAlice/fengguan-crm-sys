#pragma once
#ifndef UPDATECONTACTDTO_H__
#define UPDATECONTACTDTO_H__
#include "../../GlobalInclude.h"
#include "AddContactDTO.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * UpdateContact�������
 */		
class UpdateContactDTO : public AddContactDTO
{
	DTO_INIT(UpdateContactDTO, AddContactDTO);

	// ��ϵ��ID
	API_DTO_FIELD_DEFAULT(UInt32, linkman_id, ZH_WORDS_GETTER("contact.field.linkman_id"));

	
};

#include OATPP_CODEGEN_END(DTO)
#endif // UPDATECONTACTDTO_H__	