#pragma once
#ifndef _FeeIncome_DTO_
#define _FeeIncome_DTO_
#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 费用收入类型传输对象
 */
class FeeIncomeDTO : public oatpp::DTO
{
	DTO_INIT(FeeIncomeDTO, DTO);
	// 编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("feeincome.field.id");
	}
	// 分类名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("feeincome.field.name");
	}
	// 父类ID
	DTO_FIELD(UInt64, parentid);
	DTO_FIELD_INFO(parentid) {
		info->description = ZH_WORDS_GETTER("feeincome.field.parentid");
	}
	// 排位序号
	DTO_FIELD(UInt64, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("feeincome.field.sort");
	}
	//是否启用
	DTO_FIELD(UInt64, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("feeincome.field.visible");
	}
	//简介
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("feeincome.field.intro");
	}


};

/**
 * 费用收入类型结构树数据传输对象
 */
class FeeIncomeTreeDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(FeeIncomeTreeDTO, DTO);
	// 编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("feeincome.field.id");
	}
	// 分类名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("feeincome.field.name");
	}
	// 父类ID
	DTO_FIELD(UInt64, parentid);
	DTO_FIELD_INFO(parentid) {
		info->description = ZH_WORDS_GETTER("feeincome.field.parentid");
	}
	// 排位序号
	DTO_FIELD(UInt64, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("feeincome.field.sort");
	}
	//是否启用
	DTO_FIELD(UInt64, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("feeincome.field.visible");
	}
	//简介
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("feeincome.field.intro");
	}

	// 子节点
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