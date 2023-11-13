#pragma once
#ifndef _CONTACTAMOUNT_QUERY_
#define _CONTACTAMOUNT_QUERY_

#include "../../GlobalInclude.h"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询用户信息的数据传输模型
 */
class ContractamountQuery : public oatpp::DTO
{
	// 定义初始化
	DTO_INIT(ContractamountQuery, DTO);
	// 合同id
	DTO_FIELD(UInt64, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = ZH_WORDS_GETTER("pay.field.contact_id");
	}
	// 查询类型 付款 OR 回款
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("pay.field.type");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PAYMENTPLANQUERY_H_