#pragma once
#ifndef _Sms_Mail_DO_
#define _Sms_Mail_DO_
#include "../DoInclude.h"
#include"stdafx.h"
class EmailDO
{
	//�ռ�������
	CC_SYNTHESIZE(string, recv_name, Recv_Name);
	//��������
	CC_SYNTHESIZE(string, chance_name, Chance_Name);
	//�ռ��˵�ַ
	CC_SYNTHESIZE(string, mail, Mail);

public:
	EmailDO() {
		recv_name = "";
		chance_name = "";
		mail = "";
	}
};

class SmsDO
{
	//�ռ�������
	CC_SYNTHESIZE(string, recv_name, Recv_Name);
	//��������
	CC_SYNTHESIZE(string, chance_name, Chance_Name);
	//�ռ��˵�ַ
	CC_SYNTHESIZE(string, phone, Phone);

public:
	SmsDO() {

		recv_name = "";
		chance_name = "";
		phone = "";
	}
};
#endif