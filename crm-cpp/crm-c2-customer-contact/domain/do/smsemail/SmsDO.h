#ifndef _SMS_DO_
#define _SMS_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class SmsDO
{
	//编号
	CC_SYNTHESIZE(string, node, Node);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 联系手机
	CC_SYNTHESIZE(string, mobile, Mobile);
public:
	SmsDO() {
		node = "";
		name = "";
		mobile = "";
	}
};

#endif // !_SMS_DO_
