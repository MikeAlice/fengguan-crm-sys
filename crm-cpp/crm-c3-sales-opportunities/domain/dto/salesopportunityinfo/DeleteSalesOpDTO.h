#pragma once
#ifndef _DELETESALESOPDTO_H_
#define _DELETESALESOPDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 删除销售机会传输对象
*/
class DeleteSalesOpDTO : public oatpp::DTO {

	DTO_INIT(DeleteSalesOpDTO, DTO);

	// 销售机会id
	API_DTO_FIELD_DEFAULT(Int32, chance_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"));

};

#include OATPP_CODEGEN_END(DTO)

#endif