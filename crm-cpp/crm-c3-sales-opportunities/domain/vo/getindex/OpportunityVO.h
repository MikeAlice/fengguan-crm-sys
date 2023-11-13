#pragma once

#ifndef _OPPORTUNITYVO_H_
#define _OPPORTUNITYVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/getindex/OpportunityDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//����һ�����ۻ�����ʾJsonVO����������Ӧ���ͻ���
class OpportunityJsonVO : public JsonVO<OpportunityDTO::Wrapper>
{
	DTO_INIT(OpportunityJsonVO, JsonVO<OpportunityDTO::Wrapper>);
};

//����һ�����ۻ����ҳ��ʾJsonVO����������Ӧ���ͻ���
class OpportunityPageJsonVO : public JsonVO<OpportunityPageDTO::Wrapper>
{
	DTO_INIT(OpportunityPageJsonVO, JsonVO<OpportunityPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_