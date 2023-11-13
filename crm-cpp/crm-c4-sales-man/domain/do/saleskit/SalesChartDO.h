#pragma once

#ifndef _SALESCHARTDO_H_
#define _SALESCHARTDO_H_
#include"../DoInclude.h"

/**
* 销售榜实体类
*/
class SalesChartDO
{
	// 排名
	CC_SYNTHESIZE(uint64_t, rank_id, Rank);
	//姓名
	CC_SYNTHESIZE(string, name, Name);
	//销售金额
	CC_SYNTHESIZE(uint64_t, amount, Amount);
	//合同总数
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