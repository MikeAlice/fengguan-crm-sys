#pragma once
#ifndef EXPORTCONTACTQUERY_H__
#define EXPORTCONTACTQUERY_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������ϵ�˴������
 */
class ExportContactQuery : public oatpp::DTO
{
	DTO_INIT(ExportContactQuery, DTO);

	// ������id
	DTO_FIELD(UInt32, owner_user_id);
	DTO_FIELD_INFO(owner_user_id) {
		info->description = ZH_WORDS_GETTER("contact.field.owner_user_id");
	}

	// ��ϵ�˴�����id
	DTO_FIELD(UInt32, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("contact.field.create_user_id");
	}

	// ��ϵ��id�б�
	DTO_FIELD(List<UInt32>, linkman_id);
	DTO_FIELD_INFO(linkman_id) {
		info->description = ZH_WORDS_GETTER("contact.field.linkman_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // EXPORTCONTACTQUERY_H__