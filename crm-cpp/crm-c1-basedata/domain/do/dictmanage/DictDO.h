#pragma once

#ifndef _DICT_DO_
#define _DICT_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类-字典管理
 */
class DictDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 字典名称
	CC_SYNTHESIZE(string, name, Name);
	// 分类名称
	CC_SYNTHESIZE(string, typetag, Typetag);
	// 排序
	CC_SYNTHESIZE(int, sort, Sort);
	// 是否启用
	CC_SYNTHESIZE(int, visible, Visible);
public:
	DictDO() {
		id = 0;
		name = "";
		typetag = "";
		sort = 1;
		visible = 0;
	}
};

#endif // !_DICT_DO_