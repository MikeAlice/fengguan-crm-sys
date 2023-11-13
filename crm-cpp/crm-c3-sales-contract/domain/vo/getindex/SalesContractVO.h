#pragma once
/*
* @Anther: Glasscats
* @Date: 2023/10/24
*/
#ifndef __SalesContract_VO
#define __SalesContract_VO

#include "domain/GlobalInclude.h"
#include "domain/dto/getindex/SalesContractDTO.h"
#include "domain/dto/getindex/SalesContractDetailDTO.h"

#include "../../GlobalInclude.h"
#include "../../dto/getindex/SalesContractDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 销售合同列表显示JsonVO，用于响应给客户端的Json对象
 */
class SalesContractJsonVO : public JsonVO<SalesContractDTO::Wrapper> {
	DTO_INIT(SalesContractJsonVO, JsonVO<SalesContractDTO::Wrapper>);
};

/**
* 销售合同详细列表显示JsonVO，用于响应给客户端的Json对象
*/
class SalesContractDetailJsonVO : public JsonVO<SalesContractDetailDTO::Wrapper> {
	DTO_INIT(SalesContractDetailJsonVO, JsonVO<SalesContractDetailDTO::Wrapper>);
};

/**
 * 销售合同列表分页显示JsonVO，用于响应给客户端的Json对象
 */
class SalesContractPageJsonVO : public JsonVO<SalesContractPageDTO::Wrapper> {
	DTO_INIT(SalesContractPageJsonVO, JsonVO<SalesContractPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !__SalesContract_VO
