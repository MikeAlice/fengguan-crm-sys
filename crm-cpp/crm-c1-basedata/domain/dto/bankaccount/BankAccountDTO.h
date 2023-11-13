#pragma once
#ifndef _BANKACCOUNT_DTO__
#define _BANKACCOUNT_DTO__
#include "../../GlobalInclude.h"
#include<list>
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例银行账户传输对象
 */
class BankAccountDTO : public oatpp::DTO
{
	DTO_INIT(BankAccountDTO, DTO);
	// 编号
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.bank_id");
	}
	// 开户银行名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.name");
	}
	// 银行账号
	DTO_FIELD(Int64, card);
	DTO_FIELD_INFO(card) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.card");
	}
	// 银行地址
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.address");
	}
	//开户人
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
class BankAccountListDTO : public oatpp::DTO
{
	DTO_INIT(BankAccountListDTO, DTO);
	// 编号
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.bank_id");
	}
	// 开户银行名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.name");
	}
	// 银行账号
	DTO_FIELD(Int64, card);
	DTO_FIELD_INFO(card) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.card");
	}
};
/**
 * 示例分页传输对象
 */
class BankAccountPageDTO : public PageDTO<BankAccountDTO::Wrapper>
{
	DTO_INIT(BankAccountPageDTO, PageDTO<BankAccountDTO::Wrapper>);
};
class BankAccountExportDTO : public oatpp::DTO {
	DTO_INIT(BankAccountExportDTO, DTO);
	// 编号
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.bank_id");
	}
	// 开户银行名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.name");
	}
	// 银行账号
	DTO_FIELD(Int64, card);
	DTO_FIELD_INFO(card) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.card");
	}
	// 银行地址
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.address");
	}
	//开户人
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
//s
#include OATPP_CODEGEN_END(DTO)
#endif // !_BANKACCOUNT_DTO_