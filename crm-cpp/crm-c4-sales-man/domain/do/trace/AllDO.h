#pragma once
#ifndef _ALL_DO_
#define _ALL_DO_
#include "../DoInclude.h"
#include "TraceDO.h"

class AllDO : public TraceDO {
	//客户销售机会
	CC_SYNTHESIZE(string, Chancename, ChanceName);
	//客户名称
	CC_SYNTHESIZE(string, Customername, CName);
	//联系人名称
	CC_SYNTHESIZE(string, Linkmanname, LName);
	//当前阶段
	CC_SYNTHESIZE(string, Stagename, NName);
	//沟通方式
	CC_SYNTHESIZE(string, ConWayname, ConName);

	CC_SYNTHESIZE(string, TraceId, TraceId);
	
public:
	AllDO() {
		Chancename = "123";
		Customername = "123";
		Linkmanname = "123";
		Stagename = "123";
		ConWayname = "123";
	}
};

#endif // !_SAMPLE_DO_
