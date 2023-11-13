#pragma once

#ifndef _EXEPENSETYPE_QUERY_
#define _EXEPENSETYPE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class ExpenseTypeQuery : public PageQuery
{
	DTO_INIT(ExpenseTypeQuery, PageQuery);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("expensetype.field.id");
	}
	// ��������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("expensetype.field.name");
	}
	// ������Ŀ
	DTO_FIELD(UInt64, parentID);
	DTO_FIELD_INFO(parentID) {
		info->description = ZH_WORDS_GETTER("expensetype.field.parentID");
	}
	// ��λ���
	DTO_FIELD(Int32, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("expensetype.field.sort");
	}
	// �Ƿ�����
	DTO_FIELD(Int32, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("expensetype.field.visible");
	}
	// ����
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("expensetype.field.intro");
	}
};
/**
 * ����֧�����ͷ�ҳ��ѯ����
 */
class ExpenseQuery : public PageQuery
{
	DTO_INIT(ExpenseQuery, PageQuery);

	// ��ѯ���
	DTO_FIELD(Int32, depth);
	DTO_FIELD_INFO(depth) {
		info->description = ZH_WORDS_GETTER("expense.field.depth");
	}
	// ����ID
	DTO_FIELD(Int32, parentid);
	DTO_FIELD_INFO(parentid) {
		info->description = ZH_WORDS_GETTER("expense.field.parentid");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_EXEPENSETYPE_QUERY_