#pragma once
#pragma once

#ifndef _NUMBERCOUNTINGDO_H_
#define _NUMBERCOUNTINGDO_H_
#include"../DoInclude.h"

/**
* ����ͳ��ʵ����
*/
class NumberCountingDO
{
	//ʱ���
	//CC_SYNTHESIZE(string, time_slot, Time_slot);
	//�����̻���
	CC_SYNTHESIZE(uint64_t, newly_add_business_opportunity, Newly_add_business_opportunity);
	//������ͬ��
	CC_SYNTHESIZE(uint64_t, newly_add_contract, Newly_add_contract);
	//����������¼��
	CC_SYNTHESIZE(uint64_t, newly_add_follow_up_records, Newly_add_follow_up_records);
	//������ϵ����
	CC_SYNTHESIZE(uint64_t, newly_add_contact_people, Newly_add_contact_people);
	//������ͬ���
	CC_SYNTHESIZE(uint64_t, newly_add_contract_amount, Newly_add_contract_amount);
	//�����ؿ���
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
