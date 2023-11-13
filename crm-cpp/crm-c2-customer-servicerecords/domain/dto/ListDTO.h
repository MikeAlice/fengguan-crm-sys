#pragma once
#ifndef _LISTDTO_H_
#define _LISTDTO_H_

#include "../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б�DTOģ��
 * ������: ���ܵ���
 */
template <typename T>
class ListDTO : public oatpp::DTO
{
	DTO_INIT(ListDTO, DTO);
	//�����¼�б�
	DTO_FIELD(String, item_list);
	DTO_FIELD_INFO(item_list) {
		info->description = ZH_WORDS_GETTER("common-usage.field.item_list");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LISTDTO_H_