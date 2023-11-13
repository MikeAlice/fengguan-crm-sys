#pragma once
#ifndef _LISTDTO_H_
#define _LISTDTO_H_

#include "../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 公用列表DTO模板
 * 负责人: 会跑的鱼
 */
template <typename T>
class ListDTO : public oatpp::DTO
{
	DTO_INIT(ListDTO, DTO);
	//服务记录列表
	DTO_FIELD(String, item_list);
	DTO_FIELD_INFO(item_list) {
		info->description = ZH_WORDS_GETTER("common-usage.field.item_list");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LISTDTO_H_