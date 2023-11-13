#pragma once
#ifndef _DICTTPYE_DO_
#define _DICTTPYE_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类-字典管理
 */
class DictTypeDO 
{
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 字典分类名称
	CC_SYNTHESIZE(string, name, Name);

public:
	DictTypeDO() {
		id = 0;
		name = "";
	}
};

#endif // !_DICTTPYE_DO_