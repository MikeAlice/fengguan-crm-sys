#pragma once

#ifndef _NUMBERCOUNTINGDTO_H_
#define _NUMBERCOUNTINGDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 修改统计数量对象传输数据
*/
class NumberCountingDTO :public oatpp::DTO
{

	DTO_INIT(NumberCountingDTO, DTO);
	//时间段 
	//API_DTO_FIELD_DEFAULT(String, time_slot, ZH_WORDS_GETTER("count-num.field.time-slot"));
	//新增商机数
	API_DTO_FIELD_DEFAULT(Int32, newly_add_business_opportunity, ZH_WORDS_GETTER("count-num.field.business-opportunity"));
	//新增合同数
	API_DTO_FIELD_DEFAULT(Int32, newly_add_contract, ZH_WORDS_GETTER("count-num.field.contract"));
	//新增跟进记录数 
	API_DTO_FIELD_DEFAULT(Int32, newly_add_follow_up_records, ZH_WORDS_GETTER("count-num.field.follow-up-records"));
	//新增联系人数
	API_DTO_FIELD_DEFAULT(Int32, newly_add_contact_people, ZH_WORDS_GETTER("count-num.field.contact-people"));
	//新增合同金额
	API_DTO_FIELD_DEFAULT(Int32, newly_add_contract_amount, ZH_WORDS_GETTER("count-num.field.contract-amount"));
	//新增回款金额
	API_DTO_FIELD_DEFAULT(Int32, newly_add_collection_amount, ZH_WORDS_GETTER("count-num.field.collection-amount"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_NUMBERCOUNTINGDTO_H_

