#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _DICTCLASSIFY_DO_
#define _DICTCLASSIFY_DO_
#include "../DoInclude.h"


class DictClassifyDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	//分类名称
	CC_SYNTHESIZE(string, typeName, TypeName);
	//分类目录
	CC_SYNTHESIZE(string, typedir, Typedir);
	//调用标识
	CC_SYNTHESIZE(string, typetag, Typetag);
	//排序
	CC_SYNTHESIZE(uint64_t, sort, Sort);
	//启用
	CC_SYNTHESIZE(uint64_t, visible, Visible);
	//简介
	CC_SYNTHESIZE(string, intro, Intro);
	//下级层数设置只能为数字不能重复
	CC_SYNTHESIZE(uint64_t, seotitle, Seotitle);
	//层数提成比例
	CC_SYNTHESIZE(uint64_t, keywords, Keywords);

public:
	 DictClassifyDO() {
		id = 0;
		typeName = " ";
		typedir = "";
		typetag = "";
		sort = 0;
		visible = 0;
		intro = "";
		seotitle = 0;
		keywords = 0;
	}
};
class DictClassifyListDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	CC_SYNTHESIZE(string, typetag, Typetag);
	//分类名称
	CC_SYNTHESIZE(string, typeName, TypeName);
public:
	DictClassifyListDO() {
		id = 0;
		typeName = "typename";
		typetag = "";
	}
};
//class DictRemoveDO
//{
//	// 编号
//	CC_SYNTHESIZE(uint64_t, id, Id);
//
//public:
//	DictRemoveDO() {
//		id = 0;
//	
//	}
//};
#endif // !_DICTCLASSIFTY_DO