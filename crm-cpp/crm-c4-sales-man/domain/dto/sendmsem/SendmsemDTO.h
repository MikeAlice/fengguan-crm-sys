/*
 Copyright Zero One Star. All rights reserved.

 @Author: william
 @Date: 2023/10/27 11:22:53

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
#ifndef _SENDMSEMDTO_H_
#define _SENDMSEMDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class InfoDTO : public oatpp::DTO
{
	DTO_INIT(InfoDTO, DTO);
	//��Ϣ����
	DTO_FIELD(Int64, mess_type);
	DTO_FIELD_INFO(mess_type) {
		info->description = ZH_WORDS_GETTER("send.field.mess_type");
	}
	//�ռ���
	DTO_FIELD(String, recv_name);
	DTO_FIELD_INFO(recv_name) {
		info->description = ZH_WORDS_GETTER("send.field.recv_name");
	}
	//��ͬ��
	DTO_FIELD(String, contrast_name);
	DTO_FIELD_INFO(contrast_name) {
		info->description = ZH_WORDS_GETTER("send.field.contrast_name");
	}
	// ��Ϣ
	DTO_FIELD(String, mess);
	DTO_FIELD_INFO(mess) {
		info->description = ZH_WORDS_GETTER("send.field.mess");
	}
	//�绰
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("send.field.phone");
	}
	// ����
	DTO_FIELD(String, mail);
	DTO_FIELD_INFO(mail) {
		info->description = ZH_WORDS_GETTER("send.field.mail");
	}
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SENDMSEMDTO_H_