#pragma once

#include "domain/GlobalInclude.h"
#include "domain/dto/outboundindex/OutBoundDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ������Ӧ���ͻ��˵�Json����
 */
class OutBoundJsonVO : public JsonVO<OutBoundDTO::Wrapper> {
	DTO_INIT(OutBoundJsonVO, JsonVO<OutBoundDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
