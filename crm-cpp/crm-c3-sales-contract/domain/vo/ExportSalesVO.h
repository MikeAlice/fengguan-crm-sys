#pragma once

#include "domain/GlobalInclude.h"
#include "domain/dto/ExportSalesDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 用于响应给客户端的Json对象
 */
class ExportSalesJsonVO : public JsonVO<ExportSalesDTO::Wrapper> {
	DTO_INIT(ExportSalesJsonVO, JsonVO<ExportSalesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
