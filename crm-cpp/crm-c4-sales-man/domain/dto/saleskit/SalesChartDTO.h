#pragma once

#ifndef _SALESCHARTDTO_H_
#define _SALESCHARTDTO_H_

#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* �޸����۰����������
*/
class SalesChartDTO :public oatpp::DTO
{
	DTO_INIT(SalesChartDTO, DTO);
	// ����
	API_DTO_FIELD_DEFAULT(Int32, rank_id, ZH_WORDS_GETTER("sales-chart.field.rank"));
	// ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("sales-chart.field.name"));
	// ���۽��
	API_DTO_FIELD_DEFAULT(Int32, amount, ZH_WORDS_GETTER("sales-chart.field.amount"));
	// ��ͬ����
	API_DTO_FIELD_DEFAULT(Int32, total, ZH_WORDS_GETTER("sales-chart.field.total"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SALESCHARTDTO_H_

