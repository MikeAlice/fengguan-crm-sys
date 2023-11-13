#pragma once

#ifndef _SALESCHARTVO_H_
#define _SALESCHARTVO_H_

#include"../../GlobalInclude.h"
#include "../../dto/saleskit/SalesChartDTO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ���۰����,������Ӧ���ͻ��˵�Json����
*/
class SalesChartJsonVO :public JsonVO<SalesChartDTO::Wrapper>
{
	DTO_INIT(SalesChartJsonVO, JsonVO<SalesChartDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SALESCHARTVO_H_


