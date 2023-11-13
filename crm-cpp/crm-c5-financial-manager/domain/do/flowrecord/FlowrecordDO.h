#pragma once

#ifndef FLOWRECORDDO_H__
#define FLOWRECORDDO_H__
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class FlowrecordDO
{
	CC_SYNTHESIZE(string, bank_id, Bankid);
	CC_SYNTHESIZE(double, income, Income);
	CC_SYNTHESIZE(double, expenditure, Expenditure);
	CC_SYNTHESIZE(double, surplus, Surplus);
	CC_SYNTHESIZE(string, type, Type);
	CC_SYNTHESIZE(string, connect_id, Connectid);
	CC_SYNTHESIZE(string, create_user, Createuser);
	CC_SYNTHESIZE(string, create_time, Createtime);
	/*CC_SYNTHESIZE(int64_t, total_income, Totalincome);
	CC_SYNTHESIZE(int64_t, total_expenditure, Totalexpenditure);*/
public:
	FlowrecordDO() {
		bank_id = "101010";
	}
};

#endif // !_SAMPLE_DO_
