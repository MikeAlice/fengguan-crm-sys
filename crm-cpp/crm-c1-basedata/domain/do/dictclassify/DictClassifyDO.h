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
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	//��������
	CC_SYNTHESIZE(string, typeName, TypeName);
	//����Ŀ¼
	CC_SYNTHESIZE(string, typedir, Typedir);
	//���ñ�ʶ
	CC_SYNTHESIZE(string, typetag, Typetag);
	//����
	CC_SYNTHESIZE(uint64_t, sort, Sort);
	//����
	CC_SYNTHESIZE(uint64_t, visible, Visible);
	//���
	CC_SYNTHESIZE(string, intro, Intro);
	//�¼���������ֻ��Ϊ���ֲ����ظ�
	CC_SYNTHESIZE(uint64_t, seotitle, Seotitle);
	//������ɱ���
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
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	CC_SYNTHESIZE(string, typetag, Typetag);
	//��������
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
//	// ���
//	CC_SYNTHESIZE(uint64_t, id, Id);
//
//public:
//	DictRemoveDO() {
//		id = 0;
//	
//	}
//};
#endif // !_DICTCLASSIFTY_DO