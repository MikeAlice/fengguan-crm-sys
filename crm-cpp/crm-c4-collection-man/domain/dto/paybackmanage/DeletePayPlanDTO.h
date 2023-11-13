#pragma once
#ifndef _DELPAYPLAN_DTO
#define _DELPAYPLAN_DTO
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 删除回款计划（支持列表）数据传输对象
 */

class DeletePayPlanDTO : public oatpp::DTO
{
	DTO_INIT(DeletePayPlanDTO, DTO)

	//删除对应ID（单个/列表）
	API_DTO_FIELD_DEFAULT(Vector<UInt64>, listid, ZH_WORDS_GETTER("paybackmanage.field.listid"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_