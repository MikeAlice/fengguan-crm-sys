#pragma once
#ifndef _FeeIncome_DTO_
#define _FeeIncome_DTO_
#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * �����������ʹ������
 */
class FeeIncomeDTO : public oatpp::DTO
{
	DTO_INIT(FeeIncomeDTO, DTO);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("feeincome.field.id");
	}
	// ��������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("feeincome.field.name");
	}
	// ����ID
	DTO_FIELD(UInt64, parentid);
	DTO_FIELD_INFO(parentid) {
		info->description = ZH_WORDS_GETTER("feeincome.field.parentid");
	}
	// ��λ���
	DTO_FIELD(UInt64, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("feeincome.field.sort");
	}
	//�Ƿ�����
	DTO_FIELD(UInt64, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("feeincome.field.visible");
	}
	//���
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("feeincome.field.intro");
	}


};

/**
 * �����������ͽṹ�����ݴ������
 */
class FeeIncomeTreeDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(FeeIncomeTreeDTO, DTO);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("feeincome.field.id");
	}
	// ��������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("feeincome.field.name");
	}
	// ����ID
	DTO_FIELD(UInt64, parentid);
	DTO_FIELD_INFO(parentid) {
		info->description = ZH_WORDS_GETTER("feeincome.field.parentid");
	}
	// ��λ���
	DTO_FIELD(UInt64, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("feeincome.field.sort");
	}
	//�Ƿ�����
	DTO_FIELD(UInt64, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("feeincome.field.visible");
	}
	//���
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("feeincome.field.intro");
	}

	// �ӽڵ�
	API_DTO_FIELD(List<FeeIncomeTreeDTO::Wrapper>, children, ZH_WORDS_GETTER("feeincome.field.child"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<FeeIncomeTreeDTO>(child), Wrapper::Class::getType()));
	}
};
class FeeIncomePageDTO : public PageDTO<FeeIncomeDTO::Wrapper>
{
	DTO_INIT(FeeIncomePageDTO, PageDTO<FeeIncomeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_FreeIncome_DTO_