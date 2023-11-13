#pragma once
#ifndef _CONTRACTAMOUNT_VO_
#define _CONTRACTAMOUNT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/contractamount/ContractamountDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ContractamountJsonVO : public JsonVO<ContractamountDTO::Wrapper> {
	DTO_INIT(ContractamountJsonVO, JsonVO<ContractamountDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CONTRACTAMOUNT_VO_