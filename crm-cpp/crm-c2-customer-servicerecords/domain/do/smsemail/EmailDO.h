#ifndef _EMAIL_DO_
#define _EMAIL_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class EmailDO
{
	//编号
	CC_SYNTHESIZE(string, node, Node);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 电子邮箱
	CC_SYNTHESIZE(string, email, Email);
public:
	EmailDO() {
		node = "";
		name = "";
		email = "";
	}
};

#endif // !_EMAIL_DO_

