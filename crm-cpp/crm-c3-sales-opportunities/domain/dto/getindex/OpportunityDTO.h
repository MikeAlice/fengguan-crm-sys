#pragma once
#ifndef _OPPORTUNITYNAMEDTO_H_
#define _OPPORTUNITYNAMEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//�������ۻ������
class OpportunityDTO : public oatpp::DTO
{
	DTO_INIT(OpportunityDTO, DTO);

	//���ۻ�����  Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(Int64, chance_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"));
	//�ͻ�ID
	API_DTO_FIELD_DEFAULT(Int64, customer_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.customer_id"));
	//��ϵ��ID
	API_DTO_FIELD_DEFAULT(String, linkman_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.linkman_id"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, find_date, ZH_WORDS_GETTER("opportunities.field.cst_chance.find_date"));
	//Ԥ��ǩ��ʱ��
	API_DTO_FIELD_DEFAULT(String, bill_date, ZH_WORDS_GETTER("opportunities.field.cst_chance.bill_date"));
	//̸��״̬
	API_DTO_FIELD_DEFAULT(String, salestage, ZH_WORDS_GETTER("opportunities.field.cst_chance.salestage"));
	//Ԥ�ƽ��
	API_DTO_FIELD_DEFAULT(Float32, money, ZH_WORDS_GETTER("opportunities.field.cst_chance.money"));
	//Ԥ�ƿ��ܳɹ���
	API_DTO_FIELD_DEFAULT(Int64, success_rate, ZH_WORDS_GETTER("opportunities.field.cst_chance.success_rate"));
	//�û�ID
	API_DTO_FIELD_DEFAULT(Int64, userID, ZH_WORDS_GETTER("opportunities.field.cst_chance.userID"));
};

//����һ�����ۻ����ҳ�������
class OpportunityPageDTO : public PageDTO<OpportunityDTO::Wrapper>
{
	DTO_INIT(OpportunityPageDTO, PageDTO<OpportunityDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OPPORTUNITYNAMEDTO
