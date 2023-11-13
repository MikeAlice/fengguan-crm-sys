#pragma once
#ifndef _OPPORTUNITYQUERY_H_
#define _OPPORTUNITYQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "ApiHelper.h"


#include OATPP_CODEGEN_BEGIN(DTO)


//定义一个查询销售机会的数据传输模型
class OpportunityQuery : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(OpportunityQuery, DTO);
	//销售机会id  唯一标识
	API_DTO_FIELD_DEFAULT(Int64, chance_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"));
};

#include OATPP_CODEGEN_END(DTO)

#endif