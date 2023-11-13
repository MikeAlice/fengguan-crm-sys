#pragma once
/*
* 负责人：老菌
*/

#ifndef _LISTCONTACT_DO_
#define _LISTCONTACT_DO_
#include "../DoInclude.h"

/**
 * 获取联系人列表实体类
 */
class ListContactDO
{
	// 联系人编号
	CC_SYNTHESIZE(uint64_t, linkman_id, Linkman_Id);
	// 客户姓名
	CC_SYNTHESIZE(string, customer_name, Customer_Name);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
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

public:
	ListContactDO() {
		linkman_id = 0;
		customer_name = "";
		name = "";
		gender = 1;
		postion = "";
		tel = "";
		mobile = "";
		qicq = "";
	}
};
#endif // !_LISTCONTACT_DO_