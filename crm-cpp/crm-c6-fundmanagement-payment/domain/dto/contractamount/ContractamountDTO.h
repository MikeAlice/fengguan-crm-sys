#pragma once
#ifndef _CONTRACTAMOUNT_DTO_
#define _CONTRACTAMOUNT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ContractamountDTO : public oatpp::DTO
{
	DTO_INIT(ContractamountDTO, DTO);
	// 总金额
	API_DTO_FIELD_DEFAULT(UInt64, total_money, ZH_WORDS_GETTER("contractamount.field.total_money"));
	// 去零金额
	API_DTO_FIELD_DEFAULT(UInt64, zero_money, ZH_WORDS_GETTER("contractamount.field.zero_money"));
	// 已付金额
	API_DTO_FIELD_DEFAULT(UInt64, paid_money, ZH_WORDS_GETTER("contractamount.field.paid_money"));
	// 已收发票金额
	API_DTO_FIELD_DEFAULT(UInt64, invoice_money, ZH_WORDS_GETTER("contractamount.field.invoice_money"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CONTRACTAMOUNT_DTO_