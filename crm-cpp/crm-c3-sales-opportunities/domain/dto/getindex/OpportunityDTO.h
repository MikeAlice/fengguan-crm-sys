#pragma once
#ifndef _OPPORTUNITYNAMEDTO_H_
#define _OPPORTUNITYNAMEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//定义销售机会对象
class OpportunityDTO : public oatpp::DTO
{
	DTO_INIT(OpportunityDTO, DTO);

	//销售机会编号  唯一标识
	API_DTO_FIELD_DEFAULT(Int64, chance_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"));
	//客户ID
	API_DTO_FIELD_DEFAULT(Int64, customer_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id"));
	//联系人ID
	API_DTO_FIELD_DEFAULT(String, linkman_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.linkman_id"));
	//发行时间
	API_DTO_FIELD_DEFAULT(String, find_date, ZH_WORDS_GETTER("opportunities.field.cst_chance.find_date"));
	//预计签单时间
	API_DTO_FIELD_DEFAULT(String, bill_date, ZH_WORDS_GETTER("opportunities.field.cst_chance.bill_date"));
	//谈判状态
	API_DTO_FIELD_DEFAULT(String, salestage, ZH_WORDS_GETTER("opportunities.field.cst_chance.salestage"));
	//预计金额
	API_DTO_FIELD_DEFAULT(Float32, money, ZH_WORDS_GETTER("opportunities.field.cst_chance.money"));
	//预计可能成功率
	API_DTO_FIELD_DEFAULT(Int64, success_rate, ZH_WORDS_GETTER("opportunities.field.cst_chance.success_rate"));
	//用户ID
	API_DTO_FIELD_DEFAULT(Int64, userID, ZH_WORDS_GETTER("opportunities.field.cst_chance.userID"));
};

//定义一个销售机会分页传输对象
class OpportunityPageDTO : public PageDTO<OpportunityDTO::Wrapper>
{
	DTO_INIT(OpportunityPageDTO, PageDTO<OpportunityDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OPPORTUNITYNAMEDTO
