#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/24 20:18:25

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _CSTFIELDEXT_H_
#define _CSTFIELDEXT_H_

#include "../DoInclude.h"

/**
 * 字段扩展数据库实体类
 * 负责人: Andrew
 */
class CstFieldExtDO
{
	// 字段表单名称
	CC_SYNTHESIZE(string, show_name, ShowName);
	// 字段名称
	CC_SYNTHESIZE(string, field_name, FieldName);
	// 字段类型
	CC_SYNTHESIZE(string, field_type, FieldType);
	// 默认值
	CC_SYNTHESIZE(string, default_value, DefaultValue);
	// 是否必填
	CC_SYNTHESIZE(uint8_t, is_must, IsMust);
};

#endif // !_CSTFIELDEXT_H_