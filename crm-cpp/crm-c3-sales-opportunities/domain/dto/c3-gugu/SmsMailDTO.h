#pragma once
#ifndef _MailDTO_H_
#define _MailDTO_H_
#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class MailDTO :public oatpp::DTO
{
	DTO_INIT(MailDTO, DTO);

	//��Ϣ����
	API_DTO_FIELD_DEFAULT(UInt64, mess_type, ZH_WORDS_GETTER("opportunities.field.smsemail.mess_type"));
	//�ռ�������
	API_DTO_FIELD_DEFAULT(String, recv_name, ZH_WORDS_GETTER("opportunities.field.smsemail.recv_name"));
	//��ͬ����
	API_DTO_FIELD_DEFAULT(String, chance_name, ZH_WORDS_GETTER("opportunities.field.smsemail.chance_name"));
	//�ռ�������
	API_DTO_FIELD_DEFAULT(String, mail, ZH_WORDS_GETTER("opportunities.field.smsemail.mail"));
	//��չ��Ϣ
	API_DTO_FIELD_DEFAULT(String, mess, ZH_WORDS_GETTER("opportunities.field.smsemail.mess"));


};


class SmsDTO :public oatpp::DTO
{
	DTO_INIT(SmsDTO, DTO);

	//��Ϣ����
	API_DTO_FIELD_DEFAULT(UInt64, mess_type, ZH_WORDS_GETTER("opportunities.field.smsemail.mess_type"));
	//�ռ�������
	API_DTO_FIELD_DEFAULT(String, recv_name, ZH_WORDS_GETTER("opportunities.field.smsemail.recv_name"));
	//��ͬ����
	API_DTO_FIELD_DEFAULT(String, chance_name, ZH_WORDS_GETTER("opportunities.field.smsemail.chance_name"));
	//�ռ����ֻ���
	API_DTO_FIELD_DEFAULT(String, phone, ZH_WORDS_GETTER("opportunities.field.smsemail.phone"));
	//��չ��Ϣ
	API_DTO_FIELD_DEFAULT(String, mess, ZH_WORDS_GETTER("opportunities.field.smsemail.mess"));



};


#include OATPP_CODEGEN_END(DTO)


#endif // !_MODIFYPWDDTO_H_
