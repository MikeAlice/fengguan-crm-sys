#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _DICTCLASSIFY_QUERY_
#define _DICTCLASSIFY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class DictClassifyQuery : public PageQuery
{
	DTO_INIT(DictClassifyQuery, PageQuery);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("dictclassify.field.id");
	}
	// ��������
	DTO_FIELD(String, typeName);
	DTO_FIELD_INFO(typeName) {
		info->description = ZH_WORDS_GETTER("dictclassify.field.typename");
	}
	// ����Ŀ¼
	DTO_FIELD(String, typedir);
	DTO_FIELD_INFO(typedir) {
		info->description = ZH_WORDS_GETTER("dictclassify.field.typedir");
	}
	// ���ñ�ʶ
	DTO_FIELD(String, typetag);
	DTO_FIELD_INFO(typetag) {
		info->description = ZH_WORDS_GETTER("dictclassify.field.typetag");
	}
	//����
	DTO_FIELD(UInt64, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("dictclassify.field.sort");
	}
	//����
	DTO_FIELD(UInt64, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("dictclassify.field.visible");
	}
	//���
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("dictclassify.field.intro");
	}
	//�¼���������ֻ��Ϊ���ֲ����ظ�
	DTO_FIELD(UInt64, seotitle);
	DTO_FIELD_INFO(seotitle) {
		info->description = ZH_WORDS_GETTER("dictclassify.field.seotitle");
	}
	//������ɱ���
	DTO_FIELD(UInt64, keywords);
	DTO_FIELD_INFO(keywords) {
		info->description = ZH_WORDS_GETTER("dictclassify.field.keywords");
	}
};
class DictClassifyListQuery : public PageQuery
{
	DTO_INIT(DictClassifyQuery, PageQuery);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("dictclassify.field.id");
	}
	// ��������
	DTO_FIELD(String, typeName);
	DTO_FIELD_INFO(typeName) {
		info->description = ZH_WORDS_GETTER("dictclassify.field.typename");
	}
	// ���ñ�ʶ
	DTO_FIELD(String, typetag);
	DTO_FIELD_INFO(typetag) {
		info->description = ZH_WORDS_GETTER("dictclassify.field.typetag");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DICTCLASSIFY_QUERY_