#pragma once
/*
* 负责人：老菌
*/
#include "stdafx.h"
#ifndef _CONTACTFIELD_DO_
#define _CONTACTFIELD_DO_
#include "../DoInclude.h"

/**
 * 客户信息实体类  对应客户信息表
 */
class ContactFieldDO
{
	// 客户ID
	CC_SYNTHESIZE(int32_t, customer_id, Customer_Id);
	// 联系人姓名
	CC_SYNTHESIZE(string, link_name,Link_Name);
	// 联系人性别  姓别1=男，0=女
	CC_SYNTHESIZE(int32_t, gender, Gender);
	// 联系人职位
	CC_SYNTHESIZE(string, postion, Postion);
	// 联系人电话
	CC_SYNTHESIZE(string, tel, Tel);
	// 联系人手机
	CC_SYNTHESIZE(string, mobile, Mobile);
	// 联系人QQ
	CC_SYNTHESIZE(string, qicq, Qicq);
	// 联系人邮箱
	CC_SYNTHESIZE(string, email, Email);
	// 联系人邮编
	CC_SYNTHESIZE(string, zipcode, Zipcode);
	// 联系人地址
	CC_SYNTHESIZE(string, address, Address);
	// 联系人介绍
	CC_SYNTHESIZE(string, intro, Intro);
	// 创建人员
	CC_SYNTHESIZE(int32_t, create_user_id, Create_User_Id);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_Time);
	// 客户名称
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