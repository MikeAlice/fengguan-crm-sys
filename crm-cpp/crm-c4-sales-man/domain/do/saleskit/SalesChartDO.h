#pragma once

#ifndef _SALESCHARTDO_H_
#define _SALESCHARTDO_H_
#include"../DoInclude.h"

/**
* ���۰�ʵ����
*/
class SalesChartDO
{
	// ����
	CC_SYNTHESIZE(uint64_t, rank_id, Rank);
	//����
	CC_SYNTHESIZE(string, name, Name);
	//���۽��
	CC_SYNTHESIZE(uint64_t, amount, Amount);
	//��ͬ����
	CC_SYNTHESIZE(uint64_t, total, Total);

public:
	SalesChartDO()
	{
		rank_id = -1;
		name = "";
		amount = -1;
		total = -1;
	}
};



#endif //!_SALESCHARTDO_H_