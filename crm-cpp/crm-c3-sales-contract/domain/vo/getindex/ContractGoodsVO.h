#pragma once
#ifndef _CONTRACTGOODS_VO_
#define _CONTRACTGOODS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/getindex/ContractGoodsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 原味的原味包
 * 合同清单显示JsonVO，用于响应给客户端的Json对象
 */
class ContractGoodsJsonVO : public JsonVO<ContractGoodsDTO::Wrapper> {
	DTO_INIT(ContractGoodsJsonVO, JsonVO<ContractGoodsDTO::Wrapper>);

};

/**
* 原味的原味包
 * 合同清单分页显示JsonVO，用于响应给客户端的Json对象
 */
class ContractGoodsPageJsonVO : public JsonVO<ContractGoodsPageDTO::Wrapper> {
	DTO_INIT(ContractGoodsPageJsonVO, JsonVO<ContractGoodsPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif