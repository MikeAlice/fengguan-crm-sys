#pragma once
#ifndef _Sms_Mail_DO_
#define _Sms_Mail_DO_
#include "../DoInclude.h"
#include"stdafx.h"
class EmailDO
{
	//收件人姓名
	CC_SYNTHESIZE(string, recv_name, Recv_Name);
	//机会名称
	CC_SYNTHESIZE(string, chance_name, Chance_Name);
	//收件人地址
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
	//收件人姓名
	CC_SYNTHESIZE(string, recv_name, Recv_Name);
	//机会名称
	CC_SYNTHESIZE(string, chance_name, Chance_Name);
	//收件人地址
	CC_SYNTHESIZE(string, phone, Phone);

public:
	SmsDO() {

		recv_name = "";
		chance_name = "";
		phone = "";
	}
};
#endif