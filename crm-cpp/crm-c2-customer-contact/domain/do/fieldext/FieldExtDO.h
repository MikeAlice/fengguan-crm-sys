#pragma once
/*
* 负责人：老菌
*/
#include "stdafx.h"
#ifndef _FIELDEXT_DO_
#define _FIELDEXT_DO_
#include "../DoInclude.h"

/**
 * 扩展字段实体类 对应字段扩展表
 */
class FieldExtDO
{
	// 是否启用字段   1表示启用,2表示禁用
	CC_SYNTHESIZE(int32_t, visible, Visible);


public:
	FieldExtDO() {
		visible = 0;
	}
};
#endif // !_CUSTOMEREXT_DO_
