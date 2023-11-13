#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/18 15:01:29

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
#ifndef _DICTCLASSIFYDTO_H_
#define _DICTCLASSIFYDTO_H_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
	����ֵ����
*/

class DictClassifyDTO : public oatpp::DTO
{
	DTO_INIT(DictClassifyDTO,DTO);
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
class DictClassifyListDTO : public oatpp::DTO
{
	DTO_INIT(DictClassifyListDTO, DTO);

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
//�����б�����


//class DictRemoveDTO : public oatpp::DTO {
//
//	DTO_INIT(DictRemoveDTO, DTO);
//	DTO_FIELD(List<DictRemoveDTO>, rows) = {};
//	DTO_FIELD_INFO(rows) {
//#ifndef LINUX
//		info->description = u8"ɾ���б�";
//#else
//		info->description = "removelist";
//#endif
//	}
//	DTO_FIELD(UInt64, id);
//	DTO_FIELD_INFO(id) {
//		info->description = ZH_WORDS_GETTER("dictclassify.field.id");
//	}
//
//};
/**
 * ʾ����ҳ�������
 */
class DictClassifyPageDTO : public PageDTO<DictClassifyDTO::Wrapper>
{
	DTO_INIT(DictClassifyPageDTO, PageDTO<DictClassifyDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DICTCLASSIFYDTO_H_ 