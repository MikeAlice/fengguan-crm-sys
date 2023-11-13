#pragma once
#ifndef _BANKACCOUNT_QUERY_
#define _BANKACCOUNT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class BankAccountQuery : public PageQuery
{
	DTO_INIT(BankAccountQuery, PageQuery);
	//编号
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.bank_id");
	}
	// 开户银行名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.name");
	}
	//银行卡号
	DTO_FIELD(UInt64, card);
	DTO_FIELD_INFO(card) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.card");
	}
	// 银行地址
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.address");
	}
	// 开户人
	DTO_FIELD(String, holders);
	DTO_FIELD_INFO(holders) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.holders");
	}
	//排序
	DTO_FIELD(Int64, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.sort");
	}
	//是否启用
	DTO_FIELD(Int64, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.visible");
	}
};
class BankAccountListQuery :public PageQuery
{

	DTO_INIT(BankAccountListQuery, PageQuery);
	//编号
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.bank_id");
	}
	// 开户银行名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.name");
	}
	//银行卡号
	DTO_FIELD(UInt64, card);
	DTO_FIELD_INFO(card) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.card");
	}


};
#include OATPP_CODEGEN_END(DTO)
#endif // !_BANKACCOUNT_QUERY_