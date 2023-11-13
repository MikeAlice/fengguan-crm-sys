#pragma once

#ifndef _EXEPENSETYPE_QUERY_
#define _EXEPENSETYPE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class ExpenseTypeQuery : public PageQuery
{
	DTO_INIT(ExpenseTypeQuery, PageQuery);
	// 编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("expensetype.field.id");
	}
	// 分类名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("expensetype.field.name");
	}
	// 父级栏目
	DTO_FIELD(UInt64, parentID);
	DTO_FIELD_INFO(parentID) {
		info->description = ZH_WORDS_GETTER("expensetype.field.parentID");
	}
	// 排位序号
	DTO_FIELD(Int32, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("expensetype.field.sort");
	}
	// 是否启用
	DTO_FIELD(Int32, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("expensetype.field.visible");
	}
	// 介绍
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("expensetype.field.intro");
	}
};
/**
 * 费用支出类型分页查询对象
 */
class ExpenseQuery : public PageQuery
{
	DTO_INIT(ExpenseQuery, PageQuery);

	// 查询深度
	DTO_FIELD(Int32, depth);
	DTO_FIELD_INFO(depth) {
		info->description = ZH_WORDS_GETTER("expense.field.depth");
	}
	// 父类ID
	DTO_FIELD(Int32, parentid);
	DTO_FIELD_INFO(parentid) {
		info->description = ZH_WORDS_GETTER("expense.field.parentid");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_EXEPENSETYPE_QUERY_