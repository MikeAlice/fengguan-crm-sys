#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _SENDMESSAGEDECL_DTO_
#define _SENDMESSAGEDECL_DTO_
#include "../../GlobalInclude.h"
#include "../ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ���÷����ʼ�����ʽ�����DTO
 */
class SendMessageDeclDTO :public oatpp::DTO {
	DTO_INIT(SendMessageDeclDTO, DTO);
	// ��Ϣ����
	API_DTO_FIELD_DEFAULT(UInt64, mess_type, ZH_WORDS_GETTER("supplier-linkman.basic-data.field.show-name"));
	// �ռ�������
	API_DTO_FIELD_DEFAULT(String, recv_name, ZH_WORDS_GETTER("supplier-linkman.basic-data.field.field-name"));
	// ��ͬ����
	API_DTO_FIELD_DEFAULT(String, contrast_name, ZH_WORDS_GETTER("supplier-linkman.basic-data.field.field-type"));
	// �ռ����ֻ���
	API_DTO_FIELD_DEFAULT(String, phone, ZH_WORDS_GETTER("supplier-linkman.basic-data.field.default"));
	// ��չ��Ϣ
	API_DTO_FIELD_DEFAULT(String, mess, ZH_WORDS_GETTER("supplier-linkman.basic-data.field.default"));

};

class SendMessageDeclListDTO : public ListDTO<SendMessageDeclDTO::Wrapper>
{
	DTO_INIT(SendMessageDeclListDTO, ListDTO<SendMessageDeclDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif 