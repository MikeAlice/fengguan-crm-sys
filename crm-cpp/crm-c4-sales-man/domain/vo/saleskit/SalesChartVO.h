#pragma once

#ifndef _SALESCHARTVO_H_
#define _SALESCHARTVO_H_

#include"../../GlobalInclude.h"
#include "../../dto/saleskit/SalesChartDTO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 销售榜对象,用于响应给客户端的Json对象
*/
class SalesChartJsonVO :public JsonVO<SalesChartDTO::Wrapper>
{
	DTO_INIT(SalesChartJsonVO, JsonVO<SalesChartDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SALESCHARTVO_H_


