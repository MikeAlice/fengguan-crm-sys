#pragma once
#pragma once

#ifndef _NUMBERCOUNTINGDO_H_
#define _NUMBERCOUNTINGDO_H_
#include"../DoInclude.h"

/**
* 数量统计实体类
*/
class NumberCountingDO
{
	//时间段
	//CC_SYNTHESIZE(string, time_slot, Time_slot);
	//新增商机数
	CC_SYNTHESIZE(uint64_t, newly_add_business_opportunity, Newly_add_business_opportunity);
	//新增合同数
	CC_SYNTHESIZE(uint64_t, newly_add_contract, Newly_add_contract);
	//新增跟进记录数
	CC_SYNTHESIZE(uint64_t, newly_add_follow_up_records, Newly_add_follow_up_records);
	//新增联系人数
	CC_SYNTHESIZE(uint64_t, newly_add_contact_people, Newly_add_contact_people);
	//新增合同金额
	CC_SYNTHESIZE(uint64_t, newly_add_contract_amount, Newly_add_contract_amount);
	//新增回款金额
	CC_SYNTHESIZE(uint64_t, newly_add_collection_amount, Newly_add_collection_amount);

public:
	NumberCountingDO()
	{
		//time_slot = "";
		newly_add_business_opportunity = 0;
		newly_add_contract = 0;
		newly_add_follow_up_records = 0;
		newly_add_contact_people = 0;
		newly_add_contract_amount = 0;
		newly_add_collection_amount = 0;
	}
};

#endif //!_NUMBERCOUNTINGDO_H_
