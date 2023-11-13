#pragma once
#ifndef _BANKACCOUNT_DTO__
#define _BANKACCOUNT_DTO__
#include "../../GlobalInclude.h"
#include<list>
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ�������˻��������
 */
class BankAccountDTO : public oatpp::DTO
{
	DTO_INIT(BankAccountDTO, DTO);
	// ���
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.bank_id");
	}
	// ������������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.name");
	}
	// �����˺�
	DTO_FIELD(Int64, card);
	DTO_FIELD_INFO(card) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.card");
	}
	// ���е�ַ
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.address");
	}
	//������
	DTO_FIELD(String, holders);
	DTO_FIELD_INFO(holders) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.holders");
	}
	//����
	DTO_FIELD(Int64, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.sort");
	}
	//�Ƿ�����
	DTO_FIELD(Int64, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.visible");
	}
};
class BankAccountListDTO : public oatpp::DTO
{
	DTO_INIT(BankAccountListDTO, DTO);
	// ���
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.bank_id");
	}
	// ������������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.name");
	}
	// �����˺�
	DTO_FIELD(Int64, card);
	DTO_FIELD_INFO(card) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.card");
	}
};
/**
 * ʾ����ҳ�������
 */
class BankAccountPageDTO : public PageDTO<BankAccountDTO::Wrapper>
{
	DTO_INIT(BankAccountPageDTO, PageDTO<BankAccountDTO::Wrapper>);
};
class BankAccountExportDTO : public oatpp::DTO {
	DTO_INIT(BankAccountExportDTO, DTO);
	// ���
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.bank_id");
	}
	// ������������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.name");
	}
	// �����˺�
	DTO_FIELD(Int64, card);
	DTO_FIELD_INFO(card) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.card");
	}
	// ���е�ַ
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.address");
	}
	//������
	DTO_FIELD(String, holders);
	DTO_FIELD_INFO(holders) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.holders");
	}
	//����
	DTO_FIELD(Int64, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.sort");
	}
	//�Ƿ�����
	DTO_FIELD(Int64, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.visible");
	}
};
//s
#include OATPP_CODEGEN_END(DTO)
#endif // !_BANKACCOUNT_DTO_