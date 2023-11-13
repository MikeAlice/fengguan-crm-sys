#pragma once
#ifndef _FeeIncome_DO_
#define _FeeIncome_DO_
#include "../DoInclude.h"

/**
 * ���������������ݿ�ʵ����
 */
class FeeIncomeDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ��������
	CC_SYNTHESIZE(string, name, Name);
	// ����ID
	CC_SYNTHESIZE(uint64_t, parentid, Parentid);
	// ��λ���
	CC_SYNTHESIZE(int, sort, Sort);
	// �Ƿ�����
	CC_SYNTHESIZE(int, visible, Visible);
	//���
	CC_SYNTHESIZE(string, intro, Intro);
	
public:
	FeeIncomeDO() {
		id = 0;
		name = "";
		parentid = 0;
		sort = 0;
		visible = 1;
		intro = "";
	}
};

#endif // !_SAMPLE_DO_