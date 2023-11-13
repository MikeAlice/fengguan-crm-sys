#pragma once
#ifndef _EXPENSETYPE_DO_
#define _EXPENSETYPE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ExpenseTypeDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 分类名称
	CC_SYNTHESIZE(string, name, Name);
	// 父级栏目
	CC_SYNTHESIZE(uint64_t, parentID, ParentID);
	// 排位序号
	CC_SYNTHESIZE(int, sort, Sort);
	// 是否启用
	CC_SYNTHESIZE(int, visible, Visible);
	// 介绍
	CC_SYNTHESIZE(string, intro, Intro);
public:
	ExpenseTypeDO() {
		id = 0;
		name = "";
		sort = 0;
		visible = 1;
		intro = "";
	}
};
/**
 * 费用支出类型数据库实体类
 */
class ExpenseDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 分类名称
	CC_SYNTHESIZE(string, name, Name);
	// 父类ID
	CC_SYNTHESIZE(uint64_t, parentid, Parentid);
	// 排位序号
	CC_SYNTHESIZE(int, sort, Sort);
	// 是否启用
	CC_SYNTHESIZE(int, visible, Visible);
	//简介
	CC_SYNTHESIZE(string, intro, Intro);

public:
	ExpenseDO() {
		id = 0;
		name = "";
		parentid = 0;
		sort = 0;
		visible = 1;
		intro = "";
	}
};
#endif // !_EXPENSETYPE_DO_
