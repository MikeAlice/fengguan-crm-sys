#pragma once

#ifndef _NUMBERCOUNTINGDTO_H_
#define _NUMBERCOUNTINGDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* �޸�ͳ����������������
*/
class NumberCountingDTO :public oatpp::DTO
{

	DTO_INIT(NumberCountingDTO, DTO);
	//ʱ��� 
	//API_DTO_FIELD_DEFAULT(String, time_slot, ZH_WORDS_GETTER("count-num.field.time-slot"));
	//�����̻���
	API_DTO_FIELD_DEFAULT(Int32, newly_add_business_opportunity, ZH_WORDS_GETTER("count-num.field.business-opportunity"));
	//������ͬ��
	API_DTO_FIELD_DEFAULT(Int32, newly_add_contract, ZH_WORDS_GETTER("count-num.field.contract"));
	//����������¼�� 
	API_DTO_FIELD_DEFAULT(Int32, newly_add_follow_up_records, ZH_WORDS_GETTER("count-num.field.follow-up-records"));
	//������ϵ����
	API_DTO_FIELD_DEFAULT(Int32, newly_add_contact_people, ZH_WORDS_GETTER("count-num.field.contact-people"));
	//������ͬ���
	API_DTO_FIELD_DEFAULT(Int32, newly_add_contract_amount, ZH_WORDS_GETTER("count-num.field.contract-amount"));
	//�����ؿ���
	API_DTO_FIELD_DEFAULT(Int32, newly_add_collection_amount, ZH_WORDS_GETTER("count-num.field.collection-amount"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_NUMBERCOUNTINGDTO_H_

