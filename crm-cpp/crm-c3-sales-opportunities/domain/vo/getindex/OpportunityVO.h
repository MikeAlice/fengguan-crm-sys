#pragma once

#ifndef _OPPORTUNITYVO_H_
#define _OPPORTUNITYVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/getindex/OpportunityDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//定义一个销售机会显示JsonVO对象，用于响应给客户端
class OpportunityJsonVO : public JsonVO<OpportunityDTO::Wrapper>
{
	DTO_INIT(OpportunityJsonVO, JsonVO<OpportunityDTO::Wrapper>);
};

//定义一个销售机会分页显示JsonVO对象，用于响应给客户端
class OpportunityPageJsonVO : public JsonVO<OpportunityPageDTO::Wrapper>
{
	DTO_INIT(OpportunityPageJsonVO, JsonVO<OpportunityPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_