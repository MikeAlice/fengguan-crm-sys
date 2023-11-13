#pragma once
#ifndef _OPPORTUNITYQUERY_H_
#define _OPPORTUNITYQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "ApiHelper.h"


#include OATPP_CODEGEN_BEGIN(DTO)


//����һ����ѯ���ۻ�������ݴ���ģ��
class OpportunityQuery : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(OpportunityQuery, DTO);
	//���ۻ���id  Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(Int64, chance_id, ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"));
};

#include OATPP_CODEGEN_END(DTO)

#endif