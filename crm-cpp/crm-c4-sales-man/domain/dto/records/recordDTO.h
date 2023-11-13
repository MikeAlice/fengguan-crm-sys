#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _USERDTO_H_
#define _USERDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ��׷�ټ�¼�����ݴ���ģ��
 */
class RecordDTO : public oatpp::DTO
{
	DTO_INIT(RecordDTO, DTO);
	// ���
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("record.field.id"));
	//��ϵʱ��
	API_DTO_FIELD_DEFAULT(String, contactTime, ZH_WORDS_GETTER("record.field.contactTime"));
	//�ͻ�����
	API_DTO_FIELD_DEFAULT(String, customName, ZH_WORDS_GETTER("record.field.customName"));
	//��ͨ����
	API_DTO_FIELD_DEFAULT(String, contents, ZH_WORDS_GETTER("record.field.contents"));
	//������Ա
	API_DTO_FIELD_DEFAULT(String, recorderName, ZH_WORDS_GETTER("record.field.recorderName"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_