#pragma once
#ifndef _CONTRACTAMOUNT_VO_
#define _CONTRACTAMOUNT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/contractamount/ContractamountDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ContractamountJsonVO : public JsonVO<ContractamountDTO::Wrapper> {
	DTO_INIT(ContractamountJsonVO, JsonVO<ContractamountDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CONTRACTAMOUNT_VO_