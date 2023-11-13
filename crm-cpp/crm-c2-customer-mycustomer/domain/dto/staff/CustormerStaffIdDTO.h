//2023年10月23日
//作者：狗皮电耗子
//内容：客户与员工映射DTO
#pragma once
#ifndef _CUSTORMER_STAFF_
#define _CUSTORMER_STAFF_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CustormerStaffIdDTO : public oatpp::DTO
{
	DTO_INIT(CustormerStaffIdDTO, DTO);
	// 客户主键ID
	API_DTO_FIELD_DEFAULT(Int64, customer_id, ZH_WORDS_GETTER("mycustormer.info.id"));
	// 员工信息主键ID
	API_DTO_FIELD_DEFAULT(Int64, staff_id, ZH_WORDS_GETTER("hrm.staff.id"));
};
#include OATPP_CODEGEN_END(DTO)
#endif