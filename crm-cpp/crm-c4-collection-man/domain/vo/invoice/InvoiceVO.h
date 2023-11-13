#pragma once
#ifndef _INVOCIE_VO_
#define _INVOICE_VO_

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/dto/invoice/InvoiceDTO.h"
//#include "../../domain/dto/invoice/InvoiceDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class InvoiceJsonVO : public JsonVO<InvoiceDTO::Wrapper> {
	DTO_INIT(InvoiceJsonVO, JsonVO<InvoiceDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class InvoicePageJsonVO : public JsonVO<InvoicePageDTO::Wrapper> {
	DTO_INIT(InvoicePageJsonVO, JsonVO<InvoicePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_