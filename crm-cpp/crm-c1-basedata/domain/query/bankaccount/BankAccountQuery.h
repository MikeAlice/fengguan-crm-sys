#pragma once
#ifndef _BANKACCOUNT_QUERY_
#define _BANKACCOUNT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class BankAccountQuery : public PageQuery
{
	DTO_INIT(BankAccountQuery, PageQuery);
	//���
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.bank_id");
	}
	// ������������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.name");
	}
	//���п���
	DTO_FIELD(UInt64, card);
	DTO_FIELD_INFO(card) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.card");
	}
	// ���е�ַ
	DTO_FIELD(String, address);
	DTO_FIELD_INFO(address) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.address");
	}
	// ������
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
class BankAccountListQuery :public PageQuery
{

	DTO_INIT(BankAccountListQuery, PageQuery);
	//���
	DTO_FIELD(UInt64, bank_id);
	DTO_FIELD_INFO(bank_id) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.bank_id");
	}
	// ������������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.name");
	}
	//���п���
	DTO_FIELD(UInt64, card);
	DTO_FIELD_INFO(card) {
		info->description = ZH_WORDS_GETTER("bankaccount.field.card");
	}


};
#include OATPP_CODEGEN_END(DTO)
#endif // !_BANKACCOUNT_QUERY_