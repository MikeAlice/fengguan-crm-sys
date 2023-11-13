#pragma once
/*
* 负责人：老菌
*/
#include "stdafx.h"
#ifndef _SYSTEMUSER_DO_
#define _SYSTEMUSER_DO_
#include "../DoInclude.h"

/**
 * 系统用户实体类  对应系统用户表
 */
class SystemUserDO
{
	// 系统用户ID
	CC_SYNTHESIZE(int32_t, id, Id);
	// 登录账号
	CC_SYNTHESIZE(string, account, Account);
	// 登录密码
	CC_SYNTHESIZE(string, password, password);
	// 用户姓名
	CC_SYNTHESIZE(string, name, Name);
	// 用户性别
	CC_SYNTHESIZE(string, gender, Gender);
	// 用户电话
	CC_SYNTHESIZE(string, tel, Tel);
	// 用户手机
	CC_SYNTHESIZE(string, mobile, Mobile);
	// 用户QQ
	CC_SYNTHESIZE(string, qicq, Qicq);
	// 用户地址
	CC_SYNTHESIZE(string, address, Address);
	// 用户邮编
	CC_SYNTHESIZE(string, zipcode, Zipcode);
	// 用户邮件
	CC_SYNTHESIZE(string, email, Email);
	// 角色ID
	CC_SYNTHESIZE(string, roleID, RoleID);
	// 部门ID
	CC_SYNTHESIZE(int32_t, deptID, DeptID);
	// 职位ID
	CC_SYNTHESIZE(int32_t, positionID, PositionID);
	// 用户介绍
	CC_SYNTHESIZE(string, intro, Intro);
	// 用户创建时间
	CC_SYNTHESIZE(string, adt, Adt);
	// 用户身份
	CC_SYNTHESIZE(string, identity, Identity);
	// 账号状态 0=正常，1=冻结
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
