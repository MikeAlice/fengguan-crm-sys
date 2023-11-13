#pragma once
#ifndef _SELAMOUNTINFO_DTO_
#define _SELAMOUNTINFO_DTO_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取合同金额信息
 */
class SelectAmountInfoDTO : public oatpp::DTO
{
	DTO_INIT(SelectAmountInfoDTO, DTO);

	//金额信息
	API_DTO_FIELD_DEFAULT(Float64, totalamount, ZH_WORDS_GETTER("paybackmanage.field.totalamount"));
	API_DTO_FIELD_DEFAULT(Float64, zeroamount, ZH_WORDS_GETTER("paybackmanage.field.zeroamount"));
	API_DTO_FIELD_DEFAULT(Float64, refundedamount, ZH_WORDS_GETTER("paybackmanage.field.refundedamount"));
	API_DTO_FIELD_DEFAULT(Float64, invoicedamount, ZH_WORDS_GETTER("paybackmanage.field.invoicedamount"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_