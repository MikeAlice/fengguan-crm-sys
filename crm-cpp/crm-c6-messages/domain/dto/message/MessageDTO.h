#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/27 10:25:47

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
#ifndef _MESSAGEDTO_H_
#define _MESSAGEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ���ܣ��ʼ�����DTO
 * ִ���ˣ�Detachment
**/
class MailDTO : public oatpp::DTO
{
	DTO_INIT(MailDTO, DTO);
	/**
	 * ��Ϣ����
	 * 1������ף����Ϣ
	 * 2����Ʒ�Ƽ���Ϣ
	 * 3����ͬ������Ϣ
	 * 4����ϵ��ԤԼ������Ϣ 
	 * 5�������¼ԤԼ������Ϣ
	 * 6�����ۻ���ԤԼ������Ϣ 
	 * 7�����ټ�¼ԤԼ������Ϣ
	 * 8����Ӧ����ϵ��ԤԼ������Ϣ
	 **/   
	API_DTO_FIELD(UInt64, mess_type, ZH_WORDS_GETTER("message.field.mess_type"), true, 1)
	// �ռ�������
	API_DTO_FIELD(String, recv_name, ZH_WORDS_GETTER("message.field.recv_name"), true, "123")
	// ��ͬ����
	API_DTO_FIELD(String, contrast_name, ZH_WORDS_GETTER("message.field.con_name"), false, "")
	// �ͻ�����
	API_DTO_FIELD(String, mail, ZH_WORDS_GETTER("message.field.mail"), true, "123")
	// ��չ��Ϣ
	API_DTO_FIELD(String, mess, ZH_WORDS_GETTER("message.field.mess"),true,"123")
};
/**
 * ���ܣ����ŷ���DTO
 * ִ���ˣ�Detachment
**/
class SMSDTO : public oatpp::DTO
{
	DTO_INIT(SMSDTO, DTO);
	// ��Ϣ����
	API_DTO_FIELD(UInt64, mess_type, ZH_WORDS_GETTER("message.field.mess_type"), true, 1)
	// �ռ�������
	API_DTO_FIELD(String, recv_name, ZH_WORDS_GETTER("message.field.recv_name"), true, "123")
	// ��ͬ����
	API_DTO_FIELD(String, contrast_name, ZH_WORDS_GETTER("message.field.con_name"), false, "")
	// �ͻ��绰
	API_DTO_FIELD(String, phone, ZH_WORDS_GETTER("message.field.phone"), true, "123")
	// ��չ��Ϣ
	API_DTO_FIELD(String, mess, ZH_WORDS_GETTER("message.field.mess"), true, "123")
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MESSAGEDTO_H_