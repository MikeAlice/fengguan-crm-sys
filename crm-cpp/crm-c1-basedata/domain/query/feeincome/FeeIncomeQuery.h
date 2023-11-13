#pragma once
#ifndef _FeeIncome_QUERY_
#define _FeeIncome_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����������ͷ�ҳ��ѯ����
 */
class FeeIncomeQuery : public PageQuery
{
	DTO_INIT(FeeIncomeQuery, PageQuery);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("finincometype.field.id");
	}
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("finincometype.field.name");
	}
	// ������Ŀ
	DTO_FIELD(UInt64, parentID);
	DTO_FIELD_INFO(parentID) {
		info->description = ZH_WORDS_GETTER("feeincometype.field.parentID");
	}
	// �������
	DTO_FIELD(UInt64, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("feeincometype.field.sort");
	}
	// �Ƿ�����
	DTO_FIELD(Int32, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("feeincometype.field.visible");
	}
	// ���
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("feeincometype.field.intro");
	}
	// ��������
	DTO_FIELD(Int32, depth);
	DTO_FIELD_INFO(depth) {
		info->description = ZH_WORDS_GETTER("feeincome.field.name");
	}
	// ����ID
	DTO_FIELD(Int32, parentid);
	DTO_FIELD_INFO(parentid) {
		info->description = ZH_WORDS_GETTER("feeincome.field.parentid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_