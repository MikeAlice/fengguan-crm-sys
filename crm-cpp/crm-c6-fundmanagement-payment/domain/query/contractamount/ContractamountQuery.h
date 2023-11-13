#pragma once
#ifndef _CONTACTAMOUNT_QUERY_
#define _CONTACTAMOUNT_QUERY_

#include "../../GlobalInclude.h"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class ContractamountQuery : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(ContractamountQuery, DTO);
	// ��ͬid
	DTO_FIELD(UInt64, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = ZH_WORDS_GETTER("pay.field.contact_id");
	}
	// ��ѯ���� ���� OR �ؿ�
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("pay.field.type");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PAYMENTPLANQUERY_H_