#pragma once

#include "domain/GlobalInclude.h"
#include "domain/dto/ExportSalesDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ������Ӧ���ͻ��˵�Json����
 */
class ExportSalesJsonVO : public JsonVO<ExportSalesDTO::Wrapper> {
	DTO_INIT(ExportSalesJsonVO, JsonVO<ExportSalesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
