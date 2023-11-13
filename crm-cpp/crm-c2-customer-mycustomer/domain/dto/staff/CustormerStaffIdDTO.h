//2023��10��23��
//���ߣ���Ƥ�����
//���ݣ��ͻ���Ա��ӳ��DTO
#pragma once
#ifndef _CUSTORMER_STAFF_
#define _CUSTORMER_STAFF_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CustormerStaffIdDTO : public oatpp::DTO
{
	DTO_INIT(CustormerStaffIdDTO, DTO);
	// �ͻ�����ID
	API_DTO_FIELD_DEFAULT(Int64, customer_id, ZH_WORDS_GETTER("mycustormer.info.id"));
	// Ա����Ϣ����ID
	API_DTO_FIELD_DEFAULT(Int64, staff_id, ZH_WORDS_GETTER("hrm.staff.id"));
};
#include OATPP_CODEGEN_END(DTO)
#endif