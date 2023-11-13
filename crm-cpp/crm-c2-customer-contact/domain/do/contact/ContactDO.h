#ifndef _CONTACT_DO_
#define _CONTACT_DO_
#include "../DoInclude.h"

/**
 * 联系人数据库实体类
 */
class ContactDO
{
	// 联系人编号
	CC_SYNTHESIZE(uint64_t, linkman_id, Linkman_id);
	// 客户编号
	CC_SYNTHESIZE(uint64_t, customer_id, Customer_id);
	// 姓名
	CC_SYNTHESIZE(string, linkman_name, Linkman_name);
	// 性别
	CC_SYNTHESIZE(uint64_t, gender, Gender);
	// 职位
	CC_SYNTHESIZE(string, postion, Postion);
	// 座机
	CC_SYNTHESIZE(string, tel, Tel);
	// 手机
	CC_SYNTHESIZE(string, mobile, Mobile);
	// qq
	CC_SYNTHESIZE(string, qicq, Qicq);
	// 电子邮箱
	CC_SYNTHESIZE(string, email, Email);
	// 邮政编码
	CC_SYNTHESIZE(string, zipcode, Zipcode);
	// 地址
	CC_SYNTHESIZE(string, address, Address);
	// 介绍
	CC_SYNTHESIZE(string, intro, Intro);
	// 创建人id
	CC_SYNTHESIZE(uint64_t, create_user_id, Create_user_id);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 客户姓名
	CC_SYNTHESIZE(string, customer_name, Customer_name);
	// 归属人姓名
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