//狗皮电耗子
//2023年10月27日
//客户基础信息的VO相应给客户端
#pragma once
#ifndef _CusTormerJsonVO_
#define _CusTormerJsonVO_

#include "domain/vo/CuatormerJsonVO.h"
#include "domain/dto/custormer/CustormerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CustomerJsonVO : public JsonVO<CustormerDTO::Wrapper>
{
	DTO_INIT(CustomerJsonVO, JsonVO<CustormerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CusTormerJsonVO_
