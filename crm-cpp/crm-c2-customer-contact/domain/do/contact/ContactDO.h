#ifndef _CONTACT_DO_
#define _CONTACT_DO_
#include "../DoInclude.h"

/**
 * ��ϵ�����ݿ�ʵ����
 */
class ContactDO
{
	// ��ϵ�˱��
	CC_SYNTHESIZE(uint64_t, linkman_id, Linkman_id);
	// �ͻ����
	CC_SYNTHESIZE(uint64_t, customer_id, Customer_id);
	// ����
	CC_SYNTHESIZE(string, linkman_name, Linkman_name);
	// �Ա�
	CC_SYNTHESIZE(uint64_t, gender, Gender);
	// ְλ
	CC_SYNTHESIZE(string, postion, Postion);
	// ����
	CC_SYNTHESIZE(string, tel, Tel);
	// �ֻ�
	CC_SYNTHESIZE(string, mobile, Mobile);
	// qq
	CC_SYNTHESIZE(string, qicq, Qicq);
	// ��������
	CC_SYNTHESIZE(string, email, Email);
	// ��������
	CC_SYNTHESIZE(string, zipcode, Zipcode);
	// ��ַ
	CC_SYNTHESIZE(string, address, Address);
	// ����
	CC_SYNTHESIZE(string, intro, Intro);
	// ������id
	CC_SYNTHESIZE(uint64_t, create_user_id, Create_user_id);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// �ͻ�����
	CC_SYNTHESIZE(string, customer_name, Customer_name);
	// ����������
	CC_SYNTHESIZE(string, owner_user_name, Owner_user_name);
public:
	ContactDO() {
		linkman_id = 1;
		customer_id = 1;
		linkman_name = "";
		gender = 1;
		postion = "";
		tel = "";
		mobile = "";
		qicq = "";
		email = "";
		zipcode = "";
		address = "";
		intro = "";
		create_user_id = 1;
		create_time = "";
		customer_name = "";
		owner_user_name = "";
	}
};
#endif // !_CONTACT_DO_