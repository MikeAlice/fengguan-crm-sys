#pragma once
#ifndef _CONTRACTAMOUNT_DTO_
#define _CONTRACTAMOUNT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class ContractamountDTO : public oatpp::DTO
{
	DTO_INIT(ContractamountDTO, DTO);
	// �ܽ��
	API_DTO_FIELD_DEFAULT(UInt64, total_money, ZH_WORDS_GETTER("contractamount.field.total_money"));
	// ȥ����
	API_DTO_FIELD_DEFAULT(UInt64, zero_money, ZH_WORDS_GETTER("contractamount.field.zero_money"));
	// �Ѹ����
	API_DTO_FIELD_DEFAULT(UInt64, paid_money, ZH_WORDS_GETTER("contractamount.field.paid_money"));
	// ���շ�Ʊ���
	API_DTO_FIELD_DEFAULT(UInt64, invoice_money, ZH_WORDS_GETTER("contractamount.field.invoice_money"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CONTRACTAMOUNT_DTO_