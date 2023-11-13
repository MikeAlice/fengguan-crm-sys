#pragma once

#ifndef _AWAITCUSTOMERS_VO_
#define _AWAITCUSTOMERS_VO_
#include "../../GlobalInclude.h"
#include "../../dto/await/awaitpayments.h"
// 用于响应给客户端的Json对象
#include OATPP_CODEGEN_BEGIN(DTO)
class FINDAWAPAYJsonVO : public JsonVO<FINDAWAPAYDTO::Wrapper> {
	DTO_INIT(FINDAWAPAYJsonVO, JsonVO<FINDAWAPAYDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class FINDAWAPAYPAGEJsonVO : public JsonVO<FINDAWAPAYPageDTO::Wrapper> {
	DTO_INIT(FINDAWAPAYPAGEJsonVO, JsonVO<FINDAWAPAYPageDTO::Wrapper>);
};

// 用于响应给客户端的Json对象
class FINDAWACUSTJsonVO : public JsonVO<FINDAWACUSTDTO::Wrapper> {
	DTO_INIT(FINDAWACUSTJsonVO, JsonVO<FINDAWACUSTDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class FINDAWACUSTPAYPAGEJsonVO : public JsonVO<FINDAWACUSTDTOPageDTO::Wrapper> {
	DTO_INIT(FINDAWACUSTPAYPAGEJsonVO, JsonVO<FINDAWACUSTDTOPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif