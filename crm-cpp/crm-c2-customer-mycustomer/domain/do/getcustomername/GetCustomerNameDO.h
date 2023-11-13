#include "stdafx.h"
#ifndef _GETCUSTOMERNAME_DO_
#define _GETCUSTOMERNAME_DO_
#include "../DoInclude.h"

/**
 * �ͻ���Ϣʵ����  ��Ӧ�ͻ���Ϣ��
 */
class GetCustomerNameDO
{
	// �ͻ�ID
	CC_SYNTHESIZE(int32_t, customer_id, Customer_Id);
	// �ͻ�����
	CC_SYNTHESIZE(string, name, Name);
	// �ͻ����
	CC_SYNTHESIZE(string, customer_no, Customer_No);
	// ������Ա
	CC_SYNTHESIZE(int32_t, create_user_id, Create_User_Id);
	// ������Ա
	CC_SYNTHESIZE(int32_t, owner_user_id, Owner_User_Id);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_Time);
	// �´ι�ͨʱ��
	CC_SYNTHESIZE(string, next_time, Next_Time);
	// �����ϵʱ��
	CC_SYNTHESIZE(string, conn_time, Conn_Time);
	// �����ͨ����
	CC_SYNTHESIZE(string, conn_body, Conn_Body);
	// �ͻ�����
	CC_SYNTHESIZE(string, linkman, Linkman);
	// �ͻ���Դ
	CC_SYNTHESIZE(string, source, Source);
	// �ͻ��ȼ�
	CC_SYNTHESIZE(string, grade, Grade);
	// �ͻ���ҵ
	CC_SYNTHESIZE(string, industry, Industry);
	// ��ϵ�ֻ�
	CC_SYNTHESIZE(string, mobile, Mobile);
	// ��ϵ�绰
	CC_SYNTHESIZE(string, tel, Tel);
	// ��ϵ��ַ
	CC_SYNTHESIZE(string, address, Address);
	// �ͻ�����
	CC_SYNTHESIZE(string, intro, Intro);
	// �ͻ�����
	CC_SYNTHESIZE(string, needs, Needs);
public:
	GetCustomerNameDO() {
		customer_id = 0;
		name = "";
		customer_no = "";
		create_user_id = 0;
		owner_user_id = 0;
		create_time = "";
		next_time = "";
		conn_time = "";
		conn_body = "";
		linkman = "";
		source = "";
		grade = "";
		industry = "";
		mobile = "";
		tel = "";
		address = "";
		intro = "";
		needs = "";
	}
};
#endif // !_GETCUSTOMERNAME_DO_

