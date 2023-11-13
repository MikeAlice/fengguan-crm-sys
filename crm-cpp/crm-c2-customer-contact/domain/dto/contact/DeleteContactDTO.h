#pragma once
#ifndef DELETECONTACTDTO_H__
#define DELETECONTACTDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ɾ����ϵ�˴������
 */
class DeleteContactDTO : public oatpp::DTO
{
	DTO_INIT(DeleteContactDTO, DTO);
	
	// ��ϵ��id
	DTO_FIELD(List<UInt32>, linkman_id);
	DTO_FIELD_INFO(linkman_id) {
		info->description = ZH_WORDS_GETTER("contact.field.linkman_id");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // DELETECONTACTDTO_H__