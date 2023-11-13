//狗皮电耗子
//2023年10月23日
//基础客户信息的DO
#pragma once
#ifndef _CUSTORMER_BASE_INFO_DO_
#define _CUSTORMER_BASE_INFO_DO_
#include "../DoInclude.h"

class CustormerBaseInfo {
	CC_SYNTHESIZE(string, linkman, LinkMan);
	CC_SYNTHESIZE(string, source, Source);
	CC_SYNTHESIZE(string, grade, Grade);
	CC_SYNTHESIZE(string, industry, Industry);
	CC_SYNTHESIZE(string, mobile, Mobile);
	CC_SYNTHESIZE(string, tel, Tel);
	CC_SYNTHESIZE(string, address, Address);
	CC_SYNTHESIZE(string, intro, Intro);
	CC_SYNTHESIZE(string, needs, Needs);
public:
	CustormerBaseInfo() {
		linkman = "No-Link";
		source = "No-source";
		grade = "";
		industry = "";
		mobile = "";
		tel = "";
		address = "";
		intro = "";
		needs = "";
	}
};

#endif
