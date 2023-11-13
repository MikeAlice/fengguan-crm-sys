#pragma once
/*
* �����ˣ��Ͼ�
*/
#include "stdafx.h"
#ifndef _CONTACTFIELD_DO_
#define _CONTACTFIELD_DO_
#include "../DoInclude.h"

/**
 * �ͻ���Ϣʵ����  ��Ӧ�ͻ���Ϣ��
 */
class ContactFieldDO
{
	// �ͻ�ID
	CC_SYNTHESIZE(int32_t, customer_id, Customer_Id);
	// ��ϵ������
	CC_SYNTHESIZE(string, link_name,Link_Name);
	// ��ϵ���Ա�  �ձ�1=�У�0=Ů
	CC_SYNTHESIZE(int32_t, gender, Gender);
	// ��ϵ��ְλ
	CC_SYNTHESIZE(string, postion, Postion);
	// ��ϵ�˵绰
	CC_SYNTHESIZE(string, tel, Tel);
	// ��ϵ���ֻ�
	CC_SYNTHESIZE(string, mobile, Mobile);
	// ��ϵ��QQ
	CC_SYNTHESIZE(string, qicq, Qicq);
	// ��ϵ������
	CC_SYNTHESIZE(string, email, Email);
	// ��ϵ���ʱ�
	CC_SYNTHESIZE(string, zipcode, Zipcode);
	// ��ϵ�˵�ַ
	CC_SYNTHESIZE(string, address, Address);
	// ��ϵ�˽���
	CC_SYNTHESIZE(string, intro, Intro);
	// ������Ա
	CC_SYNTHESIZE(int32_t, create_user_id, Create_User_Id);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_Time);
	// �ͻ�����
	//CC_SYNTHESIZE(string, customer_name, Customer_Name);


public:
	ContactFieldDO() {
		customer_id = 0;
		link_name = "";
		gender = 0;
		postion = "";
		tel = "";
		mobile = "";
		qicq = "";
		email = "";
		zipcode = "";
		address = "";
		intro = "";
		create_user_id = 0;
		create_time = "";
	}
};
#endif // !_CONTACTFIELD_DO_