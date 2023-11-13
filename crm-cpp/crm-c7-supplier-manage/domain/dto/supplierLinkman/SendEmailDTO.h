#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2023/10/26 13:25:19

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
#ifndef _SENDEMAILDTO_H_
#define _SENDEMAILDTO_H_

#include "../../GlobalInclude.h"
#include "../ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SendEmailRecvDTO : public oatpp::DTO
{
	DTO_INIT(SendEmailRecvDTO, DTO)
	// ��Ӧ����ϵ��ID�б�
	API_DTO_FIELD_DEFAULT(oatpp::List<UInt64>, id_list, ZH_WORDS_GETTER("supplier-linkman.send-email.field.id"))
	// �ʼ�����
	API_DTO_FIELD_DEFAULT(UInt64, type, ZH_WORDS_GETTER("supplier-linkman.send-email.field.email-type"))
	// �ʼ���չ����
	API_DTO_FIELD_DEFAULT(String, mess, ZH_WORDS_GETTER("supplier-linkman.send-email.field.mess"))
};

// �����ݿ���Һ󷵻ص�DTO
class SendEmailSendDTO : public oatpp::DTO
{
	DTO_INIT(SendEmailSendDTO, DTO)
	// ��Ϣ����
	API_DTO_FIELD_DEFAULT(UInt64, mess_type, ZH_WORDS_GETTER("supplier-linkman.send-email.field.mess-type"))
	// �ռ�������
	API_DTO_FIELD_DEFAULT(String, recv_name, ZH_WORDS_GETTER("supplier-linkman.send-email.field.name-list"))
	// ��ͬ����
	API_DTO_FIELD_DEFAULT(String, contrast_name, ZH_WORDS_GETTER("supplier-linkman.send-email.field.contrast_name"))
	// �ռ�������
	API_DTO_FIELD_DEFAULT(String, mail, ZH_WORDS_GETTER("supplier-linkman.send-email.field.email"))
	// ��չ��Ϣ
	API_DTO_FIELD_DEFAULT(String, mess, ZH_WORDS_GETTER("supplier-linkman.send-email.field.mess"))
};

// SendEmailDTO�б�
class SendEmailListSendDTO : public ListDTO<SendEmailSendDTO::Wrapper>
{
	DTO_INIT(SendEmailListSendDTO, ListDTO<SendEmailListSendDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SENDEMAILDTO_H_