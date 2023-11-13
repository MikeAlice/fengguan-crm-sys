#pragma once

#ifndef _NUMBERCOUNTINGVO_H_
#define _NUMBERCOUNTINGVO_H_

#include"../../GlobalInclude.h"
#include "../../dto/saleskit/NumberCountingDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ͳ����������������Ӧ���ͻ��˵�Json����
*/
class NumberCountingJsonVO :public JsonVO< NumberCountingDTO::Wrapper>
{
	DTO_INIT(NumberCountingJsonVO, JsonVO< NumberCountingDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // _NUMBERCOUNTINGVO_H_


