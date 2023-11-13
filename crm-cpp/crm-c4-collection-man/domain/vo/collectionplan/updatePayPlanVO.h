#pragma once
#ifndef _UPDATEPAYPLAN_VO_
#define _UPDATEPAYPLAN_VO_

#include "../../GlobalInclude.h"
#include "../../dto/collectionplan/updatePayPlanDTO.h"
#include "../../dto/collectionplan/updateConfirmPlanDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class updatePayPlanJsonVO : public JsonVO<updatePayPlanDTO::Wrapper> {
	DTO_INIT(updatePayPlanJsonVO, JsonVO<updatePayPlanDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class updatePayPlanPageJsonVO : public JsonVO<updatePayPlanDTO::Wrapper> {
	DTO_INIT(updatePayPlanPageJsonVO, JsonVO<updatePayPlanDTO::Wrapper>);
};

class updateConfirmPlanJsonVO : public JsonVO<updateConfirmPlanDTO::Wrapper> {
	DTO_INIT(updateConfirmPlanJsonVO, JsonVO<updateConfirmPlanDTO::Wrapper>);
};

class updateConfirmPlanPageJsonVO : public JsonVO<updateConfirmPlanDTO::Wrapper> {
	DTO_INIT(updateConfirmPlanJsonVO, JsonVO<updateConfirmPlanDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPDATEPAYPLAN_VO_