#pragma once
/*
* �����ˣ��Ͼ�
*/
#include "stdafx.h"
#ifndef _SYSTEMUSER_DO_
#define _SYSTEMUSER_DO_
#include "../DoInclude.h"

/**
 * ϵͳ�û�ʵ����  ��Ӧϵͳ�û���
 */
class SystemUserDO
{
	// ϵͳ�û�ID
	CC_SYNTHESIZE(int32_t, id, Id);
	// ��¼�˺�
	CC_SYNTHESIZE(string, account, Account);
	// ��¼����
	CC_SYNTHESIZE(string, password, password);
	// �û�����
	CC_SYNTHESIZE(string, name, Name);
	// �û��Ա�
	CC_SYNTHESIZE(string, gender, Gender);
	// �û��绰
	CC_SYNTHESIZE(string, tel, Tel);
	// �û��ֻ�
	CC_SYNTHESIZE(string, mobile, Mobile);
	// �û�QQ
	CC_SYNTHESIZE(string, qicq, Qicq);
	// �û���ַ
	CC_SYNTHESIZE(string, address, Address);
	// �û��ʱ�
	CC_SYNTHESIZE(string, zipcode, Zipcode);
	// �û��ʼ�
	CC_SYNTHESIZE(string, email, Email);
	// ��ɫID
	CC_SYNTHESIZE(string, roleID, RoleID);
	// ����ID
	CC_SYNTHESIZE(int32_t, deptID, DeptID);
	// ְλID
	CC_SYNTHESIZE(int32_t, positionID, PositionID);
	// �û�����
	CC_SYNTHESIZE(string, intro, Intro);
	// �û�����ʱ��
	CC_SYNTHESIZE(string, adt, Adt);
	// �û����
	CC_SYNTHESIZE(string, identity, Identity);
	// �˺�״̬ 0=������1=����
	CC_SYNTHESIZE(int32_t, status, Status);
public:
	SystemUserDO() {
		id = 0;
		account = "";
		password = "";
		name = "";
		gender = "";
		tel = "";
		mobile = "";
		qicq = "";
		address = "";
		zipcode = "";
		email = "";
		roleID = "";
		deptID = 0;
		positionID = 0;
		intro = "";
		adt = "";
		identity = "";
		status = 0;
	}
};
#endif // !_SYSTEMUSER_DO_
