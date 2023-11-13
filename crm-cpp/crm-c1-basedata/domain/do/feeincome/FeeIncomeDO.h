#pragma once
#ifndef _FeeIncome_DO_
#define _FeeIncome_DO_
#include "../DoInclude.h"

/**
 * 费用收入类型数据库实体类
 */
class FeeIncomeDO
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
	FeeIncomeDO() {
		id = 0;
		name = "";
		parentid = 0;
		sort = 0;
		visible = 1;
		intro = "";
	}
};

#endif // !_SAMPLE_DO_