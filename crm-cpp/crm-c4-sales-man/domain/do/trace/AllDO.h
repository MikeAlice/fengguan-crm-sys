#pragma once
#ifndef _ALL_DO_
#define _ALL_DO_
#include "../DoInclude.h"
#include "TraceDO.h"

class AllDO : public TraceDO {
	//�ͻ����ۻ���
	CC_SYNTHESIZE(string, Chancename, ChanceName);
	//�ͻ�����
	CC_SYNTHESIZE(string, Customername, CName);
	//��ϵ������
	CC_SYNTHESIZE(string, Linkmanname, LName);
	//��ǰ�׶�
	CC_SYNTHESIZE(string, Stagename, NName);
	//��ͨ��ʽ
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
