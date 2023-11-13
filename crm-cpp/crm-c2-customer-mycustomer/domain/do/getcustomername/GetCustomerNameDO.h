#include "stdafx.h"
#ifndef _GETCUSTOMERNAME_DO_
#define _GETCUSTOMERNAME_DO_
#include "../DoInclude.h"

/**
 * 客户信息实体类  对应客户信息表
 */
class GetCustomerNameDO
{
	// 客户ID
	CC_SYNTHESIZE(int32_t, customer_id, Customer_Id);
	// 客户姓名
	CC_SYNTHESIZE(string, name, Name);
	// 客户编号
	CC_SYNTHESIZE(string, customer_no, Customer_No);
	// 创建人员
	CC_SYNTHESIZE(int32_t, create_user_id, Create_User_Id);
	// 归属人员
	CC_SYNTHESIZE(int32_t, owner_user_id, Owner_User_Id);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_Time);
	// 下次沟通时间
	CC_SYNTHESIZE(string, next_time, Next_Time);
	// 最近联系时间
	CC_SYNTHESIZE(string, conn_time, Conn_Time);
	// 最近沟通内容
	CC_SYNTHESIZE(string, conn_body, Conn_Body);
	// 客户代表
	CC_SYNTHESIZE(string, linkman, Linkman);
	// 客户来源
	CC_SYNTHESIZE(string, source, Source);
	// 客户等级
	CC_SYNTHESIZE(string, grade, Grade);
	// 客户行业
	CC_SYNTHESIZE(string, industry, Industry);
	// 联系手机
	CC_SYNTHESIZE(string, mobile, Mobile);
	// 联系电话
	CC_SYNTHESIZE(string, tel, Tel);
	// 联系地址
	CC_SYNTHESIZE(string, address, Address);
	// 客户介绍
	CC_SYNTHESIZE(string, intro, Intro);
	// 客户需求
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

